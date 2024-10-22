# Copyright 2024 NXP
# NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
# accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
# activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
# comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
# terms, then you may not retain, install, activate or otherwise use the software.

import SDL
import utime as time
import usys as sys
import lvgl as lv
import lodepng as png
import ustruct
import fs_driver

lv.init()
SDL.init(w=240,h=536)

# Register SDL display driver.
disp_buf1 = lv.disp_draw_buf_t()
buf1_1 = bytearray(240*536*4)
disp_buf1.init(buf1_1, None, len(buf1_1)//4)
disp_drv = lv.disp_drv_t()
disp_drv.init()
disp_drv.draw_buf = disp_buf1
disp_drv.flush_cb = SDL.monitor_flush
disp_drv.hor_res = 240
disp_drv.ver_res = 536
disp_drv.register()

# Regsiter SDL mouse driver
indev_drv = lv.indev_drv_t()
indev_drv.init()
indev_drv.type = lv.INDEV_TYPE.POINTER
indev_drv.read_cb = SDL.mouse_read
indev_drv.register()

fs_drv = lv.fs_drv_t()
fs_driver.fs_register(fs_drv, 'Z')

# Below: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

COLOR_SIZE = lv.color_t.__SIZE__
COLOR_IS_SWAPPED = hasattr(lv.color_t().ch,'green_h')

class lodepng_error(RuntimeError):
    def __init__(self, err):
        if type(err) is int:
            super().__init__(png.error_text(err))
        else:
            super().__init__(err)

# Parse PNG file header
# Taken from https://github.com/shibukawa/imagesize_py/blob/ffef30c1a4715c5acf90e8945ceb77f4a2ed2d45/imagesize.py#L63-L85

def get_png_info(decoder, src, header):
    # Only handle variable image types

    if lv.img.src_get_type(src) != lv.img.SRC.VARIABLE:
        return lv.RES.INV

    data = lv.img_dsc_t.__cast__(src).data
    if data == None:
        return lv.RES.INV

    png_header = bytes(data.__dereference__(24))

    if png_header.startswith(b'\211PNG\r\n\032\n'):
        if png_header[12:16] == b'IHDR':
            start = 16
        # Maybe this is for an older PNG version.
        else:
            start = 8
        try:
            width, height = ustruct.unpack(">LL", png_header[start:start+8])
        except ustruct.error:
            return lv.RES.INV
    else:
        return lv.RES.INV

    header.always_zero = 0
    header.w = width
    header.h = height
    header.cf = lv.img.CF.TRUE_COLOR_ALPHA

    return lv.RES.OK

def convert_rgba8888_to_bgra8888(img_view):
    for i in range(0, len(img_view), lv.color_t.__SIZE__):
        ch = lv.color_t.__cast__(img_view[i:i]).ch
        ch.red, ch.blue = ch.blue, ch.red

# Read and parse PNG file

def open_png(decoder, dsc):
    img_dsc = lv.img_dsc_t.__cast__(dsc.src)
    png_data = img_dsc.data
    png_size = img_dsc.data_size
    png_decoded = png.C_Pointer()
    png_width = png.C_Pointer()
    png_height = png.C_Pointer()
    error = png.decode32(png_decoded, png_width, png_height, png_data, png_size)
    if error:
        raise lodepng_error(error)
    img_size = png_width.int_val * png_height.int_val * 4
    img_data = png_decoded.ptr_val
    img_view = img_data.__dereference__(img_size)

    if COLOR_SIZE == 4:
        convert_rgba8888_to_bgra8888(img_view)
    else:
        raise lodepng_error("Error: Color mode not supported yet!")

    dsc.img_data = img_data
    return lv.RES.OK

# Above: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

decoder = lv.img.decoder_create()
decoder.info_cb = get_png_info
decoder.open_cb = open_png

def anim_x_cb(obj, v):
    obj.set_x(v)

def anim_y_cb(obj, v):
    obj.set_y(v)

def anim_width_cb(obj, v):
    obj.set_width(v)

def anim_height_cb(obj, v):
    obj.set_height(v)

def anim_img_zoom_cb(obj, v):
    obj.set_zoom(v)

def anim_img_rotate_cb(obj, v):
    obj.set_angle(v)

global_font_cache = {}
def test_font(font_family, font_size):
    global global_font_cache
    if font_family + str(font_size) in global_font_cache:
        return global_font_cache[font_family + str(font_size)]
    if font_size % 2:
        candidates = [
            (font_family, font_size),
            (font_family, font_size-font_size%2),
            (font_family, font_size+font_size%2),
            ("montserrat", font_size-font_size%2),
            ("montserrat", font_size+font_size%2),
            ("montserrat", 16)
        ]
    else:
        candidates = [
            (font_family, font_size),
            ("montserrat", font_size),
            ("montserrat", 16)
        ]
    for (family, size) in candidates:
        try:
            if eval(f'lv.font_{family}_{size}'):
                global_font_cache[font_family + str(font_size)] = eval(f'lv.font_{family}_{size}')
                if family != font_family or size != font_size:
                    print(f'WARNING: lv.font_{family}_{size} is used!')
                return eval(f'lv.font_{family}_{size}')
        except AttributeError:
            try:
                load_font = lv.font_load(f"Z:MicroPython/lv_font_{family}_{size}.fnt")
                global_font_cache[font_family + str(font_size)] = load_font
                return load_font
            except:
                if family == font_family and size == font_size:
                    print(f'WARNING: lv.font_{family}_{size} is NOT supported!')

global_image_cache = {}
def load_image(file):
    global global_image_cache
    if file in global_image_cache:
        return global_image_cache[file]
    try:
        with open(file,'rb') as f:
            data = f.read()
    except:
        print(f'Could not open {file}')
        sys.exit()

    img = lv.img_dsc_t({
        'data_size': len(data),
        'data': data
    })
    global_image_cache[file] = img
    return img

def calendar_event_handler(e,obj):
    code = e.get_code()

    if code == lv.EVENT.VALUE_CHANGED:
        source = e.get_current_target()
        date = lv.calendar_date_t()
        if source.get_pressed_date(date) == lv.RES.OK:
            source.set_highlighted_dates([date], 1)

def spinbox_increment_event_cb(e, obj):
    code = e.get_code()
    if code == lv.EVENT.SHORT_CLICKED or code == lv.EVENT.LONG_PRESSED_REPEAT:
        obj.increment()
def spinbox_decrement_event_cb(e, obj):
    code = e.get_code()
    if code == lv.EVENT.SHORT_CLICKED or code == lv.EVENT.LONG_PRESSED_REPEAT:
        obj.decrement()

def digital_clock_cb(timer, obj, current_time, show_second, use_ampm):
    hour = int(current_time[0])
    minute = int(current_time[1])
    second = int(current_time[2])
    ampm = current_time[3]
    second = second + 1
    if second == 60:
        second = 0
        minute = minute + 1
        if minute == 60:
            minute = 0
            hour = hour + 1
            if use_ampm:
                if hour == 12:
                    if ampm == 'AM':
                        ampm = 'PM'
                    elif ampm == 'PM':
                        ampm = 'AM'
                if hour > 12:
                    hour = hour % 12
    hour = hour % 24
    if use_ampm:
        if show_second:
            obj.set_text("%d:%02d:%02d %s" %(hour, minute, second, ampm))
        else:
            obj.set_text("%d:%02d %s" %(hour, minute, ampm))
    else:
        if show_second:
            obj.set_text("%d:%02d:%02d" %(hour, minute, second))
        else:
            obj.set_text("%d:%02d" %(hour, minute))
    current_time[0] = hour
    current_time[1] = minute
    current_time[2] = second
    current_time[3] = ampm

def analog_clock_cb(timer, obj):
    datetime = time.localtime()
    hour = datetime[3]
    if hour >= 12: hour = hour - 12
    obj.set_time(hour, datetime[4], datetime[5])

def datetext_event_handler(e, obj):
    code = e.get_code()
    target = e.get_target()
    if code == lv.EVENT.FOCUSED:
        if obj is None:
            bg = lv.layer_top()
            bg.add_flag(lv.obj.FLAG.CLICKABLE)
            obj = lv.calendar(bg)
            scr = target.get_screen()
            scr_height = scr.get_height()
            scr_width = scr.get_width()
            obj.set_size(int(scr_width * 0.8), int(scr_height * 0.8))
            datestring = target.get_text()
            year = int(datestring.split('/')[0])
            month = int(datestring.split('/')[1])
            day = int(datestring.split('/')[2])
            obj.set_showed_date(year, month)
            highlighted_days=[lv.calendar_date_t({'year':year, 'month':month, 'day':day})]
            obj.set_highlighted_dates(highlighted_days, 1)
            obj.align(lv.ALIGN.CENTER, 0, 0)
            lv.calendar_header_arrow(obj)
            obj.add_event_cb(lambda e: datetext_calendar_event_handler(e, target), lv.EVENT.ALL, None)
            scr.update_layout()

def datetext_calendar_event_handler(e, obj):
    code = e.get_code()
    target = e.get_current_target()
    if code == lv.EVENT.VALUE_CHANGED:
        date = lv.calendar_date_t()
        if target.get_pressed_date(date) == lv.RES.OK:
            obj.set_text(f"{date.year}/{date.month}/{date.day}")
            bg = lv.layer_top()
            bg.clear_flag(lv.obj.FLAG.CLICKABLE)
            bg.set_style_bg_opa(lv.OPA.TRANSP, 0)
            target.delete()

# Create screen
screen = lv.obj()
screen.set_size(240, 536)
screen.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for screen, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_cont_1
screen_cont_1 = lv.obj(screen)
screen_cont_1.set_pos(0, 0)
screen_cont_1.set_size(240, 536)
screen_cont_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for screen_cont_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_cont_1.set_style_border_width(2, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_cont_1.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_cont_1.set_style_border_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_cont_1.set_style_border_side(lv.BORDER_SIDE.FULL, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_cont_1.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_cont_1.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_cont_1.set_style_bg_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_cont_1.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_cont_1.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_cont_1.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_cont_1.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_cont_1.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_cont_1.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_menu_1
screen_menu_1 = lv.menu(screen)
screen_menu_1_sidebar_page = lv.menu_page(screen_menu_1, "menu")
screen_menu_1.set_sidebar_page(screen_menu_1_sidebar_page)
screen_menu_1_sidebar_page.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_menu_1_subpage_0 = lv.menu_page(screen_menu_1, None)
screen_menu_1_subpage_0.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_menu_1_cont_0 = lv.menu_cont(screen_menu_1_sidebar_page)
screen_menu_1_label_0 = lv.label(screen_menu_1_cont_0)
screen_menu_1_label_0.set_text("item")
screen_menu_1_label_0.set_size(lv.pct(100), lv.SIZE.CONTENT)
screen_menu_1.set_load_page_event(screen_menu_1_cont_0, screen_menu_1_subpage_0)
lv.event_send(screen_menu_1_cont_0, lv.EVENT.CLICKED, None);screen_menu_1_subpage_1 = lv.menu_page(screen_menu_1, None)
screen_menu_1_subpage_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_menu_1_cont_1 = lv.menu_cont(screen_menu_1_sidebar_page)
screen_menu_1_label_1 = lv.label(screen_menu_1_cont_1)
screen_menu_1_label_1.set_text("item")
screen_menu_1_label_1.set_size(lv.pct(100), lv.SIZE.CONTENT)
screen_menu_1.set_load_page_event(screen_menu_1_cont_1, screen_menu_1_subpage_1)
screen_menu_1_subpage_2 = lv.menu_page(screen_menu_1, None)
screen_menu_1_subpage_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_menu_1_cont_2 = lv.menu_cont(screen_menu_1_sidebar_page)
screen_menu_1_label_2 = lv.label(screen_menu_1_cont_2)
screen_menu_1_label_2.set_text("item")
screen_menu_1_label_2.set_size(lv.pct(100), lv.SIZE.CONTENT)
screen_menu_1.set_load_page_event(screen_menu_1_cont_2, screen_menu_1_subpage_2)
screen_menu_1.set_pos(0, 137)
screen_menu_1.set_size(231, 209)
screen_menu_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for screen_menu_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_menu_1.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_menu_1.set_style_bg_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_menu_1.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_menu_1.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_menu_1.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Set style for screen_menu_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
style_screen_menu_1_extra_sidebar_page_main_default = lv.style_t()
style_screen_menu_1_extra_sidebar_page_main_default.init()
style_screen_menu_1_extra_sidebar_page_main_default.set_bg_opa(255)
style_screen_menu_1_extra_sidebar_page_main_default.set_bg_color(lv.color_hex(0xdaf2f8))
style_screen_menu_1_extra_sidebar_page_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_menu_1_extra_sidebar_page_main_default.set_radius(0)
screen_menu_1_sidebar_page.add_style(style_screen_menu_1_extra_sidebar_page_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)
# Set style for screen_menu_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
style_screen_menu_1_extra_option_btns_main_default = lv.style_t()
style_screen_menu_1_extra_option_btns_main_default.init()
style_screen_menu_1_extra_option_btns_main_default.set_text_color(lv.color_hex(0x151212))
style_screen_menu_1_extra_option_btns_main_default.set_text_font(test_font("montserratMedium", 12))
style_screen_menu_1_extra_option_btns_main_default.set_text_opa(255)
style_screen_menu_1_extra_option_btns_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_menu_1_extra_option_btns_main_default.set_pad_top(10)
style_screen_menu_1_extra_option_btns_main_default.set_pad_bottom(10)
screen_menu_1_cont_0.add_style(style_screen_menu_1_extra_option_btns_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_menu_1_cont_1.add_style(style_screen_menu_1_extra_option_btns_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_menu_1_cont_2.add_style(style_screen_menu_1_extra_option_btns_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)
# Set style for screen_menu_1, Part: lv.PART.MAIN, State: lv.STATE.CHECKED.
style_screen_menu_1_extra_option_btns_main_checked = lv.style_t()
style_screen_menu_1_extra_option_btns_main_checked.init()
style_screen_menu_1_extra_option_btns_main_checked.set_text_color(lv.color_hex(0x9ab700))
style_screen_menu_1_extra_option_btns_main_checked.set_text_font(test_font("montserratMedium", 12))
style_screen_menu_1_extra_option_btns_main_checked.set_text_opa(255)
style_screen_menu_1_extra_option_btns_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_menu_1_extra_option_btns_main_checked.set_border_width(0)
style_screen_menu_1_extra_option_btns_main_checked.set_radius(0)
style_screen_menu_1_extra_option_btns_main_checked.set_bg_opa(60)
style_screen_menu_1_extra_option_btns_main_checked.set_bg_color(lv.color_hex(0x00e0b8))
style_screen_menu_1_extra_option_btns_main_checked.set_bg_grad_dir(lv.GRAD_DIR.NONE)
screen_menu_1_cont_0.add_style(style_screen_menu_1_extra_option_btns_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)
screen_menu_1_cont_1.add_style(style_screen_menu_1_extra_option_btns_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)
screen_menu_1_cont_2.add_style(style_screen_menu_1_extra_option_btns_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)
# Set style for screen_menu_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
style_screen_menu_1_extra_main_title_main_default = lv.style_t()
style_screen_menu_1_extra_main_title_main_default.init()
style_screen_menu_1_extra_main_title_main_default.set_text_color(lv.color_hex(0x41485a))
style_screen_menu_1_extra_main_title_main_default.set_text_font(test_font("montserratMedium", 12))
style_screen_menu_1_extra_main_title_main_default.set_text_opa(255)
style_screen_menu_1_extra_main_title_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_menu_1_extra_main_title_main_default.set_bg_opa(255)
style_screen_menu_1_extra_main_title_main_default.set_bg_color(lv.color_hex(0xffffff))
style_screen_menu_1_extra_main_title_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_menu_1_extra_main_title_main_default.set_pad_top(0)
style_screen_menu_1_extra_main_title_main_default.set_pad_bottom(0)
screen_menu_1_title = screen_menu_1.get_child(0)
screen_menu_1_title.set_size(lv.pct(100), lv.SIZE.CONTENT)
screen_menu_1.get_sidebar_header().add_style(style_screen_menu_1_extra_main_title_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen.update_layout()
# Create screen_1
screen_1 = lv.obj()
screen_1.set_size(240, 536)
screen_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for screen_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_1.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_1_cont_1
screen_1_cont_1 = lv.obj(screen_1)
screen_1_cont_1.set_pos(0, 0)
screen_1_cont_1.set_size(240, 536)
screen_1_cont_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for screen_1_cont_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_1_cont_1.set_style_border_width(2, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_cont_1.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_cont_1.set_style_border_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_cont_1.set_style_border_side(lv.BORDER_SIDE.FULL, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_cont_1.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_cont_1.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_cont_1.set_style_bg_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_cont_1.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_cont_1.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_cont_1.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_cont_1.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_cont_1.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_cont_1.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_1.update_layout()

def screen_event_handler(e):
    code = e.get_code()
    indev = lv.indev_get_act()
    gestureDir = lv.DIR.NONE
    if indev is not None: gestureDir = indev.get_gesture_dir()
    if (code == lv.EVENT.GESTURE and lv.DIR.LEFT == gestureDir):
        if indev is not None: indev.wait_release()
        pass
        lv.scr_load_anim(screen_1, lv.SCR_LOAD_ANIM.FADE_ON, 200, 200, False)
screen.add_event_cb(lambda e: screen_event_handler(e), lv.EVENT.ALL, None)

# content from custom.py

# Load the default screen
lv.scr_load(screen)

while SDL.check():
    time.sleep_ms(5)


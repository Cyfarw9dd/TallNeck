idf_component_register(
    SRCS
        "generated/gui_guider.c"
        "generated/events_init.c"
        "generated/setup_scr_scrCopy.c"
        "generated/setup_scr_scrCopy2.c"
        "generated/setup_scr_scrHome.c"
        "generated/setup_scr_scrLoader.c"
        "generated/setup_scr_scrPrintFini.c"
        "generated/setup_scr_scrPrintInternet.c"
        "generated/setup_scr_scrPrintMenu.c"
        "generated/setup_scr_scrPrintMobile.c"
        "generated/setup_scr_scrPrintUSB.c"
        "generated/setup_scr_scrScan.c"
        "generated/setup_scr_scrScanFini.c"
        "generated/setup_scr_scrSetup.c"
        "generated/widgets_init.c"
        "custom/custom.c"
    INCLUDE_DIRS
        "."
        "generated"
        "custom"
    REQUIRES
        lvgl
)

# 添加图像源文件
file(GLOB IMAGE_SOURCES "generated/images/*.c")
target_sources(${COMPONENT_LIB} PRIVATE ${IMAGE_SOURCES})

# 添加字体源文件
file(GLOB FONT_SOURCES "generated/guider_fonts/*.c" "generated/guider_customer_fonts/*.c")
target_sources(${COMPONENT_LIB} PRIVATE ${FONT_SOURCES})
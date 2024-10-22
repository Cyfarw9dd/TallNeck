# 收集所有的 .c 文件
file(GLOB_RECURSE ALL_SOURCES 
    "generated/*.c"
    "custom/*.c"
)

# 添加 lvgl_display.c
list(APPEND ALL_SOURCES "${CMAKE_SOURCE_DIR}/main/src/lvgl_display.c")

idf_component_register(
    SRCS ${ALL_SOURCES}
    INCLUDE_DIRS
        "."
        "generated"
        "custom"
        "${CMAKE_SOURCE_DIR}/main/include"
    REQUIRES
        lvgl
        esp_lcd_sh8601
        esp_lcd_touch_ft5x06
)

# 添加图像源文件
file(GLOB IMAGE_SOURCES "generated/images/*.c")
target_sources(${COMPONENT_LIB} PRIVATE ${IMAGE_SOURCES})

# 添加字体源文件
file(GLOB FONT_SOURCES "generated/guider_fonts/*.c" "generated/guider_customer_fonts/*.c")
target_sources(${COMPONENT_LIB} PRIVATE ${FONT_SOURCES})
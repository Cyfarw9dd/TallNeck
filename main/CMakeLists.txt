idf_component_register(SRCS "src/main.c"
                            "src/tcp_server.c"
                            "src/stepper_motor_encoder.c"
                            "src/wifi_sta.c"
                    INCLUDE_DIRS "include")

include_directories(${CMAKE_SOURCE_DIR}/build/config)

set(EXTRA_COMPONENT_DIRS ${PROJECT_DIR}/../components/esp32-wifi-manager)


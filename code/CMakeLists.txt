
cmake_minimum_required(VERSION 3.13) # CMAKE (heading)
include(pico_sdk_import.cmake) # CMAKE -> PICO SDK (include)

project(speed C CXX ASM) # CMAKE ("project")
pico_sdk_init() # PICO SDK (initialization)

add_executable(speed) # CMAKE (target)

pico_generate_pio_header(speed ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}) # PICO SDK (PIO)

target_sources(speed PRIVATE speed.c bootpress.c neopixel.c data_transfer.c) # CMAKE -> C (compiler)
target_link_libraries(speed PRIVATE pico_stdlib hardware_pio) # CMAKE -> C (linker)

pico_enable_stdio_usb(speed 1) # PICO SDK (USB)
pico_enable_stdio_uart(speed 0) # PICO SDK (USB)

pico_add_extra_outputs(speed) # PICO SDK (UF2)
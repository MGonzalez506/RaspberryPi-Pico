cmake_minimum_required(VERSION 3.20)

include(pico_sdk_import.cmake)

project(WiFi_Scan C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(PICO_BOARD pico_w)

pico_sdk_init()

add_executable(WiFi_Scan
WiFi_Scan.c
        )

target_link_libraries(WiFi_Scan 
        pico_stdlib
        pico_cyw43_arch_none
        )

# Initialize the USB serial connection
pico_enable_stdio_usb(WiFi_Scan 1)
pico_enable_stdio_uart(WiFi_Scan 0)

pico_add_extra_outputs(WiFi_Scan)
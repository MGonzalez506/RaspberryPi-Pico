cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(WiegandReader)

pico_sdk_init()

add_executable(project
	WiegandReader.c
)
pico_enable_stdio_usb(project 1)

target_sources(project PRIVATE WiegandReader.c)
target_link_libraries(project PRIVATE pico_stdlib hardware_pio)

pico_add_extra_outputs(project)
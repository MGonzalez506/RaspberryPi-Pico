cmake_minimum_required(VERSION 3.13)

include($ENV{PICO_SDK_IMPORT})

project(blinking_led)

pico_sdk_init()

add_executable(project
	blinking_led.c
)

target_link_libraries(project PRIVATE pico_stdlib)
target_sources(project PRIVATE blinking_led.c)

pico_add_extra_outputs(project)
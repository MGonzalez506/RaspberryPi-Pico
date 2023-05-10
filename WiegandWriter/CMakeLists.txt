cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(WiegandWriter)

pico_sdk_init()

add_executable(project
	WiegandWriter.c
)

target_link_libraries(project PRIVATE pico_stdlib)
target_sources(project PRIVATE WiegandWriter.c)

pico_add_extra_outputs(project)
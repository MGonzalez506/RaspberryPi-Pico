# Paso 1: especificar la versión mínima de CMake requerida
cmake_minimum_required(VERSION 3.20)

# Paso 2: especificar los estándares de C y C++
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Paso 3: especificar cuál versión de RaspberryPi Pico se
# está utilizando
set(PICO_BOARD pico_w)

# Paso 4: incluir el archivo de configuración de Pico SDK
include($ENV{PICO_SDK_IMPORT})

# Paso 5: especificar el nombre del proyecto y los lenguajes
project(WiFi_Scan C CXX ASM)

# Paso 6: inicializar el SDK de Pico
pico_sdk_init()

# Paso 7: agregar el ejecutable del proyecto
add_executable(WiFi_Scan
                WiFi_Scan.c
        )

# Paso 8: especificar las librerías requeridas
target_link_libraries(WiFi_Scan 
                        pico_stdlib
                        pico_cyw43_arch_none
                )

# Initialize the USB serial connection
pico_enable_stdio_usb(WiFi_Scan 1)
pico_enable_stdio_uart(WiFi_Scan 0)

pico_add_extra_outputs(WiFi_Scan)
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
project(picow_ntp_client C CXX ASM)

# Paso 6: inicializar el SDK de Pico
pico_sdk_init()

# Paso 7: agregar el ejecutable del proyecto
add_executable(picow_ntp_client_background
        picow_ntp_client.c
        )

# Paso 8: especificar las librerías requeridas

# --- Cargar las variables de ambiente requeridas ---
target_compile_definitions(picow_ntp_client_background PRIVATE
        WIFI_SSID=\"$ENV{WIFI_SSID}\"
        WIFI_PASSWORD=\"$ENV{WIFI_PASSWORD}\"
        )

# --- Incluir los directorios requeridos ---
target_include_directories(picow_ntp_client_background PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts
)

# --- Enlazar las librerías requeridas ---
target_link_libraries(picow_ntp_client_background
        pico_cyw43_arch_lwip_threadsafe_background
        pico_stdlib
        )

pico_add_extra_outputs(picow_ntp_client_background)

add_executable(picow_ntp_client_poll
        picow_ntp_client.c
        )
target_compile_definitions(picow_ntp_client_poll PRIVATE
        WIFI_SSID=\"$ENV{WIFI_SSID}\"
        WIFI_PASSWORD=\"$ENV{WIFI_PASSWORD}\"
        )
target_include_directories(picow_ntp_client_poll PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts
        )
target_link_libraries(picow_ntp_client_poll
        pico_cyw43_arch_lwip_poll
        pico_stdlib
        )

# Initialize the USB serial connection
pico_enable_stdio_usb(picow_ntp_client_poll 1)
pico_enable_stdio_uart(picow_ntp_client_poll 0)

pico_add_extra_outputs(picow_ntp_client_poll)

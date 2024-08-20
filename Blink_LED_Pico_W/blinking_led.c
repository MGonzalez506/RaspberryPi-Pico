#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

int main() {
    // Inicializar el subsistema CYW43
    if (cyw43_arch_init()) {
        return -1; // Error al inicializar
    }

    while (true) {
        // Encender el LED
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        sleep_ms(500); // Esperar 500 ms

        // Apagar el LED
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        sleep_ms(500); // Esperar 500 ms
    }

    // Finalizar el subsistema CYW43
    cyw43_arch_deinit();

    return 0;
}
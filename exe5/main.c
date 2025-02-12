#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int BTN_PIN = 26;
const int BTN_PIN_2 = 7;

int main() {
    stdio_init_all();

    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_pull_up(BTN_PIN);

    gpio_init(BTN_PIN_2);
    gpio_set_dir(BTN_PIN_2, GPIO_IN);
    gpio_pull_up(BTN_PIN_2);
    int cnt_1 = 0;
    int cnt_2 = 0;

    while (true) {
        if (!gpio_get(BTN_PIN)) {
            cnt_1++;
            printf("Botão 1: %d \n", cnt_1);
            sleep_ms(300);
        }

        if (!gpio_get(BTN_PIN_2)) {
            cnt_2++;
            printf("Botão 2: %d \n", cnt_2);
            sleep_ms(300);
        }
    }
}

#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_PIN_R = 4;
const int LED_PIN_G = 6;
const int BTN_PIN_R = 28;
const int BTN_PIN_G = 26;

int main() {
  stdio_init_all();

  gpio_init(LED_PIN_R);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);

  gpio_init(LED_PIN_G);
  gpio_set_dir(LED_PIN_G, GPIO_OUT);

  gpio_init(BTN_PIN_R);
  gpio_set_dir(BTN_PIN_R, GPIO_IN);

  gpio_init(BTN_PIN_G);
  gpio_set_dir(BTN_PIN_G, GPIO_IN);

  gpio_pull_up(BTN_PIN_R);
  gpio_pull_up(BTN_PIN_G);

  while (true) {
    if (!gpio_get(BTN_PIN_R)) {
      if (gpio_get(LED_PIN_R)) {
        gpio_put(LED_PIN_R, 0);
      } else {
        gpio_put(LED_PIN_R, 1);
      }
    }

    if (!gpio_get(BTN_PIN_G)) {
      if (gpio_get(LED_PIN_G)) {
        gpio_put(LED_PIN_G, 0);
      } else {
        gpio_put(LED_PIN_G, 1);
      }
    }
  }
}

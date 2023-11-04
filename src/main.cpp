#include <stdio.h>
#include "pico/cyw43_arch.h"
#include "pico/stdlib.h"
#include "controller/bt_controller.h"


void init_button_click() {
    Controller::Bluetooth bt;
    bt.InitBluetoothController();

    while(1) {
        printf("Command (1 = on || 0 = off)\n");
        char userInput = getchar(); 

        if(userInput == '1') {
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
            printf("LED switch on.\n");
        } else if(userInput == '0') {
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
            printf("LED switched off.\n");
        } else {
            printf("Unknown status.\n");
        }
    }
}

int main() {
    setup_default_uart();
    stdio_init_all();
    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed!\n");
        return -1;
    }
    
    init_button_click();

    return 0;
}
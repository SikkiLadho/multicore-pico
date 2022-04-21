#include "pico/stdlib.h"
#include "pico/multicore.h"
#define GPIO_ON 1
#define GPIO_OFF 0

#define LED_PIN 25

void second_core_code()
{
    while(1)
    {
        sleep(500)
        multicore_fifo_push_blocking(GPIO_ON)
        sleep(500)
        multicore_fifo_push_blocking(GPIO_OFF)
    }
}


int main()
{
    multicore_launch_core1(second_core_code); 

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while(true) {
        gpio_put(LED_PIN, GPIO_ON);
        sleep_ms(20000);
        gpio_put(LED_PIN, GPIO_OFF);
        sleep_ms(20000);
    }
}
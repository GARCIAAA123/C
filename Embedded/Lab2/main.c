#include <stdio.h>
#include <stdbool.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/timer.h"
#include "hardware/gpio.h"

const int button0 = 12;
const int rot_a = 10;
const int rot_b = 11;
const int led0 = 22;
const int led1 = 21;
const int led2 = 20;


void create_led(uint led);
void adjust_bright(uint led, int bright);

bool led_state = false;
int brightness = 500;

static void a_interrupt_handler(uint gpio, uint32_t event) {
    if(gpio == rot_a && gpio_get(rot_b)){

        brightness -= 100;
        if (brightness <= 0) {
            brightness = 0;
        }
    }else{

        brightness += 100;
        if (brightness >= 1000) {
            brightness = 1000;
        }
    }
}
int main() {

    create_led(led0);
    create_led(led1);
    create_led(led2);

    gpio_init(rot_a);
    gpio_init(rot_b);
    gpio_init(button0);

    gpio_set_dir(rot_a, GPIO_IN);
    gpio_set_dir(rot_b, GPIO_IN);
    gpio_set_dir(button0, GPIO_IN);
    gpio_set_pulls(button0, true, false);

    gpio_set_irq_enabled_with_callback(rot_a, GPIO_IRQ_EDGE_RISE, true, &a_interrupt_handler);

    stdio_init_all();

    while (1) {

        if (gpio_get(button0) == 0) {
            while (gpio_get(button0) == 0) {
                tight_loop_contents();
            }
            led_state = !led_state;
            if (led_state) {
                adjust_bright(led0,brightness);
                adjust_bright(led1, brightness);
                adjust_bright(led2, brightness);
                printf("ON");
            } else if(brightness == 0) {
                brightness = 500;
                pwm_set_gpio_level(led0, brightness);
                pwm_set_gpio_level(led1, brightness);
                pwm_set_gpio_level(led2, brightness);
                led_state = true;
                printf("Button 0 = %d\n", (int) brightness);
            }else {
                adjust_bright(led0,0);
                adjust_bright(led1, 0);
                adjust_bright(led2, 0);
                printf("OFF");
            }
            sleep_ms(10);
        }
        if (led_state) {
            adjust_bright(led0,brightness);
            adjust_bright(led1, brightness);
            adjust_bright(led2, brightness);
            printf("LED brightness: %d\n", brightness);
        }
    }
}
void create_led(uint led){
    uint period, freq;
    period = 1000;
    freq = 125;
    uint slice_num = pwm_gpio_to_slice_num(led);
    pwm_config config_led = pwm_get_default_config();
    pwm_config_set_clkdiv_int(&config_led,freq);
    pwm_config_set_wrap(&config_led,period-1);
    pwm_set_enabled(slice_num, led);
    pwm_init(slice_num,&config_led,true);
    gpio_set_function(led,GPIO_FUNC_PWM);
}

void adjust_bright(uint led, int bright){
    uint slice, channel;
    slice = pwm_gpio_to_slice_num(led);
    channel = pwm_gpio_to_channel(led);
    pwm_set_chan_level(slice,channel,bright);
}
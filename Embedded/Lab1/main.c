#include "stdio.h"
#include "stdbool.h"
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/timer.h"

const int button0 = 8;
const int button1 = 9;
const int button2 = 7;
const int led = 22;
const int led1 = 21;
const int led2 = 20;

int brightness = 0;
uint slice_num0, slice_num1, slice_num2;
uint channel0, channel1, channel2;

bool is_button_pressed(int button) {
    static uint32_t last_time = 0;
    uint32_t current_time = time_us_32();
    if (gpio_get(button) == 0 && (current_time - last_time) > 500000) {
        last_time = current_time;
        return true;
    }
    return false;
}

int main() {
    stdio_init_all();

    gpio_init(button0);
    gpio_set_dir(button0, GPIO_IN);
    gpio_pull_up(button0);
    gpio_init(button1);
    gpio_set_dir(button1, GPIO_IN);
    gpio_pull_up(button1);
    gpio_init(button2);
    gpio_set_dir(button2, GPIO_IN);
    gpio_pull_up(button2);

    gpio_init(led);
    gpio_set_dir(led, GPIO_OUT);
    gpio_init(led1);
    gpio_set_dir(led1, GPIO_OUT);
    gpio_init(led2);
    gpio_set_dir(led2, GPIO_OUT);

    // Get slice and channel for all LEDs
    slice_num0 = pwm_gpio_to_slice_num(led);
    channel0 = pwm_gpio_to_channel(led);
    slice_num1 = pwm_gpio_to_slice_num(led1);
    channel1 = pwm_gpio_to_channel(led1);
    slice_num2 = pwm_gpio_to_slice_num(led2);
    channel2 = pwm_gpio_to_channel(led2);

    // Configure PWM config
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv_int(&config, 125);
    pwm_config_set_wrap(&config, 999); // Set TOP value to 1 kHz

    // Configure PWM for led
    pwm_set_enabled(slice_num0, false);
    pwm_init(slice_num0, &config, false);
    gpio_set_function(led, GPIO_FUNC_PWM);
    pwm_set_chan_level(slice_num0, channel0, brightness);
    pwm_set_enabled(slice_num0, true);

    // Configure PWM for led1
    pwm_set_enabled(slice_num1, false);
    pwm_init(slice_num1, &config, false);
    gpio_set_function(led1, GPIO_FUNC_PWM);
    pwm_set_chan_level(slice_num1, channel1, brightness);
    pwm_set_enabled(slice_num1, true);

    // Configure PWM for led2
    pwm_set_enabled(slice_num2, false);
    pwm_init(slice_num2, &config, false);
    gpio_set_function(led2, GPIO_FUNC_PWM);
    pwm_set_chan_level(slice_num2, channel2, brightness);
    pwm_set_enabled(slice_num2, true);

    double brightness = 500;

    bool isLEDOn = false;
    bool brightnessDecreased = false;
    bool brightnessIncreased = false;

    while (1) {
        if (is_button_pressed(button0)) {
            if (!isLEDOn) {
                pwm_set_gpio_level(led, brightness);
                pwm_set_gpio_level(led1, brightness);
                pwm_set_gpio_level(led2, brightness);
                isLEDOn = true;
                printf("ON = %d\n", (int) brightness);
            } else if(brightness == 0){
                brightness = 500;
                pwm_set_gpio_level(led, brightness);
                pwm_set_gpio_level(led1, brightness);
                pwm_set_gpio_level(led2, brightness);
                printf("Button 0 = %d\n",(int)brightness);
            }
            else {
                pwm_set_gpio_level(led, 0);
                pwm_set_gpio_level(led1, 0);
                pwm_set_gpio_level(led2, 0);
                isLEDOn = false;
                printf("OFF = %d\n", (int) brightness);
            }
        }
        if (is_button_pressed(button1)) {
            if (!brightnessDecreased) {
                brightness -= 100;
                if (brightness < 0) {
                    brightness = 0;
                }
                pwm_set_gpio_level(led, brightness);
                pwm_set_gpio_level(led1, brightness);
                pwm_set_gpio_level(led2, brightness);
                printf("Button 2 = %d\n", (int)brightness);
                brightnessDecreased = true;
            }
        } else {
            brightnessDecreased = false;
        }
        if (is_button_pressed(button2)) {
            if (!brightnessIncreased) {
                brightness += 100;
                if (brightness > 1000) {
                    brightness = 1000;
                }
                pwm_set_gpio_level(led, brightness);
                pwm_set_gpio_level(led1, brightness);
                pwm_set_gpio_level(led2, brightness);
                printf("Button 3 = %d\n", (int)brightness);
                brightnessIncreased = true;
            }
        } else {
            brightnessIncreased = false;
        }
    }
}

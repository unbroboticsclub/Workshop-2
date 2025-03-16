#include "motor_control.h"
#include "driver/gpio.h"

// Motor control GPIOs
#define MOTOR_FORWARD GPIO_NUM_4
#define MOTOR_BACKWARD GPIO_NUM_5
#define MOTOR_LEFT GPIO_NUM_18
#define MOTOR_RIGHT GPIO_NUM_19

void setup_motors() {
    gpio_set_direction(MOTOR_FORWARD, GPIO_MODE_OUTPUT);
    gpio_set_direction(MOTOR_BACKWARD, GPIO_MODE_OUTPUT);
    gpio_set_direction(MOTOR_LEFT, GPIO_MODE_OUTPUT);
    gpio_set_direction(MOTOR_RIGHT, GPIO_MODE_OUTPUT);
}

void move_robot(const char *direction) {
    if (strcmp(direction, "forward") == 0) {
        gpio_set_level(MOTOR_FORWARD, 1);
    } else if (strcmp(direction, "backward") == 0) {
        gpio_set_level(MOTOR_BACKWARD, 1);
    } else if (strcmp(direction, "left") == 0) {
        gpio_set_level(MOTOR_LEFT, 1);
    } else if (strcmp(direction, "right") == 0) {
        gpio_set_level(MOTOR_RIGHT, 1);
    }
}

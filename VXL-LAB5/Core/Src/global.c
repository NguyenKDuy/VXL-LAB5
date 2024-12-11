/*
 * global.c
 *
 *  Created on: Dec 10, 2024
 *      Author: My Laptop
 */
#include <global.h>

int status_command = WAIT_INIT;
int status_uart = WAIT_RST;

uint8_t cursor = 0;
uint8_t buffer_flag = 0;

uint8_t command[MAX_BUFFER_SIZE];
uint8_t command_index = 0;
uint8_t command_flag = 0;

char str[50];
uint32_t ADC_value = 0;

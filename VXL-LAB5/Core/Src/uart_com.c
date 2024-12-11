/*
 * uart_com.c
 *
 *  Created on: Dec 11, 2024
 *      Author: My Laptop
 */

#include <uart_com.h>
#include <main.h>
void uart_com_fsm(ADC_HandleTypeDef hadc1, UART_HandleTypeDef huart2) {
	switch(status_uart) {
		case WAIT_RST:
			// If command has completed and command = "RST" -> status = SEND_ADC, update ADC_Value, flag = 0 and setTimer
			if (command_flag == 1) {
				command_flag = 0;
				if (command[0] == 'R' && command[1] == 'S' && command[2] == 'T') {
					HAL_ADC_Start(&hadc1);
					ADC_value = HAL_ADC_GetValue(&hadc1);
					HAL_ADC_Stop(&hadc1);
					sprintf(str, "\r\n");
					HAL_UART_Transmit(&huart2, (void*)str, 2 , 1000);
					status_uart = SEND_ADC;
					setTimer(1, 3000);
				}
			}
			break;

		case SEND_ADC:
			// Display ADC Value console, status = WAIT_OK
			sprintf(str, "ADC=%lu\r\n",ADC_value);
			HAL_UART_Transmit(&huart2,(void*)str,11, 1000);
			status_uart = WAIT_OK;
			break;

		case WAIT_OK:
			// If command has completed and command = "OK" -> status = WAIT_RST and clearTimer
			if (command_flag == 1) {
				command_flag = 0;
				if (command[0] == 'O' && command[1] == 'K') {
					sprintf(str, "\r\n");
					HAL_UART_Transmit(&huart2, (void*)str,2, 1000);
					status_uart = WAIT_RST;
					break;
				}
			}

			if(getFlag(1)== 1) {
				status_uart = SEND_ADC;
				setTimer(1, 3000);
			}
			break;
		default:
			break;
		}
}

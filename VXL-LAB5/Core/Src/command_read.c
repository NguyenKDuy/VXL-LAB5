/*
 * command_read.c
 *
 *  Created on: Dec 10, 2024
 *      Author: My Laptop
 */

#include "command_read.h"
#include <main.h>
void command_read_fsm(){
	switch(status_command){
	case WAIT_INIT:
		if (cursor == '!') {
			command_index = 0;
			status_command = WAIT_END;
		}
		break;
	case WAIT_END:
		if (cursor == '#') {
			command[command_index] = '\0';
			command_flag = 1;
			status_command = WAIT_INIT;
		}
		else {
			if (cursor == '!') {
				command_index = 0;
			}
			else {
				command[command_index] = cursor;
				command_index++;
				if (command_index == MAX_BUFFER_SIZE) command_index = 0;
			}
		}
		break;
	default:
		break;
	}
}

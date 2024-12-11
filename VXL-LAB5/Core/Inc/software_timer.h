/*
 * software_timer.h
 *
 *  Created on: Dec 10, 2024
 *      Author: My Laptop
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define TIME_CYCLE 10
#define NUM_TIM 3

void setTimer(int index, int duration);
void timerRun();
int getFlag (int index);


#endif /* INC_SOFTWARE_TIMER_H_ */

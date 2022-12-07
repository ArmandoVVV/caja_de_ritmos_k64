/*
 * state_machine.h
 * \brief
 *		This source file contains the STATE MACHINE
 *		It is a button-sensitive state machine
 *
 *  Created on: Nov 17, 2022
 *      Author: Armando Cabrales
 */

#ifndef STATE_MACHINE_H_
#define STATE_MACHINE_H_

typedef enum{
	MENU,
	MANUAL,
	SEQUENCE_STOPPED,
	SEQUENCE_PLAYING
}state_t;

state_t get_current_state(void);
void set_current_state(state_t state);

// runs the state machine
void state_machine(void);

#endif /* STATE_MACHINE_H_ */

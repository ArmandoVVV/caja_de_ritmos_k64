/*
 * callback_manager.h
 * This source file helps with the callback management, this function
 * only works when a sound button is pressed
 *
 *  Created on: 16 nov 2022
 *      Author: Laura García
 */

#ifndef CALLBACK_MANAGER_H_
#define CALLBACK_MANAGER_H_

#include "stdint.h"

/* if current state is manual mode or sequence stopped it will
* add the pressed button sound to the buffer.
* if the state is sequence stopped it will write in the LCD the
* sound´s letter.
*/
void sound_button_pressed(uint32_t port);


#endif /* CALLBACK_MANAGER_H_ */

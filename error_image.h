/*
 * error_image.h
 * \brief
 *	This source file contains an error image array to show in the LCD
 *	screen when the watchdog activates
 *
 *  Created on: 17 nov 2022
 *      Author: Laura García
 */

#ifndef ERROR_IMAGE_H_
#define ERROR_IMAGE_H_

#include "stdint.h"

// returns the error image
const uint8_t* get_error_image(void);

#endif /* ERROR_IMAGE_H_ */

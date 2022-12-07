/*
 * S25FLXX.c
 * \brief
 *      	This source file helps with the s25flxx, it allow us to read
 *      	the external memory s25flxx
 *  Created on: Oct 31, 2022
 *      Author: armando
 */

#ifndef S25FLXX_H_
#define S25FLXX_H_

#include "stdint.h"


typedef union {
	uint32_t address;
	struct{
		uint32_t address_byte_0 :8;
		uint32_t address_byte_1 :8;
		uint32_t address_byte_2 :8;
		uint32_t address_byte_3 :8;
	}address_by_byte;
}s25flxxx_memory_address_t;

// Reads the external memory and returns the 8bit value at an specific address
uint8_t S25FLXXX_read_byte(s25flxxx_memory_address_t* address);

#endif /* S25FLXX_H_ */

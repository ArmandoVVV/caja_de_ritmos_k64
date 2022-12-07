/*
 * buffer.h
  *      	This source file helps with the creation of the BUFFER.
 *      	This BUFFER is global.
 *  Created on: Nov 17, 2022
 *      Author: armando
 */

#ifndef BUFFER_H_
#define BUFFER_H_

#include "sounds.h"

#define BUFFER_CAPACITY		20

typedef struct{
	sound_name_t buffer[BUFFER_CAPACITY];
	uint8_t total_sounds;
	uint8_t index;
}buffer_t;

sound_name_t* get_buffer(void);

uint8_t get_buffer_sounds(void);
void set_buffer_sounds(uint8_t total);

// adds a sound to the global buffer
void add_buffer(sound_name_t sound);
// returns and deletes the current sound at the buffer
sound_name_t pop_buffer(void);
// returns a specific sound at the buffer
sound_name_t get_sound_at_buffer(uint8_t index);

// deletes all sounds in the buffer
void clear_buffer(void);



#endif /* BUFFER_H_ */

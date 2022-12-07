/*
 * buffer.c
 * \brief
 *      	This source file helps with the creation of the BUFFER.
 *      	This BUFFER is global.
 *
 *  Created on: Nov 17, 2022
 *      Author: armando Cabrales
 */
#include "buffer.h"
#include "stdint.h"


buffer_t g_buffer;


uint8_t get_buffer_sounds(void){
	return g_buffer.total_sounds;
}

void set_buffer_sounds(uint8_t total){
	g_buffer.total_sounds = total;

	// if value is more than the buffer capacity
	if (BUFFER_CAPACITY < g_buffer.total_sounds){
		g_buffer.total_sounds = 20;
	}
}

sound_name_t* get_buffer(void){
	return g_buffer.buffer;
}

void add_buffer(sound_name_t sound){
	// if buffer is not full
	if(get_buffer_sounds() < BUFFER_CAPACITY){
		get_buffer()[get_buffer_sounds()] = sound;

		// updates the total sounds at buffer
		set_buffer_sounds(get_buffer_sounds() + 1);
	}
}


sound_name_t pop_buffer(void){
	sound_name_t sound = get_buffer()[0];
	static uint8_t i = 0;

	// roams the buffer
	for(i = 0; i < BUFFER_CAPACITY; i++){
		get_buffer()[i] = get_buffer()[i + 1];
	}

	// updates the total sounds at buffer
	set_buffer_sounds(get_buffer_sounds() - 1);

	return sound;
}

sound_name_t get_sound_at_buffer(uint8_t index){
	return get_buffer()[index];
}

void clear_buffer(void){
	static uint8_t i = 0;

	for(i = 0; i < BUFFER_CAPACITY; i++){
		get_buffer()[i] = SILENCE;
	}

	// updates the total sounds at buffer
	set_buffer_sounds(0);
}

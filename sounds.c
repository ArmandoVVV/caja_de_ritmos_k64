/*
 * sounds.c
 * \brief
 *			This source file helps us to set the SOUNDS values to create
 *			different signals, and start the SOUNDS.
 *  Created on: Nov 16, 2022
 *      Author: Armando Cabrales
 */

#include "sounds.h"
#include "s25flxx.h"
#include "config.h"

uint16_t g_kick_array[KICK_BYTES];
uint16_t g_snare_array[SNARE_BYTES];
uint16_t g_bongo_array[BONGO_BYTES];
uint16_t g_hithat_array[HITHAT_BYTES];
uint16_t g_guiro_array[GUIRO_BYTES];
uint16_t g_rimshot_array[RIMSHOT_BYTES];
uint16_t g_tambor_array[TAMBOR_BYTES];
uint16_t g_cynbal_array[CYNBAL_BYTES];
uint16_t g_cowbell_array[COWBELL_BYTES];

static void set_sound_values(uint16_t bytes, uint32_t address, uint16_t* sound_array);

uint16_t* get_kick_array(void){
	return  g_kick_array;
}

uint16_t* get_snare_array(void){
	return  g_snare_array;
}

uint16_t* get_bongo_array(void){
	return  g_bongo_array;
}

uint16_t* get_hithat_array(void){
	return  g_hithat_array;
}

uint16_t* get_guiro_array(void){
	return  g_guiro_array;
}

uint16_t* get_rimshot_array(void){
	return  g_rimshot_array;
}

uint16_t* get_tambor_array(void){
	return  g_tambor_array;
}

uint16_t* get_cynbal_array(void){
	return  g_cynbal_array;
}

uint16_t* get_cowbell_array(void){
	return  g_cowbell_array;
}

static void set_sound_values(uint16_t bytes, uint32_t address, uint16_t* sound_array){
	s25flxxx_memory_address_t memory = {address};
	uint32_t current_byte;

	for(current_byte = 0; current_byte < bytes; ++current_byte){
		sound_array[current_byte] = (S25FLXXX_read_byte(&memory) << 8);
		memory.address++;
		sound_array[current_byte] = sound_array[current_byte] + S25FLXXX_read_byte(&memory);
		memory.address++;
	}
}

void setup_sounds(void){
	build_sound(KICK, g_kick_array);
	build_sound(SNARE, g_snare_array);
	build_sound(BONGO, g_bongo_array);
	build_sound(HITHAT, g_hithat_array);
	build_sound(GUIRO, g_guiro_array);
	build_sound(RIMSHOT, g_rimshot_array);
	build_sound(TAMBOR, g_tambor_array);
	build_sound(CYNBAL, g_cynbal_array);
	build_sound(COWBELL, g_cowbell_array);
}

void build_sound(sound_name_t name, uint16_t* sound_array){
	switch(name){
		case KICK:
			set_sound_values(KICK_BYTES, KICK_ADDRESS, sound_array);
		break;

		case SNARE:
			set_sound_values(SNARE_BYTES, SNARE_ADDRESS, sound_array);
		break;

		case BONGO:
			set_sound_values(BONGO_BYTES, BONGO_ADDRESS, sound_array);
		break;

		case HITHAT:
			set_sound_values(HITHAT_BYTES, HITHAT_ADDRESS, sound_array);
		break;

		case GUIRO:
			set_sound_values(GUIRO_BYTES, GUIRO_ADDRESS, sound_array);
		break;

		case RIMSHOT:
			set_sound_values(RIMSHOT_BYTES, RIMSHOT_ADDRESS, sound_array);
		break;

		case TAMBOR:
			set_sound_values(TAMBOR_BYTES, TAMBOR_ADDRESS, sound_array);
		break;

		case CYNBAL:
			set_sound_values(CYNBAL_BYTES, CYNBAL_ADDRESS, sound_array);
		break;

		default:	// COWBELL
			set_sound_values(COWBELL_BYTES, COWBELL_ADDRESS, sound_array);
		break;
	}
}

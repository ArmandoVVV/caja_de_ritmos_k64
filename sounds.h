/*
 * sounds.h
 * \brief
 *			This source file helps us to set the SOUNDS values to create
 *			different signals, and start the SOUNDS.
 *  Created on: Nov 16, 2022
 *      Author: Armando Cabrales
 */

#ifndef SOUNDS_H_
#define SOUNDS_H_

#include "stdint.h"

typedef enum{
	SILENCE,
	KICK,
	SNARE,
	BONGO,
	HITHAT,
	GUIRO,
	RIMSHOT,
	TAMBOR,
	CYNBAL,
	COWBELL
}sound_name_t;

typedef struct{
	uint16_t bytes;
	uint32_t address;
	//uint16_t sound_values[10075];
}sound_t;

// sound arrays getters
uint16_t* get_kick_array(void);
uint16_t* get_snare_array(void);
uint16_t* get_bongo_array(void);
uint16_t* get_hithat_array(void);
uint16_t* get_guiro_array(void);
uint16_t* get_rimshot_array(void);
uint16_t* get_tambor_array(void);
uint16_t* get_cynbal_array(void);
uint16_t* get_cowbell_array(void);

// copies the sounds at the external memory to the RAM
void setup_sounds(void);
// paste the sound from an external memory to an array
void build_sound(sound_name_t name, uint16_t* sound_array);

#endif /* SOUNDS_H_ */

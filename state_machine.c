/*
 * state_machine.c
 * \brief
 *		This source file contains the STATE MACHINE
 *		It is a button-sensitive state machine
 *
 *  Created on: Nov 17, 2022
 *      Author: Armando Cabrales
 */

#include "state_machine.h"
#include "buffer.h"
#include "sounds.h"
#include "gpio.h"
#include "lcd_nokia.h"
#include "dma.h"
#include "pit.h"

state_t g_current_state = MENU;

//*** static functions ***//
static void menu_state(void);
static void manual_state(void);
static void sequence_stopped_state(void);
static void sequence_playing_state(void);

state_t get_current_state(void){
	return g_current_state;
}

void set_current_state(state_t state){
	g_current_state = state;
}

static void menu_state(void){
	clear_buffer();

	if(get_buttonB1_pressed_flag()){
		LCD_write_manual_mode();

		set_buttonMenu_pressed_flag(FALSE);
		set_buttonB1_pressed_flag(FALSE);
		set_buttonB2_pressed_flag(FALSE);

		set_current_state(MANUAL);
	}

	if(get_buttonB2_pressed_flag()){
		LCD_write_sequence_mode();
		LCD_nokia_goto_xy(1,2);

		set_buttonMenu_pressed_flag(FALSE);
		set_buttonB1_pressed_flag(FALSE);
		set_buttonB2_pressed_flag(FALSE);

		set_current_state(SEQUENCE_STOPPED);
	}
}

static void manual_state(void){
	static sound_name_t sound_name;
	static uint16_t* sound_array;
	static sound_t sound;

	// if there are sounds in queue
	if(get_buffer_sounds()){
		// and if the previous sound is done playing
		if(get_transfer_done()){
			set_transfer_done(FALSE);

			sound_name = pop_buffer();

			switch(sound_name){
				case KICK:
					sound.address = KICK_ADDRESS;
					sound.bytes = KICK_BYTES;
					sound_array = get_kick_array();
				break;

				case SNARE:
					sound.address = SNARE_ADDRESS;
					sound.bytes = SNARE_BYTES;
					sound_array = get_snare_array();
				break;

				case BONGO:
					sound.address = BONGO_ADDRESS;
					sound.bytes = BONGO_BYTES;
					sound_array = get_bongo_array();
				break;

				case HITHAT:
					sound.address = HITHAT_ADDRESS;
					sound.bytes = HITHAT_BYTES;
					sound_array = get_hithat_array();
				break;

				case GUIRO:
					sound.address = GUIRO_ADDRESS;
					sound.bytes = GUIRO_BYTES;
					sound_array = get_guiro_array();
				break;

				case RIMSHOT:
					sound.address = RIMSHOT_ADDRESS;
					sound.bytes = RIMSHOT_BYTES;
					sound_array = get_rimshot_array();
				break;

				case TAMBOR:
					sound.address = TAMBOR_ADDRESS;
					sound.bytes = TAMBOR_BYTES;
					sound_array = get_tambor_array();
				break;

				case CYNBAL:
					sound.address = CYNBAL_ADDRESS;
					sound.bytes = CYNBAL_BYTES;
					sound_array = get_cynbal_array();
				break;

				default: // COWBELL
					sound.address = COWBELL_ADDRESS;
					sound.bytes = COWBELL_BYTES;
					sound_array = get_cowbell_array();
				break;
			}

			setup_dma_transfer_config(sound, sound_array);
			PIT_start();
		}
	}

	if(get_buttonMenu_pressed_flag()){
		LCD_write_menu();

		set_buttonMenu_pressed_flag(FALSE);
		set_buttonB1_pressed_flag(FALSE);
		set_buttonB2_pressed_flag(FALSE);

		set_current_state(MENU);
	}
}

static void sequence_stopped_state(void){
	if(get_buttonMenu_pressed_flag()){
		LCD_write_menu();

		set_buttonMenu_pressed_flag(FALSE);
		set_buttonB1_pressed_flag(FALSE);
		set_buttonB2_pressed_flag(FALSE);

		set_current_state(MENU);
	}

	if(get_buttonB1_pressed_flag()){
		if(0 < get_buffer_sounds()){
			LCD_write_playing();
			set_current_state(SEQUENCE_PLAYING);
		}
		set_buttonMenu_pressed_flag(FALSE);
		set_buttonB1_pressed_flag(FALSE);
		set_buttonB2_pressed_flag(FALSE);
	}

}

static void sequence_playing_state(void){
	static sound_name_t sound_name;
	static uint16_t* sound_array;
	static sound_t sound;
	static uint8_t buffer_index = 0;

	if(get_buttonMenu_pressed_flag()){
		LCD_write_menu();
		buffer_index = 0;

		set_buttonMenu_pressed_flag(FALSE);
		set_buttonB1_pressed_flag(FALSE);
		set_buttonB2_pressed_flag(FALSE);

		set_current_state(MENU);
	}

	if(get_buttonB2_pressed_flag()){
		LCD_write_stopped();
		LCD_nokia_goto_xy(1,2);
		buffer_index = 0;

		set_buttonMenu_pressed_flag(FALSE);
		set_buttonB1_pressed_flag(FALSE);
		set_buttonB2_pressed_flag(FALSE);

		set_current_state(SEQUENCE_STOPPED);
	}

	if(get_transfer_done()){
				set_transfer_done(FALSE);

				sound_name = get_sound_at_buffer(buffer_index);

				if(buffer_index == get_buffer_sounds() - 1){
					buffer_index = 0;
				}
				else{
					buffer_index++;
				}

				switch(sound_name){
					case KICK:
						sound.address = KICK_ADDRESS;
						sound.bytes = KICK_BYTES;
						sound_array = get_kick_array();
					break;

					case SNARE:
						sound.address = SNARE_ADDRESS;
						sound.bytes = SNARE_BYTES;
						sound_array = get_snare_array();
					break;

					case BONGO:
						sound.address = BONGO_ADDRESS;
						sound.bytes = BONGO_BYTES;
						sound_array = get_bongo_array();
					break;

					case HITHAT:
						sound.address = HITHAT_ADDRESS;
						sound.bytes = HITHAT_BYTES;
						sound_array = get_hithat_array();
					break;

					case GUIRO:
						sound.address = GUIRO_ADDRESS;
						sound.bytes = GUIRO_BYTES;
						sound_array = get_guiro_array();
					break;

					case RIMSHOT:
						sound.address = RIMSHOT_ADDRESS;
						sound.bytes = RIMSHOT_BYTES;
						sound_array = get_rimshot_array();
					break;

					case TAMBOR:
						sound.address = TAMBOR_ADDRESS;
						sound.bytes = TAMBOR_BYTES;
						sound_array = get_tambor_array();
					break;

					case CYNBAL:
						sound.address = CYNBAL_ADDRESS;
						sound.bytes = CYNBAL_BYTES;
						sound_array = get_cynbal_array();
					break;

					case COWBELL:
						sound.address = COWBELL_ADDRESS;
						sound.bytes = COWBELL_BYTES;
						sound_array = get_cowbell_array();
					break;

					default:
						// ignore
					break;
				}

				setup_dma_transfer_config(sound, sound_array);
				PIT_start();
			}
}

void state_machine(void){
	switch(get_current_state()){
		case MENU:
			menu_state();
		break;

		case MANUAL:
			manual_state();
		break;

		case SEQUENCE_STOPPED:
			sequence_stopped_state();
		break;

		case SEQUENCE_PLAYING:
			sequence_playing_state();
		break;
	}
}

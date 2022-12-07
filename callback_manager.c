/*
 * callback_manager.c
 * This source file helps with the callback management, this function
 * only works when a sound button is pressed
 *
 *  Created on: 16 nov 2022
 *      Author: Laura García
 */

#include "sounds.h"
#include "dma.h"
#include "config.h"
#include "gpio.h"
#include "pit.h"
#include "buffer.h"
#include "state_machine.h"
#include "lcd_nokia.h"

/******** static function *******/
static inline void kick_pressed(void);
static inline void snare_pressed(void);
static inline void bongo_pressed(void);
static inline void hithat_pressed(void);
static inline void guiro_pressed(void);
static inline void rimshot_pressed(void);
static inline void tambor_pressed(void);
static inline void cynbal_pressed(void);
static inline void cowbell_pressed(void);


static inline void kick_pressed(void){
	if( MANUAL == get_current_state() ){
		add_buffer(KICK);
	}
	else if(SEQUENCE_STOPPED == get_current_state()){
		add_buffer(KICK);
		LCD_nokia_send_char('K');
	}
}

static inline void snare_pressed(void){
	if( MANUAL == get_current_state() ){
		add_buffer(SNARE);
	}
	else if(SEQUENCE_STOPPED == get_current_state()){
		add_buffer(SNARE);
		LCD_nokia_send_char('S');
	}
}

static inline void bongo_pressed(void){
	if( MANUAL == get_current_state() ){
		add_buffer(BONGO);
	}
	else if(SEQUENCE_STOPPED == get_current_state()){
		add_buffer(BONGO);
		LCD_nokia_send_char('B');
	}
}

static inline void hithat_pressed(void){
	if( MANUAL == get_current_state()){
		add_buffer(HITHAT);
	}
	else if(SEQUENCE_STOPPED == get_current_state()){
		add_buffer(HITHAT);
		LCD_nokia_send_char('H');
	}
}

static inline void guiro_pressed(void){
	if( MANUAL == get_current_state() ){
		add_buffer(GUIRO);
	}
	else if(SEQUENCE_STOPPED == get_current_state()){
		add_buffer(GUIRO);
		LCD_nokia_send_char('G');
	}
}
static inline void rimshot_pressed(void){
	if( MANUAL == get_current_state() ){
		add_buffer(RIMSHOT);
	}
	else if(SEQUENCE_STOPPED == get_current_state()){
		add_buffer(RIMSHOT);
		LCD_nokia_send_char('R');
	}
}

static inline void tambor_pressed(void){
	if( MANUAL == get_current_state() ){
		add_buffer(TAMBOR);
	}
	else if(SEQUENCE_STOPPED == get_current_state()){
		add_buffer(TAMBOR);
		LCD_nokia_send_char('T');
	}
}

static inline void cynbal_pressed(void){
	if( MANUAL == get_current_state() ){
		add_buffer(CYNBAL);
	}
	else if(SEQUENCE_STOPPED == get_current_state()){
		add_buffer(CYNBAL);
		LCD_nokia_send_char('C');
	}
}

static inline void cowbell_pressed(void){
	if( MANUAL == get_current_state() ){
		add_buffer(COWBELL);
	}
	else if(SEQUENCE_STOPPED == get_current_state()){
		add_buffer(COWBELL);
		LCD_nokia_send_char('W');
	}
}

void sound_button_pressed(uint32_t port){
	if(get_kick_pressed_flag()){
		kick_pressed();
		set_kick_pressed_flag(FALSE);
	}

	if(get_snare_pressed_flag()){
		snare_pressed();
		set_snare_pressed_flag(FALSE);
	}

	if(get_bongo_pressed_flag()){
		bongo_pressed();
		set_bongo_pressed_flag(FALSE);
	}

	if(get_hithat_pressed_flag()){
		hithat_pressed();

		set_hithat_pressed_flag(FALSE);
	}

	if(get_guiro_pressed_flag()){
		guiro_pressed();
		set_guiro_pressed_flag(FALSE);
	}

	if(get_rimshot_pressed_flag()){
		rimshot_pressed();
		set_rimshot_pressed_flag(FALSE);
	}

	if(get_tambor_pressed_flag()){
		tambor_pressed();
		set_tambor_pressed_flag(FALSE);
	}

	if(get_cynbal_pressed_flag()){
		cynbal_pressed();
		set_cynbal_pressed_flag(FALSE);
	}

	if(get_cowbell_pressed_flag()){
		cowbell_pressed();
		set_cowbell_pressed_flag(FALSE);
	}
}


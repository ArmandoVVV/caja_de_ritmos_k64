/**
 * @authors: Armando Cabrales & Laura Garcia
 * @file    Equipo_3_P3.c
 * @brief   Rhythm Composer which can play nine different sounds
 * 			and create a sequence of that sounds.
 */
#include "config.h"
#include "spi.h"
#include "dac.h"
#include "nvic.h"
#include "gpio.h"
#include "lcd_nokia.h"
#include "S25FLXX.h"
#include "watchdog.h"
#include "clock_config.h"
#include "pit.h"
#include "dma.h"
#include "callback_manager.h"
#include "sounds.h"
#include "buffer.h"
#include "state_machine.h"

void main(void) {
	uint16_t reset_count;

	GPIO_init();
	SPI_config();
	DAC_init();
	LCD_nokia_init();

	NVIC_set_basepri_threshold(PRIORITY_8);

	NVIC_enable_interrupt_and_priotity(PORTB_IRQ,PRIORITY_2);
	NVIC_enable_interrupt_and_priotity(PORTD_IRQ,PRIORITY_2);
	NVIC_enable_interrupt_and_priotity(PORTA_IRQ,PRIORITY_2);
	NVIC_enable_interrupt_and_priotity(PORTC_IRQ,PRIORITY_2);
	NVIC_enable_interrupt_and_priotity(DMA_CH0_IRQ,PRIORITY_2);
	NVIC_enable_interrupt_and_priotity(PIT_CH0_IRQ,PRIORITY_2);

	NVIC_global_enable_interrupts;

	GPIO_callback_init(GPIO_B, sound_button_pressed);
	GPIO_callback_init(GPIO_C, sound_button_pressed);


	// setups the k64's clock to 100MHz
	clock_config();

	LCD_welcome_image(); //show image
	setup_sounds();
	LCD_nokia_clear();  //clear image

	LCD_write_menu();

	PIT_init();
	PIT_stop();

	dma_init();

	setup_watchdog();
	reset_count = get_reset_count();

	// if the watchdog restarted the system
	if(0 < reset_count){
		// a system error ocurred
		LCD_error_image();

		while(TRUE){
			// loop to show always show the error image
			refresh_watchdog();
		}
	}

	while(TRUE) {
		// system is working correctly
		state_machine();

		refresh_watchdog();
	}

}

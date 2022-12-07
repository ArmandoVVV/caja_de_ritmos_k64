/*
 *lcd_nokia.c
 * \brief
 *      	This source file helps with the LCD NOKIA, helps us to set the LCD values,
 *      	 and start the LCD.
 *  Created on: 16 nov 2022
 *      Author: Laura García
 */

#ifndef LCD_NOKIA_H_
#define LCD_NOKIA_H_

#include "stdint.h"

#define SCREENW 84
#define SCREENH 48
#define DELAY 2000

#define IMAGE_SIZE 504

#define LCD_X 84
#define LCD_Y 48
#define LCD_DATA 1
#define LCD_CMD 0
#define DATA_OR_CMD_PIN 5 // cambio de 4 a 5
#define RESET_PIN 7 // cambio de 5 a 7
#define CE 6
/*It configures the LCD*/
void LCD_nokia_init(void);
/*It writes a byte in the LCD memory. The place of writting is the last place that was indicated by LCDNokia_gotoXY. In the reset state
 * the initial place is x=0 y=0*/
void LCD_nokia_write_byte(uint8_t data_or_command, uint8_t data);
/*it clears all the figures in the LCD*/
void LCD_nokia_clear(void);
/*It is used to indicate the place for writing a new character in the LCD. The values that x can take are 0 to 84 and y can take values
 * from 0 to 5*/
void LCD_nokia_goto_xy(uint8_t x, uint8_t y);
/*It allows to write a figure represented by constant array*/
void LCD_nokia_bitmap(const uint8_t bitmap []);
/*It write a character in the LCD*/
void LCD_nokia_send_char(uint8_t);
/*It write a string into the LCD*/
void LCD_nokia_send_string(const uint8_t string []);
/*It used in the initialization routine*/
void LCD_nokia_delay(void);

// writes the initial menu on the nokia display
void LCD_write_menu(void);
// indicates in the lcd that we are in the manual mode
void LCD_write_manual_mode(void);
// writes in the lcd the welcome image
void LCD_welcome_image(void);

void LCD_error_image(void);
// indicates in the lcd that we are in the sequence mode
void LCD_write_sequence_mode(void);

void LCD_write_playing(void);
void LCD_write_stopped(void);


#endif /* LCD_NOKIA_H_ */

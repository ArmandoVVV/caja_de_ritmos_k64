/*
 * config.h
 *
 * 		\brief
 * 		This is a source file for the configuration for the practice 3.
 * 		Device driver for Kinetis K64.
 * 		it contains all the definitions of the macros.
 *
 *  	Created on: Nov 10, 2022
 *		Author: Laura García
 */

#ifndef CONFIG_H_
#define CONFIG_H_

typedef enum{FALSE, TRUE} boolean_t;

typedef enum{DISABLE,
			 ENABLE
}device_status_t;


//GPIO
#define SOUND_KICK_GPIO		(GPIOB)  // SOUNDS
#define SOUND_SNARE_GPIO	(GPIOB)
#define SOUND_BONGO_GPIO	(GPIOC)
#define SOUND_HITHAT_GPIO	(GPIOC)
#define SOUND_GUIRO_GPIO	(GPIOB)
#define SOUND_RIMSHOT_GPIO	(GPIOC)
#define SOUND_TAMBOR_GPIO	(GPIOB)
#define SOUND_CYNBAL_GPIO	(GPIOC)
#define SOUND_COWBELL_GPIO	(GPIOC)
#define BUTTON_MENU_GPIO	(GPIOA)  // BUTTONS
#define BUTTON_B1_GPIO 		(GPIOD)
#define BUTTON_B2_GPIO  	(GPIOD)
#define LCD_CE_GPIO			(GPIOD)	// DISPLAY AND MEMORY
#define CLK_GPIO			(GPIOD)
#define DIN_SI_GPIO			(GPIOD)
#define SO_GPIO				(GPIOD)
#define LCD_DC_GPIO			(GPIOC)
#define LCD_RST_GPIO		(GPIOC)
#define MEMORY_CE_GPIO		(GPIOC)


//PORTS
#define SOUND_KICK_PORT		(PORTB)
#define SOUND_SNARE_PORT	(PORTB)
#define SOUND_BONGO_PORT	(PORTC)
#define SOUND_HITHAT_PORT	(PORTC)
#define SOUND_GUIRO_PORT	(PORTB)
#define SOUND_RIMSHOT_PORT	(PORTC)
#define SOUND_TAMBOR_PORT	(PORTB)
#define SOUND_CYNBAL_PORT	(PORTC)
#define SOUND_COWBELL_PORT	(PORTC)
#define BUTTON_MENU_PORT	(PORTA)  // BUTTONS
#define BUTTON_B1_PORT 		(PORTD)
#define BUTTON_B2_PORT  	(PORTD)
#define LCD_CE_PORT			(PORTD)	// DISPLAY AND MEMORY
#define CLK_PORT			(PORTD)
#define DIN_SI_PORT 		(PORTD)
#define SO_PORT				(PORTD)
#define LCD_DC_PORT			(PORTC)
#define LCD_RST_PORT		(PORTC)
#define MEMORY_CE_PORT		(PORTC)


//PIN
#define SOUND_KICK_PIN		(19u)  // SOUNDS
#define SOUND_SNARE_PIN		(18u)
#define SOUND_BONGO_PIN		(2u) // WARNING PIN ORIGIN ES 1
#define SOUND_HITHAT_PIN	(8u)
#define SOUND_GUIRO_PIN		(23u)
#define SOUND_RIMSHOT_PIN	(9u)
#define SOUND_TAMBOR_PIN	(9u)
#define SOUND_CYNBAL_PIN	(0u)
#define SOUND_COWBELL_PIN	(16u)
#define BUTTON_MENU_PIN		(1u)  // BUTTONS
#define BUTTON_B1_PIN 		(4u)
#define BUTTON_B2_PIN  		(5u)
#define LCD_CE_PIN			(0u)	// DISPLAY AND MEMORY
#define CLK_PIN				(1u)
#define DIN_SI_PIN 			(2u)
#define SO_PIN				(3u)
#define LCD_DC_PIN			(5u)
#define LCD_RST_PIN			(7u)
#define MEMORY_CE_PIN		(3u)


// MASKS
#define SOUND_KICK_MASK		(1 << SOUND_KICK_PIN)  // SOUNDS
#define SOUND_SNARE_MASK	(1 << SOUND_SNARE_PIN)
#define SOUND_BONGO_MASK	(1 << SOUND_BONGO_PIN)
#define SOUND_HITHAT_MASK	(1 << SOUND_HITHAT_PIN)
#define SOUND_GUIRO_MASK	(1 << SOUND_GUIRO_PIN)
#define SOUND_RIMSHOT_MASK	(1 << SOUND_RIMSHOT_PIN)
#define SOUND_TAMBOR_MASK	(1 << SOUND_TAMBOR_PIN)
#define SOUND_CYNBAL_MASK	(1 << SOUND_CYNBAL_PIN)
#define SOUND_COWBELL_MASK	(1 << SOUND_COWBELL_PIN)
#define BUTTON_MENU_MASK	(1 << BUTTON_MENU_PIN)  // BUTTONS
#define BUTTON_B1_MASK 		(1 << BUTTON_B1_PIN)
#define BUTTON_B2_MASK  	(1 << BUTTON_B2_PIN)
#define LCD_CE_MASK			(1 << LCD_CE_PIN)	// DISPLAY AND MEMORY
#define CLK_MASK			(1 << CLK_PIN)
#define DIN_SI_MASK 		(1 << DIN_SI_PIN)
#define SO_MASK				(1 << SO_PIN)
#define LCD_DC_MASK			(1 << LCD_DC_PIN)
#define LCD_RST_MASK		(1 << LCD_RST_PIN)
#define MEMORY_CE_MASK		(1 << MEMORY_CE_PIN)

// ADRESSES

#define KICK_ADDRESS		0x2C000
#define SNARE_ADDRESS		0x37000
#define BONGO_ADDRESS		0x4000
#define HITHAT_ADDRESS		0x25000
#define GUIRO_ADDRESS		0x16000
#define RIMSHOT_ADDRESS		0x31000
#define TAMBOR_ADDRESS		0x39000
#define CYNBAL_ADDRESS		0xE000
#define COWBELL_ADDRESS		0xC000

// TOTAL BYTES

#define KICK_BYTES			6704
#define SNARE_BYTES			3561
#define BONGO_BYTES			2067
#define HITHAT_BYTES		2410
#define GUIRO_BYTES			7067
#define RIMSHOT_BYTES		808
#define TAMBOR_BYTES		4650
#define CYNBAL_BYTES		10075
#define COWBELL_BYTES		5000

#endif /* CONFIG_H_ */

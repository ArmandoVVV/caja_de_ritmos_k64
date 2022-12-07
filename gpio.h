// gpio.h
/**
*	\file
*	\brief
*		This is the source file for the GPIO device driver for Kinetis K64.
*		It contains all the implementation for configuration functions and runtime functions.
*		i.e., this is the application programming interface (API) for the GPIO peripheral.
*	\date	28/09/2022
*	\
*	    Author: Laura García
*
*/

#ifndef GPIO_H_
#define GPIO_H_

#include "stdint.h"
#include "config.h"
#include "fsl_gpio.h"

/*! These constants are used to select an specific port in the different API functions*/
typedef enum{GPIO_A, /*!< Definition to select GPIO A */
			 GPIO_B, /*!< Definition to select GPIO B */
			 GPIO_C, /*!< Definition to select GPIO C */
			 GPIO_D, /*!< Definition to select GPIO D */
			 GPIO_E, /*!< Definition to select GPIO E */
			 GPIO_F  /*!< Definition to select GPIO F */
			} gpio_name_t;

typedef struct
{
	uint8_t flag_port_a : 1;
	uint8_t flag_port_b : 1;
	uint8_t flag_port_c : 1;
	uint8_t flag_port_d : 1;
	uint8_t flag_port_e : 1;
} gpio_interrupt_flags_t;

boolean_t get_buttonB1_pressed_flag(void);
void set_buttonB1_pressed_flag(boolean_t value);

boolean_t get_buttonB2_pressed_flag(void);
void set_buttonB2_pressed_flag(boolean_t value);

boolean_t get_buttonMenu_pressed_flag(void);
void set_buttonMenu_pressed_flag(boolean_t value);

// getters
boolean_t get_kick_pressed_flag(void);
boolean_t get_snare_pressed_flag(void);
boolean_t get_bongo_pressed_flag(void);
boolean_t get_hithat_pressed_flag(void);
boolean_t get_guiro_pressed_flag(void);
boolean_t get_rimshot_pressed_flag(void);
boolean_t get_tambor_pressed_flag(void);
boolean_t get_cynbal_pressed_flag(void);
boolean_t get_cowbell_pressed_flag(void);

// Setters
void set_kick_pressed_flag(boolean_t value);
void set_snare_pressed_flag(boolean_t value);
void set_bongo_pressed_flag(boolean_t value);
void set_hithat_pressed_flag(boolean_t value);
void set_guiro_pressed_flag(boolean_t value);
void set_rimshot_pressed_flag(boolean_t value);
void set_tambor_pressed_flag(boolean_t value);
void set_cynbal_pressed_flag(boolean_t value);
void set_cowbell_pressed_flag(boolean_t value);

void GPIO_callback_init(gpio_name_t gpio, void (*handler)(uint32_t flags));

void GPIO_clear_irq_status(gpio_name_t gpio);

uint8_t GPIO_get_irq_status(gpio_name_t gpio);

void GPIO_init(void);

#endif /* GPIO_H_ */

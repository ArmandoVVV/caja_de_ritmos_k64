/*
 * gpio.c
 *	\brief
 *		This is the source file for the GPIO device driver for Kinetis K64.
 *		It contains all the implementation for configuration functions and runtime functions.
 *		i.e., this is the application programming interface (API) for the GPIO peripheral.
 *  Created on: Nov 8, 2022
 *      Author: armando Cabrales
 */

#include <gpio.h>
#include "fsl_port.h"

static volatile boolean_t g_buttonB1_pressed_flag = FALSE;
static volatile boolean_t g_buttonB2_pressed_flag = FALSE;
static volatile boolean_t g_buttonMenu_pressed_flag = FALSE;

volatile static boolean_t g_kick_pressed_flag = FALSE;
volatile static boolean_t g_snare_pressed_flag = FALSE;
volatile static boolean_t g_bongo_pressed_flag = FALSE;
volatile static boolean_t g_hithat_pressed_flag = FALSE;
volatile static boolean_t g_guiro_pressed_flag = FALSE;
volatile static boolean_t g_rimshot_pressed_flag = FALSE;
volatile static boolean_t g_tambor_pressed_flag = FALSE;
volatile static boolean_t g_cynbal_pressed_flag = FALSE;
volatile static boolean_t g_cowbell_pressed_flag = FALSE;

static void (*gpio_A_callback)(uint32_t flags) = 0;
static void (*gpio_B_callback)(uint32_t flags) = 0;
static void (*gpio_C_callback)(uint32_t flags) = 0;
static void (*gpio_D_callback)(uint32_t flags) = 0;
static void (*gpio_E_callback)(uint32_t flags) = 0;

boolean_t get_buttonB1_pressed_flag(void){
	return g_buttonB1_pressed_flag;
}
void set_buttonB1_pressed_flag(boolean_t value){
	g_buttonB1_pressed_flag = value;
}

boolean_t get_buttonB2_pressed_flag(void){
	return g_buttonB2_pressed_flag;
}
void set_buttonB2_pressed_flag(boolean_t value){
	g_buttonB2_pressed_flag = value;
}

boolean_t get_buttonMenu_pressed_flag(void){
	return g_buttonMenu_pressed_flag;
}
void set_buttonMenu_pressed_flag(boolean_t value){
	g_buttonMenu_pressed_flag = value;
}

//////// Getters
boolean_t get_kick_pressed_flag(void){
	return g_kick_pressed_flag;
}

boolean_t get_snare_pressed_flag(void){
	return g_snare_pressed_flag;
}

boolean_t get_bongo_pressed_flag(void){
	return g_bongo_pressed_flag;
}

boolean_t get_hithat_pressed_flag(void){
	return g_hithat_pressed_flag;
}

boolean_t get_guiro_pressed_flag(void){
	return g_guiro_pressed_flag;
}

boolean_t get_rimshot_pressed_flag(void){
	return g_rimshot_pressed_flag;
}

boolean_t get_tambor_pressed_flag(void){
	return g_tambor_pressed_flag;
}

boolean_t get_cynbal_pressed_flag(void){
	return g_cynbal_pressed_flag;
}

boolean_t get_cowbell_pressed_flag(void){
	return g_cowbell_pressed_flag;
}

////////Setters
void set_kick_pressed_flag(boolean_t value){
	g_kick_pressed_flag = value;
}

void set_snare_pressed_flag(boolean_t value){
	g_snare_pressed_flag = value;
}

void set_bongo_pressed_flag(boolean_t value){
	g_bongo_pressed_flag = value;
}

void set_hithat_pressed_flag(boolean_t value){
	g_hithat_pressed_flag = value;
}

void set_guiro_pressed_flag(boolean_t value){
	g_guiro_pressed_flag = value;
}

void set_rimshot_pressed_flag(boolean_t value){
	g_rimshot_pressed_flag = value;
}

void set_tambor_pressed_flag(boolean_t value){
	g_tambor_pressed_flag = value;
}

void set_cynbal_pressed_flag(boolean_t value){
	g_cynbal_pressed_flag = value;
}

void set_cowbell_pressed_flag(boolean_t value){
	g_cowbell_pressed_flag = value;
}


//////


void GPIO_callback_init(gpio_name_t gpio, void (*handler)(uint32_t flags))
{
	switch(gpio){
		case GPIO_A:
			gpio_A_callback = handler;
			break;

		case GPIO_B:
			gpio_B_callback = handler;
			break;

		case GPIO_C:
			gpio_C_callback = handler;
			break;

		case GPIO_D:
			gpio_D_callback = handler;
			break;

		default: // gpio == GPIO_E
			gpio_E_callback = handler;
	}
}

void PORTD_IRQHandler(void)
{
	uint32_t irq_status = 0;

	irq_status = GPIO_PortGetInterruptFlags(GPIOD);

	if(irq_status & BUTTON_B1_MASK){
		set_buttonB1_pressed_flag(TRUE);
	}

	if(irq_status & BUTTON_B2_MASK){
		set_buttonB2_pressed_flag(TRUE);
	}

	if(gpio_D_callback)
	{
		gpio_D_callback(irq_status);
	}

	GPIO_PortClearInterruptFlags(GPIOD, irq_status);
}

void PORTC_IRQHandler(void)
{
	uint32_t irq_status = 0;

	irq_status = GPIO_PortGetInterruptFlags(GPIOC);

	if(irq_status & SOUND_BONGO_MASK){
		set_bongo_pressed_flag(TRUE);
	}

	if(irq_status & SOUND_HITHAT_MASK){
		set_hithat_pressed_flag(TRUE);
	}

	if(irq_status & SOUND_RIMSHOT_MASK){
		set_rimshot_pressed_flag(TRUE);
	}

	if(irq_status & SOUND_CYNBAL_MASK){
		set_cynbal_pressed_flag(TRUE);
	}

	if(irq_status & SOUND_COWBELL_MASK){
		set_cowbell_pressed_flag(TRUE);
	}


	if(gpio_C_callback)
	{
		gpio_C_callback(irq_status);
	}

	GPIO_PortClearInterruptFlags(GPIOC, irq_status);


}

void PORTB_IRQHandler(void)
{
	uint32_t irq_status = 0;

	irq_status = GPIO_PortGetInterruptFlags(GPIOB);

	if(irq_status & SOUND_KICK_MASK){
		set_kick_pressed_flag(TRUE);
	}

	if(irq_status & SOUND_SNARE_MASK){
		set_snare_pressed_flag(TRUE);
	}

	if(irq_status & SOUND_GUIRO_MASK){
		set_guiro_pressed_flag(TRUE);
	}

	if(irq_status & SOUND_TAMBOR_MASK){
		set_tambor_pressed_flag(TRUE);
	}

	if(gpio_B_callback)
	{
		gpio_B_callback(irq_status);
	}

	GPIO_PortClearInterruptFlags(GPIOB, irq_status);
}

void PORTA_IRQHandler(void)
{
	uint32_t irq_status = 0;

	irq_status = GPIO_PortGetInterruptFlags(GPIOA);

	if(irq_status & BUTTON_MENU_MASK){
		set_buttonMenu_pressed_flag(TRUE);
	}

	if(gpio_A_callback)
	{
		gpio_A_callback(irq_status);
	}

	GPIO_PortClearInterruptFlags(GPIOA, irq_status);
}


void GPIO_init(void)
{
	gpio_pin_config_t gpio_input_config = {
			        kGPIO_DigitalInput,
			        0,
			    };

//	gpio_pin_config_t gpio_output_config = {
//			        kGPIO_DigitalOutput,
//			        1,
//			    };

	const port_pin_config_t spi_config = {
		.pullSelect = kPORT_PullDisable,
		.slewRate = kPORT_FastSlewRate,
		.passiveFilterEnable = kPORT_PassiveFilterEnable,
		.openDrainEnable = kPORT_OpenDrainDisable,
		.driveStrength = kPORT_HighDriveStrength,
		.mux = kPORT_MuxAlt2,
		.lockRegister = kPORT_UnlockRegister,
	};

	const port_pin_config_t button_config = {
			kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
			kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
			kPORT_PassiveFilterEnable,                              /* Passive filter is disabled */
			kPORT_OpenDrainDisable,                                  /* Open drain is disabled */
			kPORT_HighDriveStrength,                                 /* High drive strength is configured */
			kPORT_MuxAsGpio,                                         /* Pin is configured as PTA4 */
			kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
		  };


	CLOCK_EnableClock(kCLOCK_PortD);
	CLOCK_EnableClock(kCLOCK_PortC);
	CLOCK_EnableClock(kCLOCK_PortB);
	CLOCK_EnableClock(kCLOCK_PortA);

	// DC AND RST
	gpio_pin_config_t gpio_pin_config;

	gpio_pin_config.outputLogic = 0;
	gpio_pin_config.pinDirection = kGPIO_DigitalOutput;

	GPIO_PinInit(LCD_DC_GPIO, LCD_DC_PIN, &gpio_pin_config);

	gpio_pin_config.outputLogic = 1;

	GPIO_PinInit(LCD_RST_GPIO, LCD_RST_PIN, &gpio_pin_config);

	PORT_SetPinMux(LCD_DC_PORT, LCD_DC_PIN, kPORT_MuxAsGpio);
	PORT_SetPinMux(LCD_RST_PORT, LCD_RST_PIN, kPORT_MuxAsGpio);


	// DISPLAY AND MEMORY
	PORT_SetPinConfig(LCD_CE_PORT, LCD_CE_PIN, &spi_config);
	PORT_SetPinConfig(CLK_PORT, CLK_PIN, &spi_config);
	PORT_SetPinConfig(DIN_SI_PORT, DIN_SI_PIN, &spi_config);
	PORT_SetPinConfig(SO_PORT, SO_PIN, &spi_config);
	PORT_SetPinConfig(MEMORY_CE_PORT, MEMORY_CE_PIN, &spi_config);

	// SOUND BUTTONS
	PORT_SetPinConfig(SOUND_KICK_PORT, SOUND_KICK_PIN, &button_config);
	GPIO_PinInit(SOUND_KICK_GPIO, SOUND_KICK_PIN, &gpio_input_config);
	PORT_SetPinInterruptConfig(SOUND_KICK_PORT, SOUND_KICK_PIN, kPORT_InterruptFallingEdge);

	PORT_SetPinConfig(SOUND_SNARE_PORT, SOUND_SNARE_PIN, &button_config);
	GPIO_PinInit(SOUND_SNARE_GPIO, SOUND_SNARE_PIN, &gpio_input_config);
	PORT_SetPinInterruptConfig(SOUND_SNARE_PORT, SOUND_SNARE_PIN, kPORT_InterruptFallingEdge);

	PORT_SetPinConfig(SOUND_BONGO_PORT, SOUND_BONGO_PIN, &button_config);
	GPIO_PinInit(SOUND_BONGO_GPIO, SOUND_BONGO_PIN, &gpio_input_config);
	PORT_SetPinInterruptConfig(SOUND_BONGO_PORT, SOUND_BONGO_PIN, kPORT_InterruptFallingEdge);

	PORT_SetPinConfig(SOUND_HITHAT_PORT, SOUND_HITHAT_PIN, &button_config);
	GPIO_PinInit(SOUND_HITHAT_GPIO, SOUND_HITHAT_PIN, &gpio_input_config);
	PORT_SetPinInterruptConfig(SOUND_HITHAT_PORT, SOUND_HITHAT_PIN, kPORT_InterruptFallingEdge);

	PORT_SetPinConfig(SOUND_GUIRO_PORT, SOUND_GUIRO_PIN, &button_config);
	GPIO_PinInit(SOUND_GUIRO_GPIO, SOUND_GUIRO_PIN, &gpio_input_config);
	PORT_SetPinInterruptConfig(SOUND_GUIRO_PORT, SOUND_GUIRO_PIN, kPORT_InterruptFallingEdge);

	PORT_SetPinConfig(SOUND_RIMSHOT_PORT, SOUND_RIMSHOT_PIN, &button_config);
	GPIO_PinInit(SOUND_RIMSHOT_GPIO, SOUND_RIMSHOT_PIN, &gpio_input_config);
	PORT_SetPinInterruptConfig(SOUND_RIMSHOT_PORT, SOUND_RIMSHOT_PIN, kPORT_InterruptFallingEdge);

	PORT_SetPinConfig(SOUND_TAMBOR_PORT, SOUND_TAMBOR_PIN, &button_config);
	GPIO_PinInit(SOUND_TAMBOR_GPIO, SOUND_TAMBOR_PIN, &gpio_input_config);
	PORT_SetPinInterruptConfig(SOUND_TAMBOR_PORT, SOUND_TAMBOR_PIN, kPORT_InterruptFallingEdge);

	PORT_SetPinConfig(SOUND_CYNBAL_PORT, SOUND_CYNBAL_PIN, &button_config);
	GPIO_PinInit(SOUND_CYNBAL_GPIO, SOUND_CYNBAL_PIN, &gpio_input_config);
	PORT_SetPinInterruptConfig(SOUND_CYNBAL_PORT, SOUND_CYNBAL_PIN, kPORT_InterruptFallingEdge);

	PORT_SetPinConfig(SOUND_COWBELL_PORT, SOUND_COWBELL_PIN, &button_config);
	GPIO_PinInit(SOUND_COWBELL_GPIO, SOUND_COWBELL_PIN, &gpio_input_config);
	PORT_SetPinInterruptConfig(SOUND_COWBELL_PORT, SOUND_COWBELL_PIN, kPORT_InterruptFallingEdge);

	// BUTTONS
	PORT_SetPinConfig(BUTTON_MENU_PORT, BUTTON_MENU_PIN, &button_config);
	GPIO_PinInit(BUTTON_MENU_GPIO, BUTTON_MENU_PIN, &gpio_input_config);
	PORT_SetPinInterruptConfig(BUTTON_MENU_PORT, BUTTON_MENU_PIN, kPORT_InterruptFallingEdge);

	PORT_SetPinConfig(BUTTON_B1_PORT, BUTTON_B1_PIN, &button_config);
	GPIO_PinInit(BUTTON_B1_GPIO, BUTTON_B1_PIN, &gpio_input_config);
	PORT_SetPinInterruptConfig(BUTTON_B1_PORT, BUTTON_B1_PIN, kPORT_InterruptFallingEdge);

	PORT_SetPinConfig(BUTTON_B2_PORT, BUTTON_B2_PIN, &button_config);
	GPIO_PinInit(BUTTON_B2_GPIO, BUTTON_B2_PIN, &gpio_input_config);
	PORT_SetPinInterruptConfig(BUTTON_B2_PORT, BUTTON_B2_PIN, kPORT_InterruptFallingEdge);

}

/*
 * pit.c
 *
 * 		\brief
 * 		This is the PIT source file for the device driver for Kinetis K64.
 * 		It contains all PIT´s configuration functions and runtime functions.
 *      Created on: Sep 20, 2022
 *      Author: Armando Cabrales
 */

#include "pin_mux.h"
#include "clock_config.h"
#include "pit.h"
#include "config.h"

#define PIT_SOURCE_CLOCK CLOCK_GetFreq(kCLOCK_BusClk)

volatile boolean_t g_pit0_flag = FALSE;

boolean_t get_pit0_flag(void){
	return g_pit0_flag;
}

void set_pit0_flag(boolean_t value){
	g_pit0_flag = value;
}

static void (*PIT_0_callback)(uint32_t flags) = 0;
static void (*PIT_1_callback)(uint32_t flags) = 0;

void PIT0_IRQHandler(void)
{
	uint32_t irq_status = false;
	set_pit0_flag(TRUE);

	irq_status = PIT_GetStatusFlags(PIT, kPIT_Chnl_0);

	if(PIT_0_callback)
	{
		PIT_0_callback(irq_status);
	}
	PIT_ClearStatusFlags(PIT, kPIT_Chnl_0, kPIT_TimerFlag);
	__DSB(); //Used to enter the interrupt

}

void PIT1_IRQHandler(void)
{
	uint32_t irq_status = false;

	irq_status = PIT_GetStatusFlags(PIT, kPIT_Chnl_1);

	if(PIT_1_callback)
	{
		PIT_1_callback(irq_status);
	}
	PIT_ClearStatusFlags(PIT, kPIT_Chnl_1, kPIT_TimerFlag);
	__DSB(); //Used to enter the interrupt

}

void PIT_callback_init(pit_chnl_t channel, void (*handler)(uint32_t flags))
{
	if(kPIT_Chnl_0 == channel){
		PIT_0_callback = handler;
	}
	else if(kPIT_Chnl_1 == channel){
		PIT_1_callback = handler;
	}
}

void PIT_stop(void){
	PIT_StopTimer(PIT, kPIT_Chnl_0);
}

void PIT_start(void){
	PIT_StartTimer(PIT, kPIT_Chnl_0);
}

void PIT_init(void){
	pit_config_t pitConfig;

	CLOCK_SetSimSafeDivs();
	PIT_GetDefaultConfig(&pitConfig);
	PIT_Init(PIT, &pitConfig);


	PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, USEC_TO_COUNT(62U, PIT_SOURCE_CLOCK));
	PIT_EnableInterrupts(PIT, kPIT_Chnl_0, kPIT_TimerInterruptEnable);
	EnableIRQ(PIT0_IRQn);
	PIT_StartTimer(PIT, kPIT_Chnl_0);

}

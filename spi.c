/*
 * spi.c
 * \brief
 *		This source file helps us to set the SPI values to create
 *		Different signals, and start the SPI.
 *  Created on: Nov 8, 2022
 *      Author: Armando Cabrales
 */


#include "SPI.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "fsl_clock.h"
#include "clock_config.h"
#include "fsl_clock.h"
#include "config.h"

void SPI_config(void)
{
	dspi_master_config_t masterConfig;

	CLOCK_EnableClock(kCLOCK_Spi0);

	masterConfig.whichCtar = kDSPI_Ctar0;

	masterConfig.ctarConfig.baudRate = TRANSFER_BAUDRATE;
	masterConfig.ctarConfig.bitsPerFrame = 8u;
	masterConfig.ctarConfig.cpol = kDSPI_ClockPolarityActiveHigh;
	masterConfig.ctarConfig.cpha = kDSPI_ClockPhaseFirstEdge;
	masterConfig.ctarConfig.direction = kDSPI_MsbFirst;

	masterConfig.ctarConfig.pcsToSckDelayInNanoSec = 10000 / TRANSFER_BAUDRATE;
	masterConfig.ctarConfig.lastSckToPcsDelayInNanoSec = 10000 / TRANSFER_BAUDRATE;
	masterConfig.ctarConfig.betweenTransferDelayInNanoSec = 10000 / TRANSFER_BAUDRATE;

	masterConfig.whichPcs = kDSPI_Pcs0;
	masterConfig.pcsActiveHighOrLow = kDSPI_PcsActiveLow;
	masterConfig.enableContinuousSCK = false;
	masterConfig.enableRxFifoOverWrite = false;
	masterConfig.enableModifiedTimingFormat = false;
	masterConfig.samplePoint = kDSPI_SckToSin0Clock;

	DSPI_MasterInit(SPI0, &masterConfig, CLOCK_GetFreq(kDSPI_SckToSin0Clock));


	masterConfig.whichCtar = kDSPI_Ctar1;

	masterConfig.ctarConfig.baudRate = TRANSFER_BAUDRATE;
	masterConfig.ctarConfig.bitsPerFrame = 8u;
	masterConfig.ctarConfig.cpol = kDSPI_ClockPolarityActiveLow;
	masterConfig.ctarConfig.cpha = kDSPI_ClockPhaseSecondEdge;
	masterConfig.ctarConfig.direction = kDSPI_MsbFirst;

	masterConfig.ctarConfig.pcsToSckDelayInNanoSec = 10000 / TRANSFER_BAUDRATE;
	masterConfig.ctarConfig.lastSckToPcsDelayInNanoSec = 10000 / TRANSFER_BAUDRATE;
	masterConfig.ctarConfig.betweenTransferDelayInNanoSec = 10000 / TRANSFER_BAUDRATE;

	masterConfig.whichPcs = kDSPI_Pcs1;
	masterConfig.pcsActiveHighOrLow = kDSPI_PcsActiveLow;
	masterConfig.enableContinuousSCK = false;
	masterConfig.enableRxFifoOverWrite = false;
	masterConfig.enableModifiedTimingFormat = false;
	masterConfig.samplePoint = kDSPI_SckToSin0Clock;

	DSPI_MasterInit(SPI0, &masterConfig, CLOCK_GetFreq(kDSPI_SckToSin0Clock));

}


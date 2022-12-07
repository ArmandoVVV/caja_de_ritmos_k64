/*
 * spi.h
 * \brief
 *		This source file helps us to set the SPI values to create
 *		Different signals, and start the SPI.
 *  Created on: Nov 8, 2022
 *      Author: Armando Cabrales
 */
#include "fsl_dspi.h"

#ifndef SPI_H_
#define SPI_H_

#define TRANSFER_SIZE     64U     /*! Transfer dataSize */
#define TRANSFER_BAUDRATE 1000000U /*! Transfer baudrate - 500k */

// configurates the SPI
void SPI_config(void);

#endif /* SPI_H_ */

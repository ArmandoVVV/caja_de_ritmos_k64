/*
 * S25FLXX.c
 * \brief
 *      	This source file helps with the s25flxx, it allow us to read
 *      	the external memory s25flxx
 *  Created on: Oct 31, 2022
 *      Author: armando
 */

#include "S25FLXX.h"
#include "spi.h"
#include "config.h"

#define READ_COMMAND 0x03

uint8_t S25FLXXX_read_byte(s25flxxx_memory_address_t* address){
	dspi_half_duplex_transfer_t xfer = {0};
	uint8_t address_array[4];
	uint8_t received_data = 0;

	address_array[0] = READ_COMMAND;
	address_array[1] = address->address_by_byte.address_byte_2;
	address_array[2] = address->address_by_byte.address_byte_1;
	address_array[3] = address->address_by_byte.address_byte_0;

	xfer.txData = address_array;
	xfer.rxData = &received_data;
	xfer.txDataSize = 4;
	xfer.rxDataSize = 1;
	xfer.isTransmitFirst = TRUE;
	xfer.isPcsAssertInTransfer = TRUE;
	xfer.configFlags = kDSPI_MasterCtar1 | kDSPI_MasterPcs1 | kDSPI_MasterPcsContinuous;

	DSPI_MasterHalfDuplexTransferBlocking(SPI0, &xfer);

	return(received_data);
}

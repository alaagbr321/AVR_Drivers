/*
 * SPI_Interface.h
 *
 *  Created on: Aug 20, 2023
 *      Author: WIN10
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

typedef enum
{
	FCPU_4,
	FCPU_16,
	FCPU_64,
	FCPU_128,
}Clock_mode;





void SPI_voidMasterInit(Clock_mode Clock);
void SPI_voidMasterTransmit(u8 Copy_u8DataTransmited);
void SPI_voidSlaveInit();
u8 SPI_voidSlaveRecive();


#endif /* MCAL_SPI_SPI_INTERFACE_H_ */

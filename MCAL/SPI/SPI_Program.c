/*
 * SPI_Program.c
 *
 *  Created on: Aug 20, 2023
 *      Author: WIN10
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "SPI_Interface.h"
#include "SPI_Config.h"
#include "SPI_Private.h"

#include "../../MCAL/DIO/DIO_Interface.h"






void SPI_voidMasterInit(Clock_mode Clock)
{
	/*configure DIO pins*/
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN4,DIO_OUTPUT);//SS
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN5,DIO_OUTPUT);//MOSI
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN6,DIO_INPUT);//MISO
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN7,DIO_OUTPUT);//SCK
	/*choose data order*/
	CLR_BIT(SPCR_REG,DORD); //MSB first

	/*enable Master*/
	SET_BIT(SPCR_REG,MSTR);

	/*Clock Polarity*/
	CLR_BIT(SPCR_REG,CPOL); //leading-->rising

	/*Clock Phase*/
	CLR_BIT(SPCR_REG,CPHA); //sample at leading

	/*Clock Rate*/
	SPCR_REG &= 0xFC;
	SPCR_REG |= Clock;


	/*enable SPI*/
	SET_BIT(SPCR_REG,SPE);



}
void SPI_voidMasterTransmit(u8 Copy_u8DataTransmited)
{
	/* transmit DATA */
	SPDR_REG=Copy_u8DataTransmited;

	/*wait till transmission is Complete*/
	while(GET_BIT(SPSR_REG,SPIF)!=1);



}
void SPI_voidSlaveInit()
{
	/*configure DIO pins*/
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN4,DIO_INPUT);//SS
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,DIO_HIGH);//SS input_PullUp
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN5,DIO_INPUT);//MOSI
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN6,DIO_OUTPUT);//MISO
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN7,DIO_INPUT);//SCK

	/*enable SPI*/
	SET_BIT(SPCR_REG,SPE);

	/*choose data order*/
	CLR_BIT(SPCR_REG,DORD); //MSB first

	/*enable Slave*/
	CLR_BIT(SPCR_REG,MSTR);

}
u8 SPI_voidSlaveRecive()
{
	while(GET_BIT(SPSR_REG,SPIF)!=1);
	return SPDR_REG;
}

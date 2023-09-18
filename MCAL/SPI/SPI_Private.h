/*
 * SPI_Private.h
 *
 *  Created on: Aug 20, 2023
 *      Author: WIN10
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_


#define SPCR_REG     	   *((volatile u8*)0x2D)
#define	SPSR_REG    	   *((volatile u8*)0x2E)
#define	SPDR_REG    	   *((volatile u8*)0x2F)


//SPCR_REG
#define SPR0	  	0
#define SPR1     	1
#define CPHA     	2
#define CPOL        3
#define MSTR        4
#define DORD        5
#define SPE         6
#define SPIE        7

//SPSR_REG
#define SPI2X	  	0
#define WCOL     	6
#define SPIF     	7

//SPDR_REG
#define LSB	 	 	0
#define MSB     	7





#endif /* MCAL_SPI_SPI_PRIVATE_H_ */

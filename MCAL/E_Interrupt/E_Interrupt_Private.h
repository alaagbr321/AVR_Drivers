/*
 * E_Interrupt_Private.h
 *
 *  Created on: Aug 12, 2023
 *      Author: WIN10
 */

#ifndef MCAL_E_INTERRUPT_E_INTERRUPT_PRIVATE_H_
#define MCAL_E_INTERRUPT_E_INTERRUPT_PRIVATE_H_


#define MCUCR_REG   *((volatile u8*)0x55)
#define MCUCSR_REG	*((volatile u8*)0x54)
#define GICR_REG    *((volatile u8*)0x5B)
#define GIFR_REG    *((volatile u8*)0x5A)





#endif /* MCAL_E_INTERRUPT_E_INTERRUPT_PRIVATE_H_ */

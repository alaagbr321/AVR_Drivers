/*
 * E_Interrupt_Interface.h
 *
 *  Created on: Aug 12, 2023
 *      Author: WIN10
 */

#ifndef MCAL_E_INTERRUPT_E_INTERRUPT_INTERFACE_H_
#define MCAL_E_INTERRUPT_E_INTERRUPT_INTERFACE_H_

#define E_Interrupt_FallingEdge   0
#define E_Interrupt_RisingEdge    1
#define E_Interrupt_OnChange      2
#define E_Interrupt_LowLevel      3

#define E_INT0                    0
#define E_INT1                    1
#define E_INT2                    2



void E_Interrupt_voidInit(u8 Copy_u8IntID	,u8 Copy_u8SenseControl	);
void E_Interrupt_voidChangeSenseControl(u8 Copy_u8IntID	,u8 Copy_u8SenseControl);

void E_Interrupt_EnablePIE(u8 Copy_u8IntID);

void E_Interrupt_DisablePIE(u8 Copy_u8IntID);

void E_InterruptSetCallBack(u8 Copy_u8IntID,void (*PF)(void));



#endif /* MCAL_E_INTERRUPT_E_INTERRUPT_INTERFACE_H_ */

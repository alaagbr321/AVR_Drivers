/*
 * main.c
 *
 *  Created on: Aug 6, 2023
 *      Author: WIN10
 */
#define F_CPU		8000000UL
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/DIO/DIO_Interface.h"
#include  "HAL/LED/LED_Interface.h"
#include <util/delay.h>
#include "Hal/SSD/SSD_Interface.h"
#include "HAl/CLCD/CLCD_Interface.h"
#include "HAL/KPAD/KPAD_Interface.h"
#include "HAL/Stepper/Stepper_Interface.h"
#include "MCAL/E_Interrupt/E_Interrupt_Interface.h"
#include  "MCAL/GIE/GIE_Interface.h"
#include  "MCAL/ADC/ADC_Interface.h"
#include "MCAL/TIMERS/TIMERS_Interface.h"
#include "MCAL/Timer1/TIMER1_Interface.h"
#include "HAL/Servo/Servo_interface.h"
#include "MCAL/WDT/WDT_Interface.h"
#include "MCAL/UART/UART_Interface.h"
//#include "MCAL/USART/USART_INTERFACE.h"
#include "MCAL/TWI/TWI_interface.h"
//#include "HAL/EEPROM/EEPROM_interface.h"

int main(void)
{

//
CLCD_voidInit();

DIO_voidSetPortDirection(DIO_PORTA,DIO_OUTPUT);
DIO_voidSetPortDirection(DIO_PORTC,DIO_OUTPUT);

TWI_voidMasterInit(1);
//TWI_voidSlaveInit();


u8 data2;

while(1)
{

	EEPROM_voidSendDataByte(0,232);
//	 DIO_voidSetPinValue(DIO_PORTC,DIO_PIN2,DIO_HIGH);
	EEPROM_voidReadDataByte(0,&data2);
	//DIO_voidSetPinValue(DIO_PORTC,DIO_PIN1,DIO_HIGH);
	CLCD_voidSendNumber(data2,1,1);

	//CLCD_voidSendData(data2);

	if(data2==12)
	{
		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN3,DIO_HIGH);

	}


}


return 0 ;
}












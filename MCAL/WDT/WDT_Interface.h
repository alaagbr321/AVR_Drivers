/*
 * WDT_Interface.h
 *
 *  Created on: Aug 19, 2023
 *      Author: WIN10
 */

#ifndef MCAL_WDT_WDT_INTERFACE_H_
#define MCAL_WDT_WDT_INTERFACE_H_

typedef enum
{
	WDT_16k_16_3ms,
	WDT_32k_32_5ms,
	WDT_64k_65_3ms,
	WDT_128k_130ms,
	WDT_256k_260ms,
	WDT_512k_520ms,
	WDT_1024k_1000ms,
	WDT_2048k_2100ms,

}WDT_Prescaler;
void WDT_voidEnable(WDT_Prescaler Copy_u8Prescaler);
void WDT_voidDisable();


#endif /* MCAL_WDT_WDT_INTERFACE_H_ */

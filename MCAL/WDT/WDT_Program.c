/*
 * WDT_Program.c
 *
 *  Created on: Aug 19, 2023
 *      Author: WIN10
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include"WDT_Interface.h"
#include"WDT_Private.h"



void WDT_voidEnable(WDT_Prescaler Copy_u8Prescaler)
{

	WDTCR_REG &=0xf8;
	WDTCR_REG|=Copy_u8Prescaler;

	SET_BIT(WDTCR_REG,3);


}
void WDT_voidDisable()
{

	WDTCR_REG=(2<<3);


}

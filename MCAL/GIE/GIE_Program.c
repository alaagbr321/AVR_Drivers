/*
 * GIE_Program.c
 *
 *  Created on: Aug 12, 2023
 *      Author: WIN10
 */



/*
 * GIE_Interface.c
 *
 *  Created on: Aug 12, 2023
 *      Author: WIN10
 */

#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/DIO/DIO_Interface.h"


#include "GIE_Interface.h"
#include "GIE_Private.h"



void GIE_voidEnable()
{

	SET_BIT(SREG_REG,7);

}
void GIE_voidDisable()
{
	CLR_BIT(SREG_REG,7);



}

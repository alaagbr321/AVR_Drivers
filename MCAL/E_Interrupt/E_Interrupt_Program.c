/*
 * E_Interrupt_Program.c
 *
 *  Created on: Aug 12, 2023
 *      Author: WIN10
 */


#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/DIO/DIO_Interface.h"

#include "E_Interrupt_Interface.h"
#include "E_Interrupt_Config.h"
#include "E_Interrupt_Private.h"

static void (*PF_Notification[3]) (void) = {NULL,NULL,NULL};

void __vector_1(void) __attribute__((signal));

void E_Interrupt_voidInit(u8 Copy_u8IntID	,u8 Copy_u8SenseControl	)
{
	switch (Copy_u8IntID)
	{

	case E_INT0:

		switch(Copy_u8SenseControl)
		{
		case E_Interrupt_FallingEdge:
			SET_BIT(MCUCR_REG,1);
			CLR_BIT(MCUCR_REG,0);

			break;

		case E_Interrupt_RisingEdge:
			SET_BIT(MCUCR_REG,1);
			SET_BIT(MCUCR_REG,0);

			break;

		case E_Interrupt_OnChange:
			SET_BIT(MCUCR_REG,0);
			CLR_BIT(MCUCR_REG,1);
			break;

		case E_Interrupt_LowLevel:
			CLR_BIT(MCUCR_REG,1);
			CLR_BIT(MCUCR_REG,0);

			break;
		}



		break;

		case E_INT1:
			switch(Copy_u8SenseControl){
			case E_Interrupt_FallingEdge:
				SET_BIT(MCUCR_REG,3);
				CLR_BIT(MCUCR_REG,2);

				break;

			case E_Interrupt_RisingEdge:
				SET_BIT(MCUCR_REG,3);
				SET_BIT(MCUCR_REG,2);

				break;

			case E_Interrupt_OnChange:
				SET_BIT(MCUCR_REG,2);
				CLR_BIT(MCUCR_REG,3);
				break;

			case E_Interrupt_LowLevel:
				CLR_BIT(MCUCR_REG,3);
				CLR_BIT(MCUCR_REG,2);

				break;
			}

			break;


			case E_INT2:
				switch(Copy_u8SenseControl){
				case E_Interrupt_FallingEdge:
					CLR_BIT(MCUCSR_REG,6);
					break;

				case E_Interrupt_RisingEdge:
					SET_BIT(MCUCSR_REG,6);
					break;
				}

				break;
	}

}

void E_Interrupt_EnablePIE(u8 Copy_u8IntID)
{
	switch(Copy_u8IntID)
	{


	case E_INT0:
		SET_BIT(GICR_REG,6);
		break;

	case E_INT1:
		SET_BIT(GICR_REG,7);
		break;

	case E_INT2:
		SET_BIT(GICR_REG,5);
		break;

	}

}

void E_Interrupt_DisablePIE(u8 Copy_u8IntID)
{
	switch(Copy_u8IntID)
	{


	case E_INT0:
		CLR_BIT(GICR_REG,6);
		break;

	case E_INT1:
		CLR_BIT(GICR_REG,7);
		break;

	case E_INT2:
		CLR_BIT(GICR_REG,5);
		break;

	}
}

void E_InterruptSetCallBack(u8 Copy_u8IntID,void (*PF)(void))
{


switch(Copy_u8IntID)
{

case E_INT0:


	if(PF!=NULL)
	{
		PF_Notification[0]=PF;
	}
	break;

case E_INT1:
	if(PF!=NULL)
	{
		PF_Notification[1]=PF;
	}

	break;

case E_INT2:

	if(PF!=NULL)
	{
		PF_Notification[2]=PF;
	}

	break;
}

}



void __vector_1(void)
{

	if(PF_Notification[0]!=NULL)
	{

		PF_Notification[0]();

	}

}

void __vector_2(void)
{

	if(PF_Notification[1]!=NULL)
	{

		PF_Notification[1]();

	}

}


void __vector_3(void)
{

	if(PF_Notification[2]!=NULL)
	{

		PF_Notification[2]();

	}

}

void E_Interrupt_voidChangeSenseControl(u8 Copy_u8IntId , u8 Copy_u8SenseControl)
{
	switch(Copy_u8IntId)
	{
	case E_INT0:
		switch(Copy_u8SenseControl)
		{
		case E_Interrupt_RisingEdge:
			SET_BIT(MCUCR_REG , 1 );
			SET_BIT(MCUCR_REG , 0 );
			break;

		case E_Interrupt_FallingEdge:
			SET_BIT(MCUCR_REG , 1 );
			CLR_BIT(MCUCR_REG , 0 );

			break;

		case E_Interrupt_OnChange:
			CLR_BIT(MCUCR_REG , 1 );
			SET_BIT(MCUCR_REG , 0 );
			break;


		case E_Interrupt_LowLevel:
			CLR_BIT(MCUCR_REG , 1 );
			CLR_BIT(MCUCR_REG , 0 );
			break;
		default:
			break;
		}
		break;

		case E_INT1:
			switch(Copy_u8SenseControl)
			{
			case E_Interrupt_RisingEdge:
				SET_BIT(MCUCR_REG , 3 );
				SET_BIT(MCUCR_REG , 2 );
				break;

			case E_Interrupt_FallingEdge:
				SET_BIT(MCUCR_REG , 3 );
				CLR_BIT(MCUCR_REG , 2 );
				break;

			case E_Interrupt_OnChange:
				CLR_BIT(MCUCR_REG , 3 );
				SET_BIT(MCUCR_REG , 2 );

				break;

			case E_Interrupt_LowLevel:
				CLR_BIT(MCUCR_REG , 3 );
				CLR_BIT(MCUCR_REG , 2 );
				break;
			default:
				break;
			}
			break;

			case E_INT2:
				switch(Copy_u8SenseControl)
				{
				case E_Interrupt_RisingEdge:
					SET_BIT(MCUCSR_REG , 6);
					break;

				case E_Interrupt_FallingEdge:
					CLR_BIT(MCUCSR_REG , 6);

					break;

				default:
					break;
				}
				break;
				default:
					break;
	}
}

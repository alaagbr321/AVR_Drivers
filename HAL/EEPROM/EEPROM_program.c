/**********************************************************/
/* !Author      : Abdullah M. Abdullah                    */
/* !Description :                                         */
/* !Version     : v1.0                                    */
/* !Date        : 10 DEC, 2021                            */
/**********************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/TWI/TWI_interface.h"

#define F_CPU   8000000UL
#include <util/delay.h>

#include "../EEPROM/EEPROM_interface.h"
#include "../EEPROM/EEPROM_private.h"
#include "../EEPROM/EEPROM_config.h"
#include "../../MCAL/DIO/DIO_Interface.h"


void EEPROM_voidSendDataByte(u8 Copy_u16LocationAddress, u8 Copy_u8DataByte)
{

    /*Send Start Condition*/
    TWI_ErrorStatusSendStartConditionWithACK();
    DIO_voidSetPinValue(DIO_PORTC,DIO_PIN2,DIO_HIGH);
    /*Send Slave Address With Write Request*/
    TWI_ErrorStatusSendSlaveAddressWithWriteACK(0b01010010);

    /*Send The Rest Of Byte Address (b7-b0)*/
    TWI_ErrorStatusMasterWriteDataByteWithACK(Copy_u16LocationAddress);
    /*Send Data*/
    TWI_ErrorStatusMasterWriteDataByteWithACK(Copy_u8DataByte);

    /*Send Stop Condition*/
    TWI_voidStopCondition();

    /*Delay for 5msec*/
    _delay_ms(20);
}


void EEPROM_voidReadDataByte(u8 Copy_u16LocationAddress, u8 * Copy_pu8ReceivedData)
{

    /*Send Start Condition*/
    TWI_ErrorStatusSendStartConditionWithACK();
    /*Send Slave Address With Write Request*/
    TWI_ErrorStatusSendSlaveAddressWithWriteACK(0b01010010);
    /*Send The Rest Of Byte Address (b7-b0)*/
    TWI_ErrorStatusMasterWriteDataByteWithACK(Copy_u16LocationAddress);
    /*Send Repeated Start Condition*/
    TWI_ErrorStatusSendRepeatedStartConditionWithACK();
    /*Send Slave Address With Read Request*/
    TWI_ErrorStatusSendSlaveAddressWithReadACK(0b01010010);
    /*Read Data From The SDA Bus*/
    TWI_ErrorStatusMasterReadDataByteWithACK(Copy_pu8ReceivedData);
    /*Send Stop Condition*/
    TWI_voidStopCondition();
}

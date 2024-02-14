/*
 * main.c
 *
 *  Created on: Feb 14, 2024
 *      Author: bagiz
 */

#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "UltraSonic_interface.h"
#include "CLCD_interface.h"
#include <util/delay.h>





void main(void)
{
	PORT_voidInit();
	CLCD_voidInit();


	uint8 Distance=0;
	while(1)
	{

		Distance=UltraSonicDistance(DIO_u8PORTC,DIO_u8PIN0);
		CLCD_voidSendStringPos(1,1,"Distance = ");
		CLCD_voidDisplayNumberPos(1,12,Distance);
		CLCD_voidSendString(" Cm ");

		if(5 >= Distance)
		{
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_HIGH);
			CLCD_voidSendStringPos(2,1,"High Risk Dist");
		}
		else if((5 < Distance) && (Distance <= 8))
		{
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_HIGH);
			_delay_ms(50);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_LOW);
			CLCD_voidSendStringPos(2,1,"Short Distance");

	//		_delay_ms(10);
		}
		else if((8 < Distance) && (Distance <= 12))
		{
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_LOW);
			_delay_ms(50);
			CLCD_voidSendStringPos(2,1,"Be Careful          ");

		}
		else if((12 < Distance) && (Distance <= 15))
		{
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_HIGH);
			_delay_ms(100);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_LOW);
			_delay_ms(200);
			CLCD_voidSendStringPos(2,1,"Be Careful          ");

		}
		else if((15 < Distance) && (Distance <= 20))
		{
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_HIGH);
			_delay_ms(50);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_LOW);
			_delay_ms(500);
			CLCD_voidSendStringPos(2,1,"Be Careful          ");

		}
		else
		{
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_LOW);
			CLCD_voidSendStringPos(2,1,"NO Risk            ");

		}


	}
}



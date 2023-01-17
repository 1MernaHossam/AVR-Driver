/*
 * KEYPAD.c
 *
 *  Created on: Dec 16, 2022
 *      Author: Lenovo
 */
#include "STD_Types.h"
#include "BIT_Math.h"
#include<util/delay.h>
#include "DIO.h"
#include "KEYPAD_cfg.h"
#include "KEYPAD_priv.h"
#include "KEYPAD.h"
#if 0
void KEYPAD_voidInit(void)
{
	uint8 u8CntrLoc ;
	uint8 u8InputCntrLoc ;
	uint8 u8OutputCntrLoc ;
	/* loop on all cfg keypads*/
	for (u8CntrLoc = 0 ; u8CntrLoc < KEYPAD_MAX_NUM ; u8CntrLoc++)
	{
		/* all inputs activate pull up resistor     */
		for (u8InputCntrLoc = 0 ; u8InputCntrLoc < KEYPAD_astrConfigSet[u8CntrLoc].u8InputPinsNum; u8InputCntrLoc++)
		{
			DIO_enuStatePullup(KEYPAD_astrConfigSet[u8CntrLoc].au8InputPins[u8InputCntrLoc],DIO_ACTIVATE);
		}

		/* all output seq ones no switch under test */
		for (u8OutputCntrLoc = 0 ; u8OutputCntrLoc < KEYPAD_astrConfigSet[u8CntrLoc].u8OutputPinsNum; u8OutputCntrLoc++)
		{
			DIO_enuWritePin(KEYPAD_astrConfigSet[u8CntrLoc].au8OutputPins[u8OutputCntrLoc], DIO_HIGH);
		}

	}

}
uint8 KEYPAD_u8GetPressedKey(uint8 u8KeyPadIdxCpy)
{
	uint8  u8SeqCntrLoc ;
	uint16 u16InputReadingLoc ;
	uint8  u8ReturnKeyLoc = 0xFF ;
	for (u8SeqCntrLoc = 0 ; u8SeqCntrLoc < KEYPAD_astrConfigSet[u8KeyPadIdxCpy].u8OutputPinsNum; u8SeqCntrLoc++)
	{

		/* seq u8SeqCntrLoc*/
		voidWriteSeq(u8KeyPadIdxCpy ,u8SeqCntrLoc);
		/*delay*/
		_delay_ms(50);
		/*Read inputs*/
		u16InputReadingLoc = u16ReadInputs(u8KeyPadIdxCpy);
		//check break ;FF
		u8ReturnKeyLoc = u8CheckReading(u8KeyPadIdxCpy, u8SeqCntrLoc,u16InputReadingLoc);
		if(u8ReturnKeyLoc != 0xFF)
		{
			break;
		}

	}

	return u8ReturnKeyLoc ;


}


static void voidWriteSeq(uint8 u8KeyPadIdxCpy , uint8 u8SeqIdxCpy)
{
	uint8 u8CntrLoc  ;
	for (u8CntrLoc = 0 ; u8CntrLoc < KEYPAD_astrConfigSet[u8KeyPadIdxCpy].u8OutputPinsNum; u8CntrLoc++)
	{
		if (u8CntrLoc == u8SeqIdxCpy)
		{
			DIO_enuWritePin(KEYPAD_astrConfigSet[u8KeyPadIdxCpy].au8OutputPins[u8CntrLoc], DIO_LOW);
		}
		else
		{
			DIO_enuWritePin(KEYPAD_astrConfigSet[u8KeyPadIdxCpy].au8OutputPins[u8CntrLoc], DIO_HIGH);
		}

	}


}


static uint16 u16ReadInputs(uint8 u8KeyPadIdxCpy)
{
	uint16 u16ReturnReadingLoc = 0xFFFF ;
	uint8  u8InputCntrLoc             ;
	uint8  u8TempReadingLoc  =     0  ;
	for (u8InputCntrLoc = 0 ; u8InputCntrLoc < KEYPAD_astrConfigSet[u8KeyPadIdxCpy].u8InputPinsNum; u8InputCntrLoc++)
	{
		DIO_enuReadPin(KEYPAD_astrConfigSet[u8KeyPadIdxCpy].au8InputPins[u8InputCntrLoc],&u8TempReadingLoc);
		if (u8TempReadingLoc == 0)
		{
			CLR_BIT(u16ReturnReadingLoc , u8InputCntrLoc );
			break ;
		}

	}
	return u16ReturnReadingLoc ;

}


static uint8 u8CheckReading(uint8 u8KeyPadIdxCpy , uint8 u8SeqIdxCpy, uint16 u16InputReadingCpy )
{
	uint8 u8ReturnKeyLoc ;
	uint8 u8InputCntrLoc ;
	uint8 u8InputBitLoc  ;

	if (u16InputReadingCpy == 0xFFFF)
	{
		u8ReturnKeyLoc = 0xFF ;
	}
	else
	{
		for (u8InputCntrLoc = 0 ; u8InputCntrLoc < KEYPAD_astrConfigSet[u8KeyPadIdxCpy].u8InputPinsNum; u8InputCntrLoc++)
		{
			u8InputBitLoc =  GET_BIT(u16InputReadingCpy ,u8InputCntrLoc );
			if (u8InputBitLoc == 0)
			{
				// input  --> u8InputCntrLoc  output   --> u8SeqIdxCpy

				u8ReturnKeyLoc = KEYPAD_au8Mapping[u8KeyPadIdxCpy][u8SeqIdxCpy][u8InputCntrLoc] ;
				break ;
			}

		}


	}
	return u8ReturnKeyLoc ;
}
#endif

void KEYPAD_voidInit(void)
{
	uint8 u8CntrLoc ,u8InputCntrLoc,u8OutputCntrLoc;
	/*loop on all cfg config keypad  */
	for(u8CntrLoc=0;u8CntrLoc<KEYPAD_MAX_NUM;u8CntrLoc++)
	{
		for(u8InputCntrLoc=0;u8InputCntrLoc<KEYPAD_astrConfigSet[u8CntrLoc].u8InputPinsNum;u8InputCntrLoc++)
		{
			/*all inputs activate pullup resistor*/
			DIO_enuStatePullup(KEYPAD_astrConfigSet[u8CntrLoc].au8InputPins[u8InputCntrLoc],DIO_ACTIVATE);

		}
		for(u8OutputCntrLoc=0;u8OutputCntrLoc<KEYPAD_astrConfigSet[u8CntrLoc].u8OutputPinsNum;u8OutputCntrLoc++)
		{
			/*all output sequence ones no of switch under test */
			DIO_enuWritePin(KEYPAD_astrConfigSet[u8CntrLoc].au8OutputPins[u8OutputCntrLoc], DIO_HIGH);

		}
	}

}

uint8 KEYPAD_u8GetPressedKey(uint8 u8KeypadIdxCpy)
{
	uint8 u8SeqCntrLoc ;
	uint16 u16InputReadLoc;
	uint8 u8ReturnKeyLoc;
	/*seq 0 ,delay,read inputs,break*/
	/*seq 1 ,delay,read inputs,break*/
	for(u8SeqCntrLoc=0;u8SeqCntrLoc<KEYPAD_astrConfigSet[u8KeypadIdxCpy].u8OutputPinsNum;u8SeqCntrLoc++)
	{
		/*seq u8seqcntrlock*/
		voidWriteSeq(u8KeypadIdxCpy,u8SeqCntrLoc);
		/*delay*/
		_delay_ms(50);
		/*read inputs*/
		u16InputReadLoc=u16ReadInputs(u8KeypadIdxCpy);
		/*check reading ,break; ff*/
		u8ReturnKeyLoc=u8CheckReading(u8KeypadIdxCpy,u8SeqCntrLoc,u16InputReadLoc);
		if(u8ReturnKeyLoc !=0xFF)
		{
			break;
		}
	}
	return u8ReturnKeyLoc;
}

static void voidWriteSeq(uint8 u8KeypadIdxCpy,uint8 u8SeqIdxCpy)
{
	uint8 u8SeqCntrLoc;
	/*put in all ones(high) except u8SeqIdxCpy is zero(low)*/
	for(u8SeqCntrLoc=0;u8SeqCntrLoc<KEYPAD_astrConfigSet[u8KeypadIdxCpy].u8OutputPinsNum;u8SeqCntrLoc++)
	{

		if (u8SeqCntrLoc==u8SeqIdxCpy)
		{
			DIO_enuWritePin(KEYPAD_astrConfigSet[u8KeypadIdxCpy].au8OutputPins[u8SeqCntrLoc],DIO_LOW);
		}
		else
		{
			DIO_enuWritePin(KEYPAD_astrConfigSet[u8KeypadIdxCpy].au8OutputPins[u8SeqCntrLoc],DIO_HIGH);

		}

	}
}
static uint16 u16ReadInputs(uint8 u8KeypadIdxCpy)
{
	uint16 u16ReturnReadingLoc=0xFFFF;
	uint8 u8TempReadingLoc=0;
	uint8 u8InputCntrLoc;

	/*read from pins ,read one or zero
	 * if reading is zero put low
	 * if reading is one put high
	 * in state no press ,reading ff
	 * in state pressed ,at least one of them is zero
	 * finally return reading*/
	for(u8InputCntrLoc=0;u8InputCntrLoc<KEYPAD_astrConfigSet[u8KeypadIdxCpy].u8InputPinsNum;u8InputCntrLoc++)
	{
		DIO_enuReadPin(KEYPAD_astrConfigSet[u8KeypadIdxCpy].au8InputPins[u8InputCntrLoc],&u8TempReadingLoc);
		if(u8TempReadingLoc==0)
		{
			CLR_BIT(u16ReturnReadingLoc,u8InputCntrLoc);
			break;
		}
	}
	return u16ReturnReadingLoc;

}
static uint8 u8CheckReading(uint8 u8KeypadIdxCpy,uint8 u8SeqIdxCpy,uint16 u16InputReadingCpy)
{
	uint8 u8ReturnKeyLoc;
	uint8 u8InputCntrLoc;
	uint8 u8InputBitLoc;

	if(u16InputReadingCpy==0xFFFF)
	{
		u8ReturnKeyLoc=0xFF;
	}
	else
	{
		for(u8InputCntrLoc=0;u8InputCntrLoc<KEYPAD_astrConfigSet[u8KeypadIdxCpy].u8InputPinsNum;u8InputCntrLoc++)
		{
			u8InputBitLoc=GET_BIT(u16InputReadingCpy,u8InputCntrLoc);
			if(u8InputBitLoc==0)
			{
				// input ---> u8InputCntrLoc ,output -->u8SeqIdxCpy
				u8ReturnKeyLoc=KEYPAD_au8Mapping[u8KeypadIdxCpy][u8SeqIdxCpy][u8InputCntrLoc];
				break;
			}
		}

	}
	return u8ReturnKeyLoc;
}


#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO.h"
#include "GIE.h"
#include "TIM1.h"
#include "TIM1_cfg.h"
#include "TIM1_priv.h"


/*MAIN FOR OVERFLOW* /
 *
 */
void LED_Toggle(void);

void One_Sec(void);
void One_milli_Sec(void);
void Tim1_ISR(void)
{
	static uint8 u8CNTRLoc=0;
	if(u8CNTRLoc==0)
	{
		DIO_enuWritePin(DIO_PIN_NUM_0,DIO_HIGH);
		u8CNTRLoc=1;
	}
	else
	{
		DIO_enuWritePin(DIO_PIN_NUM_0,DIO_LOW);
		u8CNTRLoc=0;
	}

}
void main (void)
{

	DIO_voidInit();
	TIM1_voidInit();
	//PRESCALER =8
	TIM1_voidEnable(2);
	TIM1_voidSetSetCallBackOvfInt(LED_Toggle);
	/*to start count again*/
	TIM1_voidSetTimerValue(192);
	TIM1_voidEnableOvfInt();
	GIE_voidEnable();


	while(1)
	{


	}
}
void One_Sec(void)
{
	static uint16 u16FlagLoc=0;
	u16FlagLoc++;
	if(u16FlagLoc==3907)
	{
		u16FlagLoc=0;
		TIM1_voidSetTimerValue(192);
		//action
		Tim1_ISR();
	}

}
void One_milli_Sec(void)
{
	static uint8 u8FlagLoc=0;
	u8FlagLoc++;
	if(u8FlagLoc==4)
	{
		u8FlagLoc=0;
		TIM1_voidSetTimerValue(24);
		//action
		//Tim0_ISR();
	}

}
void LED_Toggle(void)
{
	static uint16 Local_u16Counter = 0;
	static uint8 Local_u8LedState = 0;
	Local_u16Counter++;
	if(Local_u16Counter==5)
	{
		/*Timer0_voidSetPreload(192);*/
		/*Toggle the LED*/
		TOG_BIT(Local_u8LedState,0);
		DIO_enuWritePin(DIO_PIN_NUM_1,Local_u8LedState);

		Local_u16Counter = 0;
	}
}

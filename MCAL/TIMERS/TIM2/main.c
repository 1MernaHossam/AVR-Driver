
#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO.h"
#include "GIE.h"
#include "TIM2.h"
#include "TIM2_cfg.h"
#include "TIM2_priv.h"

/*MAIN FOR OVERFLOW* /
 *
 */
void One_Sec(void);
void One_milli_Sec(void);
void Tim2_ISR(void)
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
	TIM2_voidInit();
	//PRESCALER =8
	TIM2_voidEnable(2);
	TIM2_voidSetSetCallBackOvfInt(One_Sec);
	/*to start count again*/
	TIM2_voidSetTimerValue(192);
	TIM2_voidEnableOvfInt();
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
		TIM2_voidSetTimerValue(192);
		//action
		Tim2_ISR();
	}

}
void One_milli_Sec(void)
{
	static uint8 u8FlagLoc=0;
	u8FlagLoc++;
	if(u8FlagLoc==4)
	{
		u8FlagLoc=0;
		TIM2_voidSetTimerValue(24);
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

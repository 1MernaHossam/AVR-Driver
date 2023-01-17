/**************************************/
/* Description : TIM0 c File          */
/* Author      : Lenovo               */
/* Version     : 0.1V                 */
/* Date        : 09:35:33  06 Jan 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/

#include "STD_Types.h"
#include "BIT_Math.h"
#include "TIM0.h"
#include "TIM0_cfg.h"
#include "TIM0_priv.h"

/*pf TIM0_pfOvfCallBck;
pf TIM0_pfCmpCallBck;
*/
pf  TIM0_pfOvfCallBack;
pf  TIM0_pfCmpCallBack;
void TIM0_voidInit(void)
{
	
#if   TIM0_MODE  ==    TIM0_NORMAL
	CLR_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);
#elif   TIM0_MODE  ==   TIM0_CTC
	CLR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
#elif   TIM0_MODE  ==  TIM0_PWM
	SET_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);
#else
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
#endif
	

#if   TIM0_OUTFORM == TIM0_TOGL_OC0
    SET_BIT(TCCR0 , 4);
	CLR_BIT(TCCR0 , 5);
#elif TIM0_OUTFORM == TIM0_SET_OC0
    SET_BIT(TCCR0 , 4);
	SET_BIT(TCCR0 , 5);
#elif TIM0_OUTFORM == TIM0_CLR_OC0
    CLR_BIT(TCCR0 , 4);
	SET_BIT(TCCR0 , 5);
#elif TIM0_OUTFORM == TIM0_F_NON_INVERT
    CLR_BIT(TCCR0 , 4);
	SET_BIT(TCCR0 , 5);
#elif TIM0_OUTFORM == TIM0_F_INVERT
    SET_BIT(TCCR0 , 4);
	SET_BIT(TCCR0 , 5);
#elif TIM0_OUTFORM == TIM0_PH_NON_INVERT
    CLR_BIT(TCCR0 , 4);
	SET_BIT(TCCR0 , 5);
#elif TIM0_OUTFORM == TIM0_PH_INVERT
    SET_BIT(TCCR0 , 4);
	SET_BIT(TCCR0 , 5);
#else
	CLR_BIT(TCCR0 , 4);
	CLR_BIT(TCCR0 , 5);
#endif
	/*DISABLE TIMER */
	TCCR0 &= 0b11111000;
	/*DISABLE INTERRUPT OVF*/
	CLR_BIT(TIMSK,0);
	/*DISABLE INTERRUPT CMP*/
	CLR_BIT(TIMSK,1);
	/*CLR FLAG OVF__WRITE 1*/
	SET_BIT(TIFR,0);
	/*CLR FLAG CMP___ WRITE 1*/
	SET_BIT(TIFR,1);
	/*CLEAR TCNT*/
	TCNT0=0;
	OCR0=0;
}

/*set value of prescaler*/
void TIM0_voidEnable(uint8 u8SpeedValCpy)
{
	//change in  first 3 bits in lsb to change in prescaler
	//masking 
	TCCR0 &= 0b11111000;
	/*& 0b00000111 if usr give a value over  7 
	not make a problem*/
	TCCR0 |= u8SpeedValCpy & 0b00000111;

}

/*clr value of prescaler*/

void TIM0_voidDisable(void)
{ 
	TCCR0 &= 0b11111000;
}
void TIM0_voidEnableOvfInt(void)
{ 
	SET_BIT(TIMSK ,0);
}
void TIM0_voidDisableOvfInt(void)
{ 
	CLR_BIT(TIMSK ,0);

}
void TIM0_voidEnableCmpInt(void)
{
	SET_BIT(TIMSK ,1);
}
void TIM0_voidDisableCmpInt(void)
{
	CLR_BIT(TIMSK ,1);

}

void TIM0_voidSetCmpRegValue(uint8 u8CmpValCpy)
{
	OCR0=u8CmpValCpy;

}

void TIM0_voidSetSetCallBackOvfInt(pf pfCallbackCpy)
{ 
	TIM0_pfOvfCallBack = pfCallbackCpy;

}

void TIM0_voidSetSetCallBackCmpInt(pf pfCallbackCpy)
{ 
	TIM0_pfCmpCallBack = pfCallbackCpy;
}
void TIM0_voidSetTimerValue(uint8 u8TimValCpy)
{ 
	TCNT0=u8TimValCpy;
}
uint8 TIM0_voidReadTimerValue(void)
{
	return TCNT0;
}
/*TIMER0 OVERFLOW 10
 * 10-1=9*/
void __vector_11 (void) __attribute__((signal ,used));
//told compiler it is signal that not deleted if not used
//talk to linker through compiler



/*TIMER0 ISR OV*/
void __vector_11 (void)
{
	TIM0_pfOvfCallBack();

}
/*TIMER0 CTC 11
 * 11-1=10*/
void __vector_10(void) __attribute__((signal ,used));
//told compiler it is signal that not deleted if not used
//talk to linker through compiler



/*TIMER0 ISR CTC*/

void __vector_10 (void)
{
	TIM0_pfCmpCallBack();

}

/**************************************/
/* Description : TIM2 c File          */
/* Author      : Lenovo               */
/* Version     : 0.1V                 */
/* Date        : 04:53:04  17 Jan 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/

#include "STD_Types.h"
#include "BIT_Math.h"
#include "TIM2.h"
#include "TIM2_cfg.h"
#include "TIM2_priv.h"

/*pf TIM2_pfOvfCallBck;
pf TIM2_pfCmpCallBck;
*/
pf  TIM2_pfOvfCallBack;
pf  TIM2_pfCmpCallBack;
void TIM2_voidInit(void)
{

#if   TIM2_MODE  ==    TIM2_NORMAL
	CLR_BIT(TCCR2,6);
	CLR_BIT(TCCR2,3);
#elif   TIM2_MODE  ==   TIM2_CTC
	CLR_BIT(TCCR2,6);
	SET_BIT(TCCR2,3);
#elif   TIM2_MODE  ==  TIM2_PWM
	SET_BIT(TCCR2,6);
	CLR_BIT(TCCR2,3);
#else
	SET_BIT(TCCR2,6);
	SET_BIT(TCCR2,3);
#endif


#if   TIM2_OUTFORM == TIM2_TOGL_OC0
    SET_BIT(TCCR2 , 4);
	CLR_BIT(TCCR2 , 5);
#elif TIM2_OUTFORM == TIM2_SET_OC0
    SET_BIT(TCCR2 , 4);
	SET_BIT(TCCR2 , 5);
#elif TIM2_OUTFORM == TIM2_CLR_OC0
    CLR_BIT(TCCR2 , 4);
	SET_BIT(TCCR2 , 5);
#elif TIM2_OUTFORM == TIM2_F_NON_INVERT
    CLR_BIT(TCCR2 , 4);
	SET_BIT(TCCR2 , 5);
#elif TIM2_OUTFORM == TIM2_F_INVERT
    SET_BIT(TCCR2 , 4);
	SET_BIT(TCCR2 , 5);
#elif TIM2_OUTFORM == TIM2_PH_NON_INVERT
    CLR_BIT(TCCR2 , 4);
	SET_BIT(TCCR2 , 5);
#elif TIM2_OUTFORM == TIM2_PH_INVERT
    SET_BIT(TCCR2 , 4);
	SET_BIT(TCCR2 , 5);
#else
	CLR_BIT(TCCR2 , 4);
	CLR_BIT(TCCR2 , 5);
#endif
	/*DISABLE TIMER */
	TCCR2 &= 0b11111000;
	/*DISABLE INTERRUPT OVF*/
	CLR_BIT(TIMSK,6);
	/*DISABLE INTERRUPT CMP*/
	CLR_BIT(TIMSK,7);
	/*CLR FLAG OVF__WRITE 1*/
	SET_BIT(TIFR,6);
	/*CLR FLAG CMP___ WRITE 1*/
	SET_BIT(TIFR,7);
	/*CLEAR TCNT*/
	TCNT2=0;
	OCR2=0;
}

/*set value of prescaler*/
void TIM2_voidEnable(uint8 u8SpeedValCpy)
{
	//change in  first 3 bits in lsb to change in prescaler
	//masking
	TCCR2 &= 0b11111000;
	/*& 0b00000111 if usr give a value over  7
	not make a problem*/
	TCCR2 |= u8SpeedValCpy & 0b00000111;

}

/*clr value of prescaler*/

void TIM2_voidDisable(void)
{
	TCCR2 &= 0b11111000;
}
void TIM2_voidEnableOvfInt(void)
{
	SET_BIT(TIMSK ,6);
}
void TIM2_voidDisableOvfInt(void)
{
	CLR_BIT(TIMSK ,6);

}
void TIM2_voidEnableCmpInt(void)
{
	SET_BIT(TIMSK ,7);
}
void TIM2_voidDisableCmpInt(void)
{
	CLR_BIT(TIMSK ,7);

}

void TIM2_voidSetCmpRegValue(uint8 u8CmpValCpy)
{
	OCR2=u8CmpValCpy;

}

void TIM2_voidSetSetCallBackOvfInt(pf pfCallbackCpy)
{
	TIM2_pfOvfCallBack = pfCallbackCpy;

}

void TIM2_voidSetSetCallBackCmpInt(pf pfCallbackCpy)
{
	TIM2_pfCmpCallBack = pfCallbackCpy;
}
void TIM2_voidSetTimerValue(uint8 u8TimValCpy)
{
	TCNT2=u8TimValCpy;
}
uint8 TIM2_voidReadTimerValue(void)
{
	return TCNT2;
}
/*TIMER2 OVERFLOW 6
 * 6-1=5*/
void __vector_5 (void) __attribute__((signal ,used));
//told compiler it is signal that not deleted if not used
//talk to linker through compiler



/*TIMER0 ISR OV*/
void __vector_5 (void)
{
	TIM2_pfOvfCallBack();

}
/*TIMER0 CTC 5
 * 5-1=4*/
void __vector_4(void) __attribute__((signal ,used));
//told compiler it is signal that not deleted if not used
//talk to linker through compiler



/*TIMER0 ISR CTC*/

void __vector_4 (void)
{
	TIM2_pfCmpCallBack();

}
/*A FOC2 strobe will not generate any interrupt, nor will it clear the timer in CTC mode using
OCR2 as TOP.
The FOC2 bit is always read as zero.*/
void TIM2_WGM_EnablePWM()
{
	CLR_BIT(TCCR2,7);
}
void TIM2_WGM_DisablePWM()
{
	SET_BIT(TCCR2,7);

}

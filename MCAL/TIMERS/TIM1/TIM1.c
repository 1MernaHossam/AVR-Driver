/**************************************/
/* Description : TIM1 c File          */
/* Author      : Lenovo               */
/* Version     : 0.1V                 */
/* Date        : 23:21:03  12 Jan 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/
#include "STD_Types.h"
#include "BIT_Math.h"
#include "TIM1.h"
#include "TIM1_cfg.h"
#include "TIM1_priv.h"


/*pf TIM1_pfOvfCallBck;
pf TIM1_pfCmpCallBck;
*/
pf  TIM1_pfOvfCallBack;
pf  TIM1_pfCmpCallBack;
pf  TIM1_pfICUCallBack;


void TIM1_voidInit(void)
{
	
#if   TIM0_MODE  ==    TIM1_NORMAL
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
#elif   TIM0_MODE  ==   TIM1_PWM_PHASE_CORRECT_8BIT
	SET_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
#elif   TIM0_MODE  ==  TIM1_PWM_PHASE_CORRECT_9BIT
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
#elif   TIM0_MODE  == TIM1_PWM_PHASE_CORRECT_10BIT
	SET_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
#elif   TIM0_MODE  ==   TIM1_CTC_OCR1A
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
#elif   TIM0_MODE  ==  TIM1_FASTPWM_PHASE_CORRECT_8BIT
	SET_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
#elif   TIM0_MODE  == TIM1_FASTPWM_PHASE_CORRECT_9BIT
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
#elif   TIM0_MODE  ==   TIM1_FASTPWM_PHASE_CORRECT_10BIT
	SET_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
#elif   TIM0_MODE  ==  TIM1_FPWM_PHASE_AND_FREQUENCY_CORRECT_ICR1
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
#elif   TIM0_MODE  == TIM1_PWM_PHASE_AND_FREQUENCY_CORRECT_OCR1A
	SET_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
#elif   TIM0_MODE  == TIM1_PWM_PHASE_CORRECT_ICR1
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
#elif   TIM0_MODE  ==   TIM1_PWM_PHASE_CORRECT_OCR1A
	SET_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
#elif   TIM0_MODE  ==  TIM1_CTC_ICR1
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
#elif   TIM0_MODE  == TIM1_RESERVED
	SET_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
#elif   TIM0_MODE  ==  TIM1_CTC_ICR1
	SET_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
#elif   TIM0_MODE  == TIM1_FAST_PWM_ICR1
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
#elif   TIM0_MODE  == TIM1_FAST_PWM_OCR1A
	SET_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
#endif
}
void TIM1_voidEnable(uint8 u8SpeedValCpy)
{
	//change in  first 3 bits in lsb to change in prescaler
	//masking 
	TCCR1B &= 0b11111000;
	/*& 0b00000111 if usr give a value over  7 
	not make a problem*/
	TCCR1B |= u8SpeedValCpy & 0b00000111;

}
void TIM1_voidDisable(void)
{ 
	TCCR1B &= 0b11111000;
}
void TIM1_voidSetCmpRegValue(uint8 u8CmpValCpy)
{
	OCR1A=u8CmpValCpy;

}
void TIM1_voidSetTimerValue(uint8 u8TimValCpy)
{ 
	TCNT1=u8TimValCpy;
}
uint8 TIM1_voidReadTimerValue(void)
{
	return TCNT1;
}
void TIM1_voidEnableOvfInt(void)
{ 
	SET_BIT(TIMSK ,TIMSK_TOIE1);
}
void TIM1_voidDisableOvfInt(void)
{ 
	CLR_BIT(TIMSK ,TIMSK_TOIE1);

}
void TIM1_voidEnableCmpInt(void)
{
	SET_BIT(TIMSK ,TIMSK_OCIE1A);
}
void TIM1_voidDisableCmpInt(void)
{
	CLR_BIT(TIMSK ,TIMSK_OCIE1A);

}
void TIM1_voidEnableICU(void)
{
	SET_BIT(TIMSK ,TIMSK_TICIE1);
}
void TIM1_voidDisableICU(void)
{
	CLR_BIT(TIMSK ,TIMSK_TICIE1);

}
void TIM1_voidSetSetCallBackOvfInt(pf pfCallbackCpy)
{ 
	TIM1_pfOvfCallBack = pfCallbackCpy;

}
void TIM1_voidSetSetCallBackICUInt(pf pfCallbackCpy)
{ 
	TIM1_pfICUCallBack = pfCallbackCpy;
}
void TIM1_voidSetSetCallBackCmpInt(pf pfCallbackCpy)
{ 
	TIM1_pfCmpCallBack = pfCallbackCpy;
}
/*TIMER1 OVERFLOW 10
 * 10-1=9*/
void __vector_9 (void) __attribute__((signal ,used));
//told compiler it is signal that not deleted if not used
//talk to linker through compiler



/*TIMER1 ISR OV*/
void __vector_9 (void)
{
	TIM1_pfOvfCallBack();

}
/*TIMER1 CTC 8
 * 8-1=7*/
void __vector_7(void) __attribute__((signal ,used));
//told compiler it is signal that not deleted if not used
//talk to linker through compiler



/*TIMER1 ISR CTC*/

void __vector_7 (void)
{
	TIM1_pfCmpCallBack();

}
/*TIMER1 ICU 7
 * 7-1=6*/
void __vector_6(void) __attribute__((signal ,used));
//told compiler it is signal that not deleted if not used
//talk to linker through compiler



/*TIMER1 ICU */

void __vector_6 (void)
{
	TIM1_pfICUCallBack();

}

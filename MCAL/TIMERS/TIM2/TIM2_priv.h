/**************************************/
/* Description : TIM2 private c File  */
/* Author      : Lenovo               */
/* Version     : 0.1V                 */
/* Date        : 04:53:04  17 Jan 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef TIM2_PRIV_H
#define TIM2_PRIV_H





#define TIM2_NORMAL 0
#define TIM2_CTC    1
#define TIM2_PWM    2
#define TIM2_F_PWM  3

#define TIM2_TOGL_OC0 0
#define TIM2_SET_OC0 1
#define TIM2_CLR_OC0 2
//F___FAST
#define TIM2_F_NON_INVERT 3
#define TIM2_F_INVERT 4
//PH___PHASE CORRECT
#define TIM2_PH_NON_INVERT 5
#define TIM2_PH_INVERT 6
#define TIM2_DISCONNECT 7


#define TCCR2 								*((volatile uint8*)0x45)
#define TCNT2 								 *((volatile uint8*)0x44)
#define OCR2        						*((volatile uint8*)0x43)
#define TIMSK        						*((volatile uint8*)0x59)
#define TIFR                                *((volatile uint8*)0x58)


#endif

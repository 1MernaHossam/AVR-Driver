/**************************************/
/* Description : TIM0 private c File  */
/* Author      : Lenovo               */
/* Version     : 0.1V                 */
/* Date        : 09:35:33  06 Jan 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef TIM0_PRIV_H
#define TIM0_PRIV_H

#define TIM0_NORMAL 0
#define TIM0_CTC    1
#define TIM0_PWM    2
#define TIM0_F_PWM  3

#define TIM0_TOGL_OC0 0
#define TIM0_SET_OC0 1
#define TIM0_CLR_OC0 2
//F___FAST
#define TIM0_F_NON_INVERT 3
#define TIM0_F_INVERT 4
//PH___PHASE CORRECT
#define TIM0_PH_NON_INVERT 5
#define TIM0_PH_INVERT 6
#define TIM0_DISCONNECT 7


#define TCCR0 								*((volatile uint8*)0x53)
#define TCNT0 								 *((volatile uint8*)0x52)
#define OCR0        						*((volatile uint8*)0x5C)
#define TIMSK        						*((volatile uint8*)0x59)
#define TIFR        						*((volatile uint8*)0x58)







#endif
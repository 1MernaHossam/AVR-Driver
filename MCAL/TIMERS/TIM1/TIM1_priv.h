/**************************************/
/* Description : TIM1 private c File  */
/* Author      : Lenovo               */
/* Version     : 0.1V                 */
/* Date        : 23:21:03  12 Jan 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef TIM1_PRIV_H
#define TIM1_PRIV_H

#define TIM1_NORMAL 				 0
#define TIM1_PWM_PHASE_CORRECT_8BIT   1
#define TIM1_PWM_PHASE_CORRECT_9BIT   2
#define TIM1_PWM_PHASE_CORRECT_10BIT  3
#define TIM1_CTC_OCR1A   					 4
#define TIM1_FASTPWM_PHASE_CORRECT_8BIT   5
#define TIM1_FASTPWM_PHASE_CORRECT_9BIT   6
#define TIM1_FASTPWM_PHASE_CORRECT_10BIT  7
#define TIM1_PWM_PHASE_AND_FREQUENCY_CORRECT_ICR1    8
#define TIM1_PWM_PHASE_AND_FREQUENCY_CORRECT_OCR1A    9

#define TIM1_PWM_PHASE_CORRECT_ICR1    10
#define TIM1_PWM_PHASE_CORRECT_OCR1A    11
#define TIM1_CTC_ICR1   					 12
#define TIM1_RESERVED   				13
#define TIM1_FAST_PWM_ICR1   				14
#define TIM1_FAST_PWM_OCR1A   				15





#define TIM0_F_PWM  3


#define TCCR1A 								*((volatile uint8*)0x4F)
#define TCCR1A_WGM10							 0
#define TCCR1A_WGM11							 1
#define TCCR1A_FOC1B							 2
#define TCCR1A_FOC1A							 3
#define TCCR1A_COM1B0							 4
#define TCCR1A_COM1B1							 5
#define TCCR1A_COM1A0							 6
#define TCCR1A_COM1A1							 7

#define TCCR1B 								 *((volatile uint8*)0x4E)
#define TCCR1B_CS10							 0
#define TCCR1B_CS11							 1
#define TCCR1B_CS12							 2
#define TCCR1B_WGM12							 3
#define TCCR1B_WGM13							 4
#define TCCR1B_RESERVED							 5
#define TCCR1B_ICES1							 6
#define TCCR1B_ICNC1							 7

#define TCNT1        						*((volatile uint16*)0x4C)

#define OCR1A        						*((volatile uint16*)0x4A)

#define OCR1B        						*((volatile uint16*)0x48)

#define ICR1        						*((volatile uint16*)0x46)
/*TIMSK – Timer/Counter Interrupt Mask Register*/

#define TIMSK        						*((volatile uint8*)0x59)
#define TIMSK_TOIE1 							2
#define TIMSK_OCIE1B							3
#define TIMSK_OCIE1A 							4
#define TIMSK_TICIE1							5

/*TIFR – Timer/Counter Interrupt Flag Register*/
#define TIFR        						*((volatile uint8*)0x58)
#define TIFR_TOV1 							2
#define TIFR_OCF1B                          3
#define TIFR_OCF1A							4
#define TIFR_ICF1                           5
#define CLOCK_SELECT_NO_CLOCK_SOURCE         								0

#define CLOCK_SELECT_CLOCK_0_PRESCALER        								1

#define CLOCK_SELECT_CLOCK_8_PRESCALER										2

#define CLOCK_SELECT_CLOCK_64_PRESCALER										3

#define CLOCK_SELECT_CLOCK_256_PRESCALER									4

#define CLOCK_SELECT_CLOCK_1024_PRESCALER									5

#define CLOCK_SELECT_EXTERNAL_CLOCK_SOURCE_T0_PIN_FALLING_EDGE 				6

#define CLOCK_SELECT_EXTERNAL_CLOCK_SOURCE_T0_PIN_RISING_EDGE				7



#endif
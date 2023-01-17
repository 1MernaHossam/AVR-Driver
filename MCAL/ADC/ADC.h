/**************************************/
/* Description : ADC Header file    */
/* Author      : Merna Hossam        */
/* Version     : 0.1v                 */
/* Date        : 23 Dec 2022          */
/* History     : 0.1v initial creation*/
/**************************************/


#ifndef ADC_H
#define ADC_H

#define ADC_AREF       0
#define ADC_AVCC             1
#define ADC_RESERVED   2
#define ADC_INTERNALVOLTAGEREFERENCE     3

#define ADC_ADLAR_LEFT_8BITS       0
#define ADC_ADLAR_RIGHT_10BITS       1


#define ADC_CHANNEL_0   0
#define ADC_CHANNEL_1   1
#define ADC_CHANNEL_2   2
#define ADC_CHANNEL_3   3
#define ADC_CHANNEL_4   4
#define ADC_CHANNEL_5   5
#define ADC_CHANNEL_6   6
#define ADC_CHANNEL_7   7

#define ADC_CH0_CH0_G10   8

/*SINGLE MODE*/
#define  ADC_SGL_MODE 8

#define  ADC_FREE_RUN_MODE  0
#define  ADC_ANALOG_CMP    1
#define ADC_EXTIN0_CMP     2

#define ADC_ INTERNALVOLTAGEREFERENCE     3
void ADC_voidInit();

void ADC_voidEnable();
void ADC_voidDisable();


void ADC_voidEnableInterrupt();
void ADC_voidDisableInterrupt();

void ADC_voidSetCallback(pf pfCallbackCpy);

void ADC_voidStartConversion(uint8 u8ChannelNbCpy);

uint16 ADC_u16ReadSync(uint8 u8ChannelNbCpy);
uint16 ADC_u16ReadAync(void);
void ADC_voidChangeMode(uint8 u8ModeCpy);

#endif

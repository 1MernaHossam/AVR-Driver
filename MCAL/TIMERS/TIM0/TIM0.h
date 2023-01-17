/**************************************/
/* Description : TIM0 header File     */
/* Author      : Lenovo               */
/* Version     : 0.1V                 */
/* Date        : 09:35:33  06 Jan 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef TIM0_H
#define TIM0_H



void TIM0_voidInit(void);
//change in prescaler through enable disable 
void TIM0_voidEnable(uint8 u8SpeedValCpy);
void TIM0_voidDisable(void);
void TIM0_voidEnableOvfInt(void);
void TIM0_voidDisableOvfInt(void);
void TIM0_voidEnableCmpInt(void);
void TIM0_voidDisableCmpInt(void);
void TIM0_voidSetCmpRegValue(uint8 u8CmpValCpy);
void TIM0_voidSetSetCallBackOvfInt(pf pfCallbackCpy);
void TIM0_voidSetSetCallBackCmpInt(pf pfCallbackCpy);
void TIM0_voidSetTimerValue(uint8 u8TimValCpy);
uint8 TIM0_voidReadTimerValue(void);




#endif

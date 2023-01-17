/**************************************/
/* Description : TIM1 header File     */
/* Author      : Lenovo               */
/* Version     : 0.1V                 */
/* Date        : 23:21:03  12 Jan 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef TIM1_H
#define TIM1_H



void TIM1_voidInit(void);
void TIM1_voidEnable(uint8 u8SpeedValCpy);
void TIM1_voidDisable(void);
void TIM1_voidSetCmpRegValue(uint8 u8CmpValCpy);
void TIM1_voidSetTimerValue(uint8 u8TimValCpy);
uint8 TIM1_voidReadTimerValue(void);
void TIM1_voidEnableOvfInt(void);
void TIM1_voidDisableOvfInt(void);
void TIM1_voidEnableCmpInt(void);
void TIM1_voidDisableCmpInt(void);
void TIM1_voidEnableICU(void);
void TIM1_voidDisableICU(void);
void TIM1_voidSetSetCallBackOvfInt(pf pfCallbackCpy);
void TIM1_voidSetSetCallBackICUInt(pf pfCallbackCpy);
void TIM1_voidSetSetCallBackCmpInt(pf pfCallbackCpy);



#endif

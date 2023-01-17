/**************************************/
/* Description : TIM2 header File     */
/* Author      : Lenovo               */
/* Version     : 0.1V                 */
/* Date        : 04:53:04  17 Jan 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef TIM2_H
#define TIM2_H

void TIM2_WGM_EnablePWM();
void TIM2_WGM_DisablePWM();

void TIM2_voidInit(void);
//change in prescaler through enable disable
void TIM2_voidEnable(uint8 u8SpeedValCpy);
void TIM2_voidDisable(void);
void TIM2_voidEnableOvfInt(void);
void TIM2_voidDisableOvfInt(void);
void TIM2_voidEnableCmpInt(void);
void TIM2_voidDisableCmpInt(void);
void TIM2_voidSetCmpRegValue(uint8 u8CmpValCpy);
void TIM2_voidSetSetCallBackOvfInt(pf pfCallbackCpy);
void TIM2_voidSetSetCallBackCmpInt(pf pfCallbackCpy);
void TIM2_voidSetTimerValue(uint8 u8TimValCpy);
uint8 TIM2_voidReadTimerValue(void);





#endif

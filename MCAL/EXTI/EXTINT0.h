/**************************************/
/* Description : Ext0 interface file  */
/* Author      : Abo elnour           */
/* Version     : 0.1v                 */
/* Date        : 17 Dec 2022          */
/* History     : 0.1v initial creation*/
/**************************************/

#ifndef  EXTINT0_H
#define  EXTINT0_H

typedef void(*pf)(void);


#define EXTINT0_LOW_LEVEL       0
#define EXTINT0_IOC             1
#define EXTINT0_FALLING_EDGE    2
#define EXTINT0_RISING_EDGE     3

void EXTINT0_voidInit(void);
void EXTINT0_voidEnable(void);
void EXTINT0_voidDisable(void);
void EXTINT0_voidChangeSense(uint8 u8SenseStateCpy);
void EXTINT0_voidSetCallBack(pf  pfCallbackCpy);

#endif



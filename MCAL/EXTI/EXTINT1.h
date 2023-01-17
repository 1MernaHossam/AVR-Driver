/**************************************/
/* Description : Ext1 interface file  */
/* Author      : Abo elnour           */
/* Version     : 0.1v                 */
/* Date        : 17 Dec 2022          */
/* History     : 0.1v initial creation*/
/**************************************/

#ifndef  EXTINT1_H
#define  EXTINT1_H

typedef void(*pf)(void);


#define EXTINT1_LOW_LEVEL       0
#define EXTINT1_IOC             1
#define EXTINT1_FALLING_EDGE    2
#define EXTINT1_RISING_EDGE     3

void EXTINT1_voidInit(void);
void EXTINT1_voidEnable(void);
void EXTINT1_voidDisable(void);
uint8 EXTINT1_voidChangeSense(uint8 u8SenseStateCpy);
void EXTINT1_voidSetCallBack(pf  pfCallbackCpy);

#endif



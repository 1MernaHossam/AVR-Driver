/**************************************/
/* Description : Ext2 interface file  */
/* Author      : Abo elnour           */
/* Version     : 0.1v                 */
/* Date        : 17 Dec 2022          */
/* History     : 0.1v initial creation*/
/**************************************/

#ifndef  EXTINT2_H
#define  EXTINT2_H

typedef void(*pf)(void);


#define EXTINT2_LOW_LEVEL       0
#define EXTINT2_IOC             1
#define EXTINT2_FALLING_EDGE    2
#define EXTINT2_RISING_EDGE     3

void EXTINT2_voidInit(void);
void EXTINT2_voidEnable(void);
void EXTINT2_voidDisable(void);
uint8 EXTINT2_voidChangeSense(uint8 u8SenseStateCpy);
void EXTINT2_voidSetCallBack(pf  pfCallbackCpy);

#endif



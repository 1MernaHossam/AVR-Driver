/**************************************/
/* Description : Ext1 interface file   */
/* Author      : Abo elnour           */
/* Version     : 0.1v                 */
/* Date        : 17 Dec 2022          */
/* History     : 0.1v initial creation*/
/**************************************/
#include "STD_Types.h"
#include "BIT_Math.h"

#include "EXTINT1.h"
#include "EXTINT1_priv.h"
#include "EXTINT1_cfg.h"


static pf EXTINT1_pfCall;

void EXTINT1_voidInit(void)
{
#if   EXTINT1_SENSE_MODE ==  EXTINT1_LOW_LEVEL 
    CLR_BIT(MCUCR , 2);
	CLR_BIT(MCUCR , 3);  
#elif EXTINT1_SENSE_MODE ==  EXTINT1_IOC  
	SET_BIT(MCUCR , 2);
	CLR_BIT(MCUCR , 3);   
       
#elif EXTINT1_SENSE_MODE ==  EXTINT1_FALLING_EDGE  
 	CLR_BIT(MCUCR , 2);
	SET_BIT(MCUCR , 3);
#elif EXTINT1_SENSE_MODE ==  EXTINT1_RISING_EDGE 
	SET_BIT(MCUCR , 2);
	SET_BIT(MCUCR , 3);

#endif 
   /*Disable Extint0*/
  CLR_BIT(GICR,7);
  /*Clear Event flag */
  SET_BIT(GIFR , 7 );
	
}
void EXTINT1_voidEnable(void)
{
	SET_BIT(GICR,7);
}
void EXTINT1_voidDisable(void)
{
	CLR_BIT(GICR,7);
}
uint8 EXTINT1_voidChangeSense(uint8 u8SenseStateCpy)
{
	uint8 Local_u8ErrorState= EOK;
	switch (u8SenseStateCpy)
	{
	    case EXTINT1_LOW_LEVEL    :
			CLR_BIT(MCUCR , 2);
			CLR_BIT(MCUCR , 3);
		break;
		case EXTINT1_IOC          :
			SET_BIT(MCUCR , 2);
			CLR_BIT(MCUCR , 3);
		break;
		case EXTINT1_FALLING_EDGE :
			CLR_BIT(MCUCR , 2);
			SET_BIT(MCUCR , 3);
		break;
		case EXTINT1_RISING_EDGE  :
			SET_BIT(MCUCR , 2);
			SET_BIT(MCUCR , 3);
		break;
		default: Local_u8ErrorState = ENOK;
		break;
		
	}
	return Local_u8ErrorState;
	
}
void EXTINT1_voidSetCallBack(pf  pfCallbackCpy)
{
	EXTINT1_pfCall = pfCallbackCpy ;
}
/* ISR EXTINT1 */
void __vector_2 (void) __attribute__((signal,used));
void __vector_2 (void)
{
	
	EXTINT1_pfCall();
	
}

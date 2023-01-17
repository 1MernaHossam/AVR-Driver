/**************************************/
/* Description : GIE interface file   */
/* Author      : Abo elnour           */
/* Version     : 0.1v                 */
/* Date        : 17 Dec 2022          */
/* History     : 0.1v initial creation*/
/**************************************/
#include "STD_Types.h"
#include "BIT_Math.h"

#include "EXTINT0.h"
#include "EXTINT0_priv.h"
#include "EXTINT0_cfg.h"


static pf EXTINT0_pfCall;

void EXTINT0_voidInit(void)
{
#if   EXTINT0_SENSE_MODE ==  EXTINT0_LOW_LEVEL 
    CLR_BIT(MCUCR , 0);
	CLR_BIT(MCUCR , 1);  
#elif EXTINT0_SENSE_MODE ==  EXTINT0_IOC  
	SET_BIT(MCUCR , 0);
	CLR_BIT(MCUCR , 1);   
       
#elif EXTINT0_SENSE_MODE ==  EXTINT0_FALLING_EDGE  
 	CLR_BIT(MCUCR , 0);
	SET_BIT(MCUCR , 1);
#elif EXTINT0_SENSE_MODE ==  EXTINT0_RISING_EDGE 
	SET_BIT(MCUCR , 0);
	SET_BIT(MCUCR , 1);

#endif 
   /*Disable Extint0*/
  CLR_BIT(GICR,6);
  /*Clear Event flag */
  SET_BIT(GIFR , 6 );
	
}
void EXTINT0_voidEnable(void)
{
	SET_BIT(GICR,6);
}
void EXTINT0_voidDisable(void)
{
	CLR_BIT(GICR,6);
}
void EXTINT0_voidChangeSense(uint8 u8SenseStateCpy)
{
	
	switch (u8SenseStateCpy)
	{
	    case EXTINT0_LOW_LEVEL    :
			CLR_BIT(MCUCR , 0);
			CLR_BIT(MCUCR , 1);
		break;
		case EXTINT0_IOC          :
			SET_BIT(MCUCR , 0);
			CLR_BIT(MCUCR , 1);
		break;
		case EXTINT0_FALLING_EDGE :
			CLR_BIT(MCUCR , 0);
			SET_BIT(MCUCR , 1);
		break;
		case EXTINT0_RISING_EDGE  :
			SET_BIT(MCUCR , 0);
			SET_BIT(MCUCR , 1);
		break;
		default :
		    CLR_BIT(MCUCR , 0);
			CLR_BIT(MCUCR , 1);
		
	}
	
}
void EXTINT0_voidSetCallBack(pf  pfCallbackCpy)
{
	EXTINT0_pfCall = pfCallbackCpy ;
}
/* ISR EXTINT0 */
void __vector_1 (void) __attribute__((signal,used));
void __vector_1 (void)
{
	
	EXTINT0_pfCall();
	
}

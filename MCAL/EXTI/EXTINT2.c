/**************************************/
/* Description : Ext2 interface file   */
/* Author      : Abo elnour           */
/* Version     : 0.1v                 */
/* Date        : 17 Dec 2022          */
/* History     : 0.1v initial creation*/
/**************************************/
#include "STD_Types.h"
#include "BIT_Math.h"

#include "EXTINT2.h"
#include "EXTINT2_priv.h"
#include "EXTINT2_cfg.h"


static pf EXTINT2_pfCall;

void EXTINT2_voidInit(void)
{
	/*#if   EXTINT2_SENSE_MODE ==  EXTINT2_LOW_LEVEL
    CLR_BIT(GICR , 5);
	SET_BIT(SREG , 7);  
	    SET_BIT(GICR , 5);

#elif EXTINT2_SENSE_MODE ==  EXTINT2_IOC  
    CLR_BIT(GICR , 5);

	SET_BIT(SREG , 7);  
		    SET_BIT(GICR , 5);
	 */

#if EXTINT2_SENSE_MODE ==  EXTINT2_FALLING_EDGE 
	CLR_BIT(GICR , 5);

	SET_BIT(SREG , 7);  

	CLR_BIT(MCUCSR , 6);
	SET_BIT(GICR , 5);

#elif EXTINT2_SENSE_MODE ==  EXTINT2_RISING_EDGE 
	CLR_BIT(GICR , 5);

	SET_BIT(SREG , 7);  

	SET_BIT(MCUCSR , 6);
	SET_BIT(GICR , 5);

#endif 
	/*Disable Extint0*/
	CLR_BIT(GICR,5);
	/*Clear Event flag */
	SET_BIT(GIFR , 5 );

}
void EXTINT2_voidEnable(void)
{
	SET_BIT(GICR,5);
}
void EXTINT2_voidDisable(void)
{
	CLR_BIT(GICR,5);
}
uint8 EXTINT2_voidChangeSense(uint8 u8SenseStateCpy)
{
	uint8 Local_u8ErrorState= EOK;


	switch (u8SenseStateCpy)
	{

	case EXTINT2_FALLING_EDGE :
		CLR_BIT(GICR , 5);

		SET_BIT(SREG , 7);

		CLR_BIT(MCUCSR , 6);
		SET_BIT(GICR , 5);
		break;
	case EXTINT2_RISING_EDGE  :
		CLR_BIT(GICR , 5);

		SET_BIT(SREG , 7);

		SET_BIT(MCUCSR , 6);
		SET_BIT(GICR , 5);

		break;
	default: Local_u8ErrorState = ENOK;
	break;
	}
	return Local_u8ErrorState;

}
void EXTINT2_voidSetCallBack(pf  pfCallbackCpy)
{
	EXTINT2_pfCall = pfCallbackCpy ;
}
/* ISR EXTINT3 */
void __vector_3 (void) __attribute__((signal,used));
void __vector_3 (void)
{

	EXTINT2_pfCall();

}

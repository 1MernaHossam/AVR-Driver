/**************************************/
/* Description : GIE interface file   */
/* Author      : Abo elnour           */
/* Version     : 0.1v                 */
/* Date        : 17 Dec 2022          */
/* History     : 0.1v initial creation*/
/**************************************/
#include "STD_Types.h"
#include "BIT_Math.h"

#include "GIE.h"
#include "GIE_priv.h"

void GIE_voidEnable(void) 
{
	SET_BIT(SREG , 7);
}

void GIE_voidDiable(void) 
{
	CLR_BIT(SREG , 7);
}
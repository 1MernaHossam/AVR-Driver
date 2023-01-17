/**************************************/
/* Description : Ext1 private file    */
/* Author      : Abo elnour           */
/* Version     : 0.1v                 */
/* Date        : 17 Dec 2022          */
/* History     : 0.1v initial creation*/
/**************************************/

#ifndef  EXTINT1_PRIV_H
#define  EXTINT1_PRIV_H

#define MCUCR  *((volatile uint8 *) 0x55 )
#define GICR   *((volatile uint8 *) 0x5B )
#define GIFR   *((volatile uint8 *) 0x5A )
#define MCUCSR *((volatile uint8 *) 0x54 )
#endif



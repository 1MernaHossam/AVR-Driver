/****************************************************/
/*      Description : 	Bit Math Lib          */
/* 		Author		:	Merna Hossam                */
/*		Version		:	0.1v						*/
/*		Date		: 	11Nov 2022					*/
/****************************************************/
#ifndef	 BIT_MATH_H
#define  BIT_MATH_H
#define		SET(Reg,bitNo)		Reg |  =(1<<bitNo)
#define		CLR(Reg,bitNo)		Reg &  =~(1<<bitNo)
#define		TOGGLE(Reg,bitNo)	Reg ^  =(1<<bitNo)
#define		GETBIT(Reg,bitNo)	Reg	   =(Reg>>bitNo)&1
#endif
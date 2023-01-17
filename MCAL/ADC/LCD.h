/**************************************/
/* Description : LCD header File      */
/* Author      : Aboelno              */
/* Version     : 0.1V                 */
/* Date        : 13:45:20  03 Dec 2022*/
/* History     : 0.1V Initial Creation*/
/**************************************/
#ifndef LCD_H
#define LCD_H

void LCD_voidInit(void);

void LCD_voidWriteCmd(uint8 u8LcdIndxCpy , uint8 u8CmdCpy);

void LCD_voidDisplayChar(uint8 u8LcdIndxCpy , uint8 u8CharCpy);
void LCD_voidSendString(uint8 u8LcdIndxCpy,const uint8* Copy_pchString);
void LCD_voidGotoXY(uint8 u8LcdIndxCpy,uint8 Copy_u8XPos, uint8 Copy_u8YPos);
void LCD_voidSendNumber(uint8 u8LcdIndxCpy , uint32 u8IntCpy);
void lcd_home(uint8 u8LcdIndxCpy);
void lcdClearbit(uint8 u8LcdIndxCpy,uint8 Copy_u8XPos,uint8 Copy_u8YPos);
void LCD_voidWriteSpecialCharacter(uint8 u8LcdIndxCpy,uint8* Copy_pu8Pattern,uint8 Copy_u8PatternNumber,uint8 Copy_u8XPos,uint8 Copy_u8YPos);
#endif






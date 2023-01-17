/*
 * KEYPAD.h
 *
 *  Created on: Dec 16, 2022
 *      Author: Lenovo
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

void KEYPAD_voidInit(void);
uint8 KEYPAD_u8GetPressedKey(uint8 u8KeypadIdxCpy);
static void voidWriteSeq(uint8 u8KeypadIdxCpy,uint8 u8SeqIdxCpy);
static uint16 u16ReadInputs(uint8 u8KeypadIdxCpy);
static uint8 u8CheckReading(uint8 u8KeypadIdxCpy,uint8 u8SeqIdxCpy,uint16 u16InputReadingCpy);
#endif /* KEYPAD_H_ */

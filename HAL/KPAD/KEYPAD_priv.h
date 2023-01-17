/*
 * KEYPAD_priv.h
 *
 *  Created on: Dec 16, 2022
 *      Author: Lenovo
 */

#ifndef KEYPAD_PRIV_H_
#define KEYPAD_PRIV_H_


typedef struct
{
	uint8 au8InputPins[KEYPAD_MAX_INPUT_NUM];
	uint8 au8OutputPins[KEYPAD_MAX_OUTPUT_NUM];
	uint8 u8InputPinsNum;
	uint8 u8OutputPinsNum;
}tstrKeypadConfigSet;

extern uint8 KEYPAD_au8Mapping[KEYPAD_MAX_NUM][KEYPAD_MAX_OUTPUT_NUM][KEYPAD_MAX_INPUT_NUM];
extern tstrKeypadConfigSet KEYPAD_astrConfigSet[KEYPAD_MAX_NUM];

#endif /* KEYPAD_PRIV_H_ */

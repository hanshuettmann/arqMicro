/*
 * functions.h
 *
 *  Created on: May 30, 2022
 *      Author: hansh
 */

#ifndef INC_FUNCTIONS_H_
#define INC_FUNCTIONS_H_

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>

/* Public function prototypes ------------------------------------------------*/
void zeros(uint32_t *vector, uint32_t length);
void scalar32(uint32_t *vectorIn, uint32_t *vectorOut, uint32_t length, uint32_t scalar);
void scalar16(uint16_t *vectorIn, uint16_t *vectorOut, uint16_t length, uint16_t scalar);
void scalar12(uint16_t *vectorIn, uint16_t *vectorOut, uint16_t length,uint16_t scalar);
uint32_t getMaxIndex(int32_t *vectorIn, uint32_t length);
void windowFilter10(uint16_t *vectorIn, uint16_t *vectorOut, uint32_t vectorInLength);
void invertVector(uint16_t *vector, uint32_t length);
void removeSample(int32_t *vectorIn, int32_t *vectorOut, uint32_t length, uint32_t N);
void pack32to16(int32_t *vectorIn, int16_t *vectorOut, uint32_t length);
void corr(int16_t *vectorX, int16_t *vectorY, int16_t *vectorCorr, uint32_t length);

#endif /* INC_FUNCTIONS_H_ */
/*****************************END OF FILE**************************************/

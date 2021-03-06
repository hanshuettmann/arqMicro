#pragma once

#include <stdint.h>

void asm_svc(void);
uint32_t asm_sum(uint32_t firstOperand, uint32_t secondOperand);
void asm_zeros(uint32_t *vector, uint32_t longitud);
void asm_scalar32(uint32_t *vectorIn, uint32_t *vectorOut, uint32_t length,
		uint32_t scalar);
void asm_scalar16(uint16_t *vectorIn, uint16_t *vectorOut, uint16_t length,
		uint16_t scalar);
void asm_scalar12(uint16_t *vectorIn, uint16_t *vectorOut, uint16_t length,
		uint16_t scalar);
void asm_scalar12_sat(uint16_t *vectorIn, uint16_t *vectorOut, uint16_t length,
		uint16_t scalar);
void asm_invertVector(uint16_t *vector, uint32_t length);
void asm_removeSample(int32_t *vectorIn, int32_t *vectorOut, uint32_t length,
		uint32_t N);
void asm_pack32to16(int32_t *vectorIn, int16_t *vectorOut, uint32_t length);
uint32_t asm_getMaxIndex(int32_t *vectorIn, uint32_t length);

/*
 * functions.c
 *
 *  Created on: May 30, 2022
 *      Author: hansh
 */

/* Includes ------------------------------------------------------------------*/
#include "functions.h"

/* Private function prototypes -----------------------------------------------*/
/**
 * @brief Initialize vector with zero values
 * @param vector pointer to array to be 0 initialized
 * @param length amount of elements in the array
 * @retval None
 */
void zeros(uint32_t *vector, uint32_t length) {
	uint32_t *const vectorEnd = vector + length;

	for (; vector < vectorEnd; ++vector) {
		*vector = 0;
	}
}

/**
 * @brief Multiply each element of uint32_t array by scalar
 * @param vectorIn pointer to uint32_t array to be multiplied
 * @param vectorOut pointer to uint32_t output array
 * @param length amount of elements in the array
 * @retval None
 */
void scalar32(uint32_t *vectorIn, uint32_t *vectorOut, uint32_t length,
		uint32_t scalar) {
	uint32_t *const vectorEnd = vectorIn + length;

	for (; vectorIn < vectorEnd; ++vectorIn) {
		*vectorOut = *vectorIn * scalar;
		++vectorOut;
	}
}

/**
 * @brief Multiply each element of uint16_t array by scalar
 * @param vectorIn pointer to uint16_t array to be multiplied
 * @param vectorOut pointer to uint16_t output array
 * @param length amount of elements in the array
 * @retval None
 */
void scalar16(uint16_t *vectorIn, uint16_t *vectorOut, uint16_t length,
		uint16_t scalar) {
	uint16_t *const vectorEnd = vectorIn + length;

	for (; vectorIn < vectorEnd; ++vectorIn) {
		*vectorOut = *vectorIn * scalar;
		++vectorOut;
	}
}

/**
 * @brief Multiply each element of array by scalar
 * @param vectorIn pointer to uint16_t array to be multiplied
 * @param vectorOut pointer to uint16_t output array
 * @param length amount of elements in the array
 * @retval None
 */
void scalar12(uint16_t *vectorIn, uint16_t *vectorOut, uint16_t length,
		uint16_t scalar) {
	uint16_t *const vectorEnd = vectorIn + length;
	uint16_t const MAX_VALUE = 4095;

	for (; vectorIn < vectorEnd; ++vectorIn) {
		/* Remove 4 MSB */
		*vectorOut = *vectorIn * scalar;
		if (*vectorOut > MAX_VALUE)
			*vectorOut = MAX_VALUE;
		++vectorOut;
	}
}


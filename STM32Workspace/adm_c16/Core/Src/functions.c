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

/**
 * @brief return the index of the maximum value inside vectorIn
 * @param vectorIn pointer to int32_t array
 * @param length amount of elements in the array
 * @retval index
 */
uint32_t getMaxIndex(int32_t *vectorIn, uint32_t length) {
	int32_t maxValue = *vectorIn;
	uint32_t index = 0;
	int32_t *const vectorEnd = vectorIn + length;

	for (; vectorIn < vectorEnd; ++vectorIn) {
		if (*vectorIn > maxValue) {
			maxValue = *vectorIn;
			index = length - (vectorEnd - vectorIn);
		}
	}

	return index;
}

/**
 * @brief window-based filter of 10 elements
 * @param vectorIn pointer to int32_t array
 * @param vectorOut pointer to int32_t array
 * @param vectorInLength amount of elements in the array
 * @retval none
 */
void windowFilter10(uint16_t *vectorIn, uint16_t *vectorOut,
		uint32_t vectorInLength) {
	const uint16_t WINDOW_SIZE = 10;

	uint16_t *const vectorEnd = vectorIn + vectorInLength;
	uint16_t sum = 0;
	uint16_t *ptrInit = vectorIn;
	uint16_t *ptrAux = 0;

	for (uint16_t i = 0; i < vectorInLength; ++i) {
		for (uint16_t j = 0; j < WINDOW_SIZE; ++j) {
			if (vectorIn + j > vectorEnd - 1) {
				ptrAux = vectorIn;
				vectorIn = ptrInit;
				for (uint16_t k = 0; k < WINDOW_SIZE - j; ++k) {
					sum += *(vectorIn + k);
				}
				vectorIn = ptrAux;
				break;
			} else {
				sum += *(vectorIn + j);
			}
		}

		*vectorOut = sum / WINDOW_SIZE;
		sum = 0;

		++vectorIn;
		++vectorOut;

	}
}

/**
 * @brief inverts positions of elements inside a vector
 * @param vectorIn pointer to int32_t array
 * @param length amount of elements in the array
 * @retval none
 */
void invertVector(uint16_t *vector, uint32_t length) {
	uint16_t auxValue = 0;

	/* Exchange the first element with the last one until length/2 */
	for (uint16_t i = 0; i < length / 2; ++i) {
		auxValue = vector[i];
		vector[i] = vector[length - 1 - i];
		vector[length - 1 - i] = auxValue;
	}
}

/**
 * @brief eliminates one element every N samples
 * @param vectorIn pointer to int32_t array
 * @param vectorOut pointer to int32_t array
 * @param length amount of elements in the array
 * @retval none
 */
void removeSample(int32_t *vectorIn, int32_t *vectorOut, uint32_t length,
		uint32_t N) {
	uint32_t i = 0;
	uint32_t j = 0;

	while (i < length + 1) {
		if (i % (N + 1) != 0) {
			vectorOut[j] = vectorIn[i - 1];
			++j;
		}
		++i;
	}
}

/**
 * @brief packs the vectorIn elements into 16 bits
 * @param vectorIn pointer to int32_t array
 * @param vectorOut pointer to int16_t array
 * @param length amount of elements in the array
 * @retval none
 */
void pack32to16(int32_t *vectorIn, int16_t *vectorOut, uint32_t length) {
	for (uint32_t i = 0; i < length; ++i) {
		vectorOut[i] = (int16_t) (vectorIn[i] >> 16);
	}
}

/**
 * @brief gets the correlation vector between vectorX and vectorY
 * @param vectorX pointer to int16_t array
 * @param vectorY pointer to int16_t array
 * @param vectorCorr pointer to int16_t array
 * @param length amount of elements in the array
 * @retval none
 */
void corr(int16_t *vectorX, int16_t *vectorY, int16_t *vectorCorr,
		uint32_t length) {

	for (int16_t j = 0; j < length; ++j) {
		for (uint16_t i = 0; i < length; ++i) {
			if (i - j >= 0)
				vectorCorr[j] += vectorX[i] * vectorY[i - j];
		}
	}
}


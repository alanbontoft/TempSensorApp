/*
 * STTS22.cpp
 *
 *  Created on: Mar 11, 2024
 *      Author: 103019535
 */

#include "STTS22.h"

STTS22::STTS22(I2C_HandleTypeDef &handle) {
	_handle = handle;
}

STTS22::~STTS22() {
	// TODO Auto-generated destructor stub
}

bool STTS22::ReadTemp(float *temp) {

	HAL_StatusTypeDef status;

	uint8_t data[2], buffer[2];
	uint16_t numbytes;
	int16_t value;

	// set one_shot bit in control register to start conversion
	data[0] = STTS_CTRL;
	data[1] = 0x01;
	numbytes = 2;

	status = HAL_I2C_Master_Transmit (&_handle, _address, data, numbytes, _timeout);

	if (status != HAL_OK) return false;


	// Send Temp_L register address
	data[0] = STTS_TEMPL;
	numbytes = 1;

	status = HAL_I2C_Master_Transmit (&_handle, _address, data, numbytes, _timeout);

	if (status != HAL_OK) return false;

	// Read low byte
	status = HAL_I2C_Master_Receive (&_handle, _address, &buffer[0], numbytes, _timeout);

	if (status != HAL_OK) return false;

	// Send Temp_L register address
	data[0] = STTS_TEMPH;

	status = HAL_I2C_Master_Transmit (&_handle, _address, data, numbytes, _timeout);

	if (status != HAL_OK) return false;


	// Read high byte
	status = HAL_I2C_Master_Receive (&_handle, _address, &buffer[1], numbytes, _timeout);

	// combine bytes
	value = *((int16_t*)buffer);

	// divide by 100 to give temperature value
	*temp = (float)value/100.0F;

	return true;
}


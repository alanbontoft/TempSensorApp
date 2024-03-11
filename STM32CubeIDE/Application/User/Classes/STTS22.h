/*
 * STTS22.h
 *
 *  Created on: Mar 11, 2024
 *      Author: 103019535
 */

#ifndef APPLICATION_USER_CLASSES_STTS22_H_
#define APPLICATION_USER_CLASSES_STTS22_H_



// I2C register defines
#define STTS_CTRL 0x04
#define STTS_STATUS 0x05
#define STTS_TEMPL 0x06
#define STTS_TEMPH 0x07

#include "main.h"

class STTS22 {
public:
	STTS22(I2C_HandleTypeDef &handle);
	virtual ~STTS22();

	bool ReadTemp(float *temp);
private:
	I2C_HandleTypeDef _handle;
	uint16_t _address = 0x3f << 1;			// I2C address
	uint32_t _timeout = 100;				// I2C timeout
};

#endif /* APPLICATION_USER_CLASSES_STTS22_H_ */

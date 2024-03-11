#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include "STTS22.h"

float g_Temperature;

static int divider = 0;

STTS22 *pTempSensor;
extern I2C_HandleTypeDef hi2c3;

Model::Model() : modelListener(0)
{
	pTempSensor = new STTS22(hi2c3);
}

void Model::tick()
{
	divider++;

	if (divider == 50)
	{
		pTempSensor->ReadTemp(&g_Temperature);
		modelListener->update(g_Temperature);
		divider = 0;
	}

}

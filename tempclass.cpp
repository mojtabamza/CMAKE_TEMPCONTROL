#include "tempclass.hpp"

TemperatureControlSystem::TemperatureControlSystem() : guiObj()
{
	init();
	setMinMaxTemp(DEFAULTMINTEMP, DEFAULTMAXTEMP);
}

TemperatureControlSystem::TemperatureControlSystem(double minTemp, double maxTemp) : guiObj()
{
	init();
	setMinMaxTemp(minTemp, maxTemp);
}

void TemperatureControlSystem::init(void)
{
	//init GPIOs as output to control heater and cooler
	//init SERIAL ports
	//init ADC for temperature sensor
}

OpStatus TemperatureControlSystem::controlTask(void)
{
	OpStatus res;
	if (getCurrentTemp() > this->maxTemp) {
		sendFeedback("start Cooling!");
		runOperation(COOLER, ON);
		res = COOLER_ON;
	}
	else if (getCurrentTemp() < this->minTemp) {
		sendFeedback("start Heating!");
		runOperation(HEATER, ON);
		res = HEATER_ON;
	}
	else {
		sendFeedback("Normal Temperature");
		runOperation(HEATER, OFF);
		runOperation(COOLER, OFF);
		res = NORMAL_CONDITION;
	}
	return res;
}

ValidityStatus TemperatureControlSystem::setMinMaxTemp(double minTemp, double maxTemp)
{
	if (checkTempValidity(minTemp, maxTemp) == VALID) {
		this->minTemp = minTemp;
		this->maxTemp = maxTemp;
		sendFeedback("Successfully set!");
		return VALID;
	}
	else {
		sendFeedback("Invalid Values");
		return INVALID;
	}
}

ValidityStatus TemperatureControlSystem::checkTempValidity(double min, double max)
{
	if ((max >= 0) && (min >= 0) && (max > min)) {//make conditions to have meaningful data
		return VALID;
	}
	return INVALID;
}

double TemperatureControlSystem::getCurrentTemp(void)
{
	//read updated temperature from ADC or other type of sensors
	//this->currentTemp = adcObj.getValue();
	return this->currentTemp;
}

void TemperatureControlSystem::sendFeedback(string data)
{
	this->guiObj->printData(data);
}

void TemperatureControlSystem::runOperation(Operation op, Status st)
{
	if (op == HEATER) {
		if (st == OFF) {
			//GPIO_writePin(PORTx0, PINy0, RESET)  -- >  HEATER OFF
		}
		else
		{
			//GPIO_writePin(PORTx0, PINy0, SET)  -- >  HEATER ON
		}
	}
	if (op == COOLER) {
		if (st == OFF) {
			//GPIO_writePin(PORTx1, PINy1, RESET)  -- >  COOLER OFF
		}
		else
		{
			//GPIO_writePin(PORTx1, PINy1, SET)  -- >  COOLER ON
		}
	}
}


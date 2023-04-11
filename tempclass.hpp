#pragma once

#include <string>
#include "guiclass.hpp"
using std::string;

#define DEFAULTMAXTEMP 30
#define DEFAULTMINTEMP 15

#define SOME_CONDITION 1

enum ValidityStatus {
	VALID = 0,
	INVALID,
};

enum Operation {
	HEATER = 0,
	COOLER,
};

enum Status {
	OFF = 0,
	ON,
};

enum OpStatus {
	HEATER_ON = 0,
	COOLER_ON,
	NORMAL_CONDITION,
};


class TemperatureControlSystem
{
public:
	TemperatureControlSystem();
	TemperatureControlSystem(double minTemp, double maxTemp);

	OpStatus controlTask(void);
	ValidityStatus setMinMaxTemp(double mintemp, double maxTemp);
	inline double getMaxTemp(void) { return maxTemp; }
	inline double getMinTemp(void) { return minTemp; }

	inline void setCurrentTemp(double temp) { this->currentTemp = temp; } //implemented to use in GTest

private:
	void init(void);
	double getCurrentTemp(void);
	void sendFeedback(string data);
	void runOperation(Operation op, Status st);
	ValidityStatus checkTempValidity(double min, double max);

	double maxTemp;
	double minTemp;
	double currentTemp;
	GUI* guiObj;
};

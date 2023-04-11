
#include <iostream>
#include "tempclass.hpp"


int main(void) {
	TemperatureControlSystem roomtmp(18, 28);

	while (1) {
		roomtmp.controlTask();
	}
	return 0;

}
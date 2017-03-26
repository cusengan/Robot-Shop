#ifndef BATTERY_H
#define BATTERY_H

#include <iostream>
#include "Robot_part.h"

class Battery : public Robot_part{

public:

private:
	double power_available;
	double max_energy;

};

#endif

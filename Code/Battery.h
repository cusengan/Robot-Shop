#ifndef BATTERY_H
#define BATTERY_H

#include <iostream>
#include "Robot_part.h"

class Battery : public Robot_part{

public:
	Battery(std::string _name, int _model_number) : 
			Robot_part(_name,_model_number) {}
	std::string get_info();

private:
	double power_available;
	double max_energy;

};

#endif

#ifndef ROBOT_MODEL_H
#define ROBOT_MODEL_H

#include <iostream>
#include "Robot_part.h"


class Robot_model{
public:
	double cost();
	double max_speed();
	double max_battery_life();

private:
	std::string name;
	int model_number;
	Robot_part torso;
	Robot_part head;
	Robot_part locomotor;
	Robot_part arm;
	Robot_part battery;

};

#endif
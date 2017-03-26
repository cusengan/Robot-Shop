#ifndef ROBOT_MODEL_H
#define ROBOT_MODEL_H

#include <iostream>
#include "Robot_part.h"
#include "Torso.h"
#include "Head.h"
#include "Battery.h"
#include "Locomotor.h"
#include "Arm.h"


class Robot_model{
public:
	Robot_model(std::string _name,
				int _model_num,
				Arm _arm, 
				Head _head, 
				Torso _torso,
				Battery _battery, 
				Locomotor _locomotor) : 

				name(_name), 
				model_number(_model_num), 
				arm(_arm),
				head(_head),
				torso(_torso),
				battery(_battery),
				locomotor(_locomotor) { }

	double cost();
	double max_speed();
	double max_battery_life();

private:
	std::string name;
	int model_number;
	Torso torso;
	Head head;
	Locomotor locomotor;
	Arm arm;
	Battery battery;

};

#endif
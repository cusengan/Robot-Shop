#ifndef ROBOT_MODEL_H
#define ROBOT_MODEL_H

#include <iostream>
#include <vector>
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
	std::string save_to_file();
	std::string get_info();
	Arm get_robot_arm();
	Head get_robot_head();
	Torso get_robot_torso();
	Battery get_robot_battery();
	Locomotor get_robot_locomotor();
	void add_choice(int choice);
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
	std::vector<int> choices;//this vector keeps track of what was chosen

};

#endif
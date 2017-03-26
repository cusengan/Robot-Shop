#ifndef TORSO_H
#define TORSO_H

#include <iostream>
#include "Robot_part.h"

class Torso : public Robot_part{

public:
	Torso(std::string _name, int _model_number) : 
			Robot_part(_name,_model_number) {}
	std::string get_info();

private:
	int battery_components;
	int max_arms;

};

#endif
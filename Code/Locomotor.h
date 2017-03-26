#ifndef LOCOMOTOR_H
#define LOCOMOTOR_H

#include <iostream>
#include "Robot_part.h"

class Locomotor : public Robot_part{

public:
	Locomotor(std::string _name, int _model_number) : 
			Robot_part(_name,_model_number) {}
	std::string get_info();

private:
	double max_power;
};

#endif
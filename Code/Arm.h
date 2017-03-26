#ifndef ARM_H
#define ARM_H

#include <iostream>
#include "Robot_part.h"

class Arm : public Robot_part{

public:
	Arm(std::string _name, int _model_number) : 
			Robot_part(_name,_model_number) {}
	std::string get_info();
	

private:
	
	double length;
	double max_power;
};

#endif

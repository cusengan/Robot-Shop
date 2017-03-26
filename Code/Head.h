#ifndef HEAD_H
#define HEAD_H

#include <iostream>
#include "Robot_part.h"

class Head : public Robot_part{

public:
	Head(std::string _name, int _model_number) : 
			Robot_part(_name,_model_number) {}
	std::string get_info();

private:
	double power;
	
};

#endif
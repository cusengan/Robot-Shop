#ifndef ARM_H
#define ARM_H

#include <iostream>
#include "Robot_part.h"

class Arm : public Robot_part{

public:
	Arm(std::string _name, 
	    int _model_number,
	    double _price,
	    std::string _description) : 
	Robot_part(_name,
	     	   _model_number,
		   _price,
	  	   _description) {}
	
	std::string get_info();
	std::string save_to_file();
	

private:
	
	double length;
	double max_power;
};

#endif

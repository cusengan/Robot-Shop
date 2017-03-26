#ifndef ARM_H
#define ARM_H

#include <iostream>
#include "Robot_part.h"

class Arm : public Robot_part{

public:
	Arm(double _length, double _max_power): length(_length), 
											max_power(_max_power){}


private:
	
	double length;
	double max_power;
};

#endif

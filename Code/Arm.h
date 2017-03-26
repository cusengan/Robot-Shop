#include <iostream>
#ifndef ARM_H
#define ARM_H

class Arm : Robot_part{

public:
	Arm(double _length, double _max_power): length(_length), 
											max_power(_max_power){}


private:
	
	double length;
	double max_power;
};

#endif

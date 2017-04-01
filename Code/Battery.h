#ifndef BATTERY_H
#define BATTERY_H

#include <iostream>
#include "Robot_part.h"

class Battery : public Robot_part{

public:
	Battery(std::string _name, 
            	int _model_number,
            	double _price,
            	std::string _description) :
        Robot_part(_name,
                   _model_number, 
                   _price, 
                   _description) {}
  std::string save_to_file();
	std::string get_info();

private:
	double power_available;
	double max_energy;

};

#endif

#ifndef HEAD_H
#define HEAD_H

#include <iostream>
#include "Robot_part.h"

class Head : public Robot_part{

public:
	Head(std::string _name,    
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
	double power;
	
};

#endif

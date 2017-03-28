#ifndef ROBOT_PART_H
#define ROBOT_PART_H

#include <iostream>
#include <string>


class Robot_part{
public:
	Robot_part(std::string _name, 
		   int _model_number, 
		   double _price,
		   std::string _description) : 
		   name(_name), 
		   model_number(_model_number), 
		   price (_price),
		   description(_description){}

	std::string get_info();

protected:
	std::string name;
	int model_number;
	double price;
	std::string description;
	std::string image_filename;

};

#endif

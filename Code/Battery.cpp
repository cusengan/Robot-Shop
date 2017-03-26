#include "Battery.h"

std::string Battery::get_info(){
	std::string info = Robot_part::get_info();
	return info;
}
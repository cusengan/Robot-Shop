#include "Battery.h"

std::string Battery::get_info(){
	std::string info = Robot_part::get_info();
	return info;
}

std::string Battery::save_to_file(){
	std::string info = "Battery_Identifier\n"  + Robot_part::save_to_file();
	return info;
}
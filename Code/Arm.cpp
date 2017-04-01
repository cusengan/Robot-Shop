#include "Arm.h"

std::string Arm::get_info(){
	std::string info = Robot_part::get_info();
	return info;
}

std::string Arm::save_to_file(){
	std::string info = "Arm_Identifier \n"  + Robot_part::save_to_file();
	return info;
}
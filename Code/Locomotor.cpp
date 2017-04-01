#include "Locomotor.h"

std::string Locomotor::get_info(){
	std::string info = Robot_part::get_info();
	return info;
}

std::string Locomotor::save_to_file(){
	std::string info = "Locomotor_Identifier \n"  + Robot_part::save_to_file();
	return info;
}
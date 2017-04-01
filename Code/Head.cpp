#include "Head.h"

std::string Head::get_info(){
	std::string info = Robot_part::get_info();
	return info;
}

std::string Head::save_to_file(){
	std::string info = "Head_Identifier \n"  + Robot_part::save_to_file();
	return info;
}
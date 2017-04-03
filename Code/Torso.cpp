#include "Torso.h"

std::string Torso::get_info(){

	std::string info = Robot_part::get_info();
	return info;

}

std::string Torso::save_to_file(){
	std::string info = "Torso_Identifier\n"  + Robot_part::save_to_file();
	return info;
}
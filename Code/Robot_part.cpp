#include "Robot_part.h"

std::string Robot_part::get_info(){

	std::string info = "Name: " + name + "\n" 
						"Model number: " + std::to_string(model_number) + "\n";
	return info;
}
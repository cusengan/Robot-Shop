#include "Robot_part.h"

std::string Robot_part::get_info(){

	std::string info = "Name: " + name + '\n'+ 
	"Model number: " + std::to_string(model_number) + '\n'+
	+"Price (usd): " + std::to_string(price) + '\n'+
	"Description: " + description + '\n';
	return info;
}

double Robot_part::get_price(){
	return price;
}

#include "SalesAssociate.h"

std::string SalesAssociate::get_info(){

	std::string info = 
	"Sales Associate's Name: " + name + '\n'+
	"Sales Associate's ID Number: " + std::to_string(id) + '\n';
	
	return info;

}

std::string SalesAssociate::save_to_file(){
	std::string info = "Sales_Associate_Identifier\n" + name + "\n" +
						std::to_string(id);
	return info;
}


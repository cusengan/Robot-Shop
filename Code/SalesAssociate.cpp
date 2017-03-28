#include "SalesAssociate.h"

std::string SalesAssociate::get_info(){

	std::string info = 
	"Sales Associate's Name: " + name + '\n'+
	"Sales Associate's ID Number: " +std::to_sring(id) + '\n';
	
	return info;

}

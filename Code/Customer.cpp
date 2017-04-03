#include "Customer.h"

std::string Customer::get_info(){

        std::string info =
        "Beloved Customer's Name: " + name + '\n'+
        "Beloved Customer's ID Number: " + std::to_string(id) + '\n'+
	"Beloved Customer's phone number (one continuous number): "+ std::to_string(phone) + '\n'+
	"Beloved Customer's email: " + email +'\n';
        return info;

}

std::string Customer::save_to_file(){
	std::string info = "Customer_Identifier\n" + name + "\n" 
						+ std::to_string(id) + "\n" + 
						std::to_string(phone) + "\n" +
						email;
	return info;
}

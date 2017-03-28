#include "Customer.h"

std::string Customer::get_info(){

        std::string info =
        "Beloved Customer's Name: " + name + '\n'+
        "Beloved Customer's ID Number: " +std::to_sring(id) + '\n'+
	"Beloved Customer's phone number (one continuous number): "+std::to_sring(phone) + '\n'+
	"Beloved Customer's email: " + email +'\n';
        return info;

}


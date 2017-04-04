#include "Order.h"

std::string Order::get_info(){

	std::string info = model.get_info() + '\n' + seller.get_info() + '\n' + customer.get_info() + '\n';
	return info;
}

std::string Order::save_to_file(){
	std::string info = "Order_Identifier\n" + std::to_string(choices[0]) + "\n"
						+ std::to_string(choices[1]) + "\n"
						+ std::to_string(choices[2]);
	return info;

}

void Order::add_choice(int choice){
	choices.push_back(choice);
}


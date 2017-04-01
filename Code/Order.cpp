#include "Order.h"

std::string Order::get_info(){

	std::string info = model.get_info() + '\n' + seller.get_info() + '\n' + customer.get_info() + '\n';
	return info;
}

std::string Order::save_to_file(){
	std::string info = "Order_Identifier\n" + model.save_to_file() + "\n";

}
#include "Order.h"

std::string Order::get_info(){

	std::string info = model.get_info() + '\n' + seller.get_info() + '\n' + customer.get_info() + '\n';
	return info;
}

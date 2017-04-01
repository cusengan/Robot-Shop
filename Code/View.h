#ifndef VIEW_H
#define VIEW_H
#include <string>
#include "Shop.h"

class View{
public:
	View(Shop& market) : shop(market){}
	std::string get_menu();
	std::string get_robot_models();
	std::string parts_menu();
	std::string get_robot_parts(int choice);
	std::string create_a_part_menu();
	std::string view_customers_menu();
	std::string view_sales_associates_menu();
	std::string view_orders_menu();


private:
	Shop& shop;
};

#endif

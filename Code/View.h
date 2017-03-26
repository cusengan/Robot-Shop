#ifndef VIEW_H
#define VIEW_H
#include <string>
#include "Shop.h"

class View{
public:
	View(Shop& market) : shop(market){}
	std::string get_menu();
	std::string get_robot_models();
	std::string get_robot_parts();

private:
	Shop& shop;
};

#endif
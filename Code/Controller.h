#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <sstream>
#include <fstream>
#include "View.h"

class Controller{
public:
	Controller(Shop& _shop, View& _view) : shop(_shop), 
											view(_view) {}
	void execute_cmd(int cmd);
	void cli();
	int validate_integer(std::string prompt);
	void new_robot_part();
	void new_robot_model();
	void view_robot_parts();
	void create_new_customer();
	void create_new_sales_associate();
	void create_order();
	void view_orders();
	void use_test();
	void view_customers();
	void view_sales_associates();
	void load_data();
	void save_data();


private:
	Shop& shop;
	View& view;


};

#endif

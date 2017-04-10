#ifndef GUICONTROLLER_H
#define GUICONTROLLER_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_ask.H>
#include <Fl/Fl_Menu_Bar.H>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "View.h"


class GuiController{
public:
	GuiController(Shop& _shop, View& _view) : shop(_shop), 
											view(_view) {}
	void execute_cmd(int cmd);
	void cli();
	int validate_integer(std::string title, std::string prompt, int min_num, int max_num);
	double validate_double(std::string title, std::string prompt, double min_num, double max_num);
	std::string get_string(std::string title, std::string prompt);

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

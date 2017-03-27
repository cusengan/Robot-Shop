#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <sstream>
#include <ios>
#include "View.h"

class Controller{
public:
	Controller(Shop& market, View& _view) : shop(market), 
											view(_view) {}
	void execute_cmd(int cmd);
	void cli();

private:
	Shop& shop;
	View& view;


};

#endif
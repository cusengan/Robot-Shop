#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>

class Controller{
public:
	Controller(Shop& _shop, View& _view) : shop(_shop), 
											view(_view) {}
	void execute_cmd(int cmd);

private:
	Shop& shop;
	View& view;


};

#endif
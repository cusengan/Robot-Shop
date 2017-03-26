#ifndef SHOP_H
#define SHOP_H

#include "Robot_model.h"

class Shop{
public:
	create_new_robot_parts();
	create_new_robot_model();
private:
	Robot_part robot_parts;
	Robot_model robot_models;
};

#endif
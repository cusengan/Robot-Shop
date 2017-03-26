#ifndef SHOP_H
#define SHOP_H

#include "Robot_model.h"
#include "Torso.h"
#include "Head.h"
#include "Battery.h"
#include "Locomotor.h"
#include "Arm.h"

#include <vector>

class Shop{
public:
	void create_new_robot_parts();
	void create_new_robot_model();
private:
	// Robot_part robot_parts;
	// Robot_model robot_models;
	std::vector<Robot_model> rebot_models;
	std::vector<Torso> torsos;
	std::vector<Head> heads;
	std::vector<Locomotor> locomotors;
	std::vector<Battery> batteries;
	std::vector<Arm> arms;

};

#endif
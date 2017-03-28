#ifndef SHOP_H
#define SHOP_H

#include "Robot_model.h"
#include "Torso.h"
#include "Head.h"
#include "Battery.h"
#include "Locomotor.h"
#include "Arm.h"
#include "SalesAssociate.h"
#include "Customer.h"

#include <vector>

class Shop{
public:
	void create_new_robot_arm(std::string name, int model_num);
	void create_new_robot_head(std::string name, int model_num);
	void create_new_robot_torso(std::string name, int model_num);
	void create_new_robot_battery(std::string name, int model_num);
	void create_new_robot_locomotor(std::string name, int model_num);
	void create_new_sales_associate(std::string name, int id);
	void create_new_beloved_customer(std::string name, int id, int phone, std::string email);	
	
	Arm get_robot_arm(int index);
	Head get_robot_head(int index);
	Torso get_robot_torso(int index);
	Battery get_robot_battery(int index);
	Locomotor get_robot_locomotor(int index);
	Robot_model get_robot_model(int index);
	void create_new_robot_model(std::string name,
								int model_num,
								Arm arm, 
								Head head, 
								Torso torso,
								Battery battery, 
								Locomotor locomotor);
	int number_of_arms();
	int number_of_torsos();
	int number_of_batteries();
	int number_of_heads();
	int number_of_locomotors();
	int number_of_models();
	int number_of_associates();
	int number_of_customers();

private:
	std::vector<Robot_model> robot_models;
	std::vector<Torso> torsos;
	std::vector<Head> heads;
	std::vector<Locomotor> locomotors;
	std::vector<Battery> batteries;
	std::vector<Arm> arms;
	std::vector<SalesAssociate> associates;
	std::vector<Customer> customers;
};

#endif

#include "Shop.h"

void Shop::create_new_robot_arm(std::string name, int model_num){

	Arm arm(name, model_num);
	arms.push_back(arm);

}

void Shop::create_new_robot_head(std::string name, int model_num){

	Head head(name, model_num);
	heads.push_back(head);

}

void Shop::create_new_robot_torso(std::string name, int model_num){

	Torso Torso(name, model_num);
	torsos.push_back(Torso);

	
	

}

void Shop::create_new_robot_battery(std::string name, int model_num){

	Battery battery(name, model_num);
	batteries.push_back(battery);

}

void Shop::create_new_robot_locomotor(std::string name, int model_num){


	Locomotor locomotor(name, model_num);
	locomotors.push_back(locomotor);

}

void Shop::create_new_sales_associate(std::string name, int id){
	
	SalesAssociate associate(name, id);
	associates.push_back(associate);

}

void Shop::create_new_beloved_customer
(std::string name, int id, int phone, std::string email){

	Customer customer(name, id, phone, email);
	customers.push_back(customer);

}

Arm Shop::get_robot_arm(int index){
	return arms[index];

}

Head Shop::get_robot_head(int index){
	return heads[index];

}

Torso Shop::get_robot_torso(int index){
	return torsos[index];

}

Battery Shop::get_robot_battery(int index){
	return batteries[index];

}

Locomotor Shop::get_robot_locomotor(int index){
	return locomotors[index];
}

Robot_model Shop::get_robot_model(int index){
	return robot_models[index];
}

void Shop::create_new_robot_model(std::string name,
								int model_num,
								Arm arm, 
								Head head, 
								Torso torso,
								Battery battery, 
								Locomotor locomotor){




	Robot_model Robot(name, model_num, arm, head, torso,
						battery, locomotor);

	robot_models.push_back(Robot);

}

int Shop::number_of_arms(){
	return arms.size();
}

int Shop::number_of_torsos(){
	return torsos.size();
}

int Shop::number_of_batteries(){
	return batteries.size();
}

int Shop::number_of_heads(){
	return heads.size();
}

int Shop::number_of_locomotors(){
	return locomotors.size();
}

int Shop::number_of_models(){
	return robot_models.size();
}

int Shop::number_of_associates(){
        return associates.size();
}

int Shop::number_of_customers(){
        return customers.size();
}



#include "Robot_model.h"

std::string Robot_model::get_info(){
	std::string info = "Name: " + name + "\n" 
						"Model number: " + std::to_string(model_number) + "\n"
						"Cost: " + std::to_string(cost()) + "\n";
	return info;
}

std::string Robot_model::save_to_file(){
	std::string info = "Robot_Identifier\n" + name + "\n" 
						+ std::to_string(model_number) + "\n"
						+ std::to_string(choices[0]) + "\n"
						+ std::to_string(choices[1]) + "\n"
						+ std::to_string(choices[2]) + "\n"
						+ std::to_string(choices[3]) + "\n"
						+ std::to_string(choices[4]);
	return info;
}

Arm Robot_model::get_robot_arm(){
	return arm;

}

Head Robot_model::get_robot_head(){
	return head;
}

Torso Robot_model::get_robot_torso(){
	return torso;
}

Battery Robot_model::get_robot_battery(){
	return battery;
}

Locomotor Robot_model::get_robot_locomotor(){
	return locomotor;
}

double Robot_model::cost(){
	return torso.get_price() + head.get_price() + arm.get_price() + locomotor.get_price() + battery.get_price();

}

void Robot_model::add_choice(int choice){
	choices.push_back(choice);

}

double Robot_model::max_speed(){

}

double Robot_model::max_battery_life(){

}
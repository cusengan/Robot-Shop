#include "Robot_model.h"

std::string Robot_model::get_info(){
	std::string info = "Name: " + name + "\n" 
						"Model number: " + std::to_string(model_number) + "\n";
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

}

double Robot_model::max_speed(){

}

double Robot_model::max_battery_life(){

}
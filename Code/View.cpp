#include "View.h"


std::string View::get_menu(){

string menu = R"(
====================================================
Which one of these options would you like to choose? 
====================================================

1)Create a robot part 
2)Create a robot model 
3)View robot parts 
4)View robot models
)"

return menu;

}

std::string View::get_robot_models(){




}

std::string View::get_robot_parts(){

std::string part;

std::string list = R"(
==================
List of )"+ part + R"( 
==================
)"

int choice;

std::cout << "Which one of these parts would you like to view?" << std::endl;
std::cout << "1) Head" << std::endl;
std::cout << "2) Torso" <<std::endl;
std::cout << "3) Arm" <<std::endl;
std::cout << "4) Battery" <<std::endl;
std::cout << "5) Locomotor" <<std::endl;

std::cin >> choice;
std::cin.ignore();

switch (choice) {

case 1: part = "Heads";
for (int i = 0; i < shop.number_of_heads(); ++i) {
	list += "Part #"+std::to_string(i)+'\n';
	list += shop.get_robot_head(i)+'\n';
};
break;

case 2: part = "Torsos"; 
for (int i = 0; i < shop.number_of_torsos(); ++i) {
	list += "Part #"+std::to_string(i)+'\n';
	list += shop.get_robot_torso(i)+'\n';
};
break;

case 3: part = "Arms";
for (int i = 0; i < shop.number_of_arms(); ++i) {
	list += "Part #"+std::to_string(i)+'\n';
	list += shop.get_robot_arm(i)+'\n';
};
break;

case 4: part = "Batteries";
for (int i = 0; i < shop.number_of_batteries(); ++i) {
	list += "Part #"+std::to_string(i)+'\n';
	list += shop.get_robot_battery(i)+'\n';
};
break;

case 5: part = "Locomotors"; 
for (int i = 0; i < shop.number_of_locomotors(); ++i) {
	list += "Part #"+std::to_string(i)+'\n';
	list += shop.get_robot_locomotor(i)+'\n';
};
break;

}// end switch

return list;

}


<<<<<<< HEAD
=======


>>>>>>> f8f1b4ec69fa0c53f8018b726a0e5f73cf452882

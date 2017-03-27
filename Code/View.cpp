#include "View.h"


std::string View::get_menu(){

std::string menu = R"(
====================================================
Which one of these options would you like to choose? 
====================================================

1)Create a robot part 
2)Create a robot model 
3)View robot parts 
4)View robot models
0)Exit
)";

return menu;

}

std::string View::get_robot_models(){




}

std::string View::parts_menu(){

std::string menu = R"(Which of these parts would you like to view?
1) Head
2) Torso
3) Arm
4) Battery
5) Locomotor
)";

return menu;


}

std::string View::get_robot_parts(int choice){

std::string part = "parts";

std::string list = R"(
==================
List of )"+ part + R"( 
==================
)";

switch (choice) {

case 1: part = "Heads";
for (int i = 0; i < shop.number_of_heads(); ++i) {
	list += "Part #"+std::to_string(i)+'\n';
	list += shop.get_robot_head(i).get_info() +'\n';
};
break;

case 2: part = "Torsos"; 
for (int i = 0; i < shop.number_of_torsos(); ++i) {
	list += "Part #"+std::to_string(i)+'\n';
	list += shop.get_robot_torso(i).get_info() +'\n';
};
break;

case 3: part = "Arms";
for (int i = 0; i < shop.number_of_arms(); ++i) {
	list += "Part #"+std::to_string(i)+'\n';
	list += shop.get_robot_arm(i).get_info() +'\n';
};
break;

case 4: part = "Batteries";
for (int i = 0; i < shop.number_of_batteries(); ++i) {
	list += "Part #"+std::to_string(i)+'\n';
	list += shop.get_robot_battery(i).get_info() +'\n';
};
break;

case 5: part = "Locomotors"; 
for (int i = 0; i < shop.number_of_locomotors(); ++i) {
	list += "Part #"+std::to_string(i)+'\n';
	list += shop.get_robot_locomotor(i).get_info() +'\n';
};
break;

}// end switch

return list;

}

std::string View::create_a_part(){

}




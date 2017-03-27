#include "Controller.h"

// std::string name;
// 	int model_num;

// 	std::cout << "Name?" << std::endl;
// 	getline(std::cin, name);

// 	std::cout << "Model number?" << std::endl;
// 	std::cin >> model_num;
// 	std::cin.ignore();
//these were in the create_robot_part functions in shop

void Controller::execute_cmd(int cmd){
	if(cmd == 1){
		
		//variable declarations
		std::string name;
		int model_num, choice;
		
		//start submenu here
		std::cout << view.view_parts_menu() << std::endl;
                std::cout << "Choose an action: ";
                std::cin >> choice;
                std::cin.ignore();
		
		//post-select action
		std::cout << "Name?" << std::endl;
		getline(std::cin, name);

		std::cout << "Model number?" << std::endl;
		std::cin >> model_num;
		std::cin.ignore();
		
		//actual storing 
		switch(choice){
		case 1: shop.create_new_robot_head(name, model_num); break;
		case 2: shop.create_new_robot_torso(name, model_num); break;
		case 3: shop.create_new_robot_arm(name, model_num); break;
		case 4: shop.create_new_robot_battery(name, model_num); break;
		case 5: shop.create_new_robot_locomotor(name, model_num); break;
		
		}


	}
	else if(cmd ==2){

	}
	else if(cmd == 3){
		int choice;
		std::cout << view.parts_menu() << std::endl;
		std::cout << "Choose an action: ";
		std::cin >> choice;
		std::cin.ignore();
		std::cout << view.get_robot_parts(choice) << std::endl;

	}

	else if(cmd == 4){

	}
	else if(cmd ==0){}


}

void Controller::cli(){
	int cmd = -1;
	while(cmd != 0){
		std::cout << view.get_menu() << std::endl;
		std::cout << "Choose an action: ";
		std::cin >> cmd;
		std::cin.ignore();
		execute_cmd(cmd);

	} //loops till manual exit at 0

}

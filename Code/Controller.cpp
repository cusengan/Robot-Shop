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
		std::string name;
		int model_num;

		std::cout << "Name?" << std::endl;
		getline(std::cin, name);

		std::cout << "Model number?" << std::endl;
		std::cin >> model_num;
		std::cin.ignore();


	}
	else if(cmd ==2){

	}
	else if(cmd == 3){
		int choice;
		std::cout << view.view_parts_menu() << std::endl;
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

	}

}
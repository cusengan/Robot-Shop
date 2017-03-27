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
	
	//create a part
	if(cmd == 1){
		
		//variable declarations
		std::string name;
		int model_num, choice;
		
		//start submenu here
		std::cout << view.parts_menu() << std::endl;
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
	
	//create a model
	else if(cmd ==2){
	
	//variable declarations
        std::string name;
        int model_num, index;
	
	//if not enough parts for a model
		
	//tells you which vectors are null
	if (shop.number_of_arms() == 0){
		std::cout <<"There aren't any arm parts for you to make a model"<<std::endl;
	}
	if (shop.number_of_heads() == 0){
		std::cout <<"There aren't any head parts for you to make a model"<<std::endl;
	}
	if (shop.number_of_torsos() == 0){
		std::cout <<"There aren't any torso parts for you to make a model"<<std::endl;
	}
	if (shop.number_of_batteries() == 0){
		std::cout <<"There aren't any battery parts for you to make a model"<<std::endl;
	}
	if (shop.number_of_locomotors() == 0) {
		std::cout << "There aren't any locomotor parts for you to make a model"<<std::endl;
	}

	//this actually throws you out 
	if ( 
        shop.number_of_arms() == 0 ||
        shop.number_of_heads() == 0 ||
        shop.number_of_torsos() == 0 ||
        shop.number_of_batteries() == 0 ||
        shop.number_of_locomotors() == 0 ){
	//do nothing
	}
	
	//all parts needed are presence
	else {
	//model info
		std::cout << "Name?" << std::endl;
                getline(std::cin, name);
                std::cout << "Model number?" << std::endl;
                std::cin >> model_num;
                std::cin.ignore();
	//assigning parts to the model
	
	}
	
	}//end cmd 2
		
	
	//view parts
	else if(cmd == 3){
		int choice;
		//submenu
		std::cout << view.parts_menu() << std::endl;
		std::cout << "Choose an action: ";
		std::cin >> choice;
		std::cin.ignore();
		//print a list of the specific parts
		std::cout << view.get_robot_parts(choice) << std::endl;

	}

	//view models
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

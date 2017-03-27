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
		std::string name, strInput;
		int model_num, choice;
		
		//start submenu here

		while(true){ //this loop validates integer input
			std::cout << view.parts_menu() << std::endl;
			std::cout << "Choose an action: ";
			getline(std::cin, strInput);
			//This will convert string to number safely
			std::stringstream myStream(strInput);
			if((myStream >> choice)){
				break;
			}
			std::cout << "\nPlease enter a valid integer" << std::endl;
		}
		
		//post-select action
		std::cout << "Name?" << std::endl;
		getline(std::cin, name);

		while(true){ //this loop validates integer input
			std::cout << "Enter a model number: ";
			getline(std::cin, strInput);
			//This will convert string to number safely
			std::stringstream myStream(strInput);
			if((myStream >> model_num)){
				break;
			}
			std::cout << "\nPlease enter a valid integer" << std::endl;
		}
		
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
        std::string name, strInput;
        int model_num, 
	    arm_num, 
	    head_num,
	    torso_num,
	    battery_num,
	    locomotor_num;
	
	//if not enough parts for a model
        if (
        shop.number_of_arms() == 0 ||
        shop.number_of_heads() == 0 ||
        shop.number_of_torsos() == 0 ||
        shop.number_of_batteries() == 0 ||
        shop.number_of_locomotors() == 0 ){
 
	std::cerr << std::endl << "Error! You cannot make a model for the following reason or reasons:" << std::endl;
	
        }

	//tells you which vectors are null
	if (shop.number_of_arms() == 0){
		std::cout <<"-There aren't any arm parts for you to make a model"<<std::endl;
	}
	if (shop.number_of_heads() == 0){
		std::cout <<"-There aren't any head parts for you to make a model"<<std::endl;
	}
	if (shop.number_of_torsos() == 0){
		std::cout <<"-There aren't any torso parts for you to make a model"<<std::endl;
	}
	if (shop.number_of_batteries() == 0){
		std::cout <<"-There aren't any battery parts for you to make a model"<<std::endl;
	}
	if (shop.number_of_locomotors() == 0) {
		std::cout << "-There aren't any locomotor parts for you to make a model"<<std::endl;
	}

	//all parts needed are present
	if ( 
        shop.number_of_arms() != 0 &&
        shop.number_of_heads() != 0 &&
        shop.number_of_torsos() != 0 &&
        shop.number_of_batteries() != 0 &&
        shop.number_of_locomotors() != 0 ){
	
	 //model info
                std::cout << "Name?" << std::endl;
                getline(std::cin, name);
               while(true){ //this loop validates integer input

					std::cout << "Enter a model number: ";
					getline(std::cin, strInput);

					//This will convert string to number safely
					std::stringstream myStream(strInput);
					if((myStream >> model_num)){
						break;
					}
					std::cout << "\nPlease enter a valid integer" << std::endl;
				}
        //assigning parts to the model
	//arm
        std::cout << view.get_robot_parts(3) << std::endl;
		std::cout<<"Please input the part # for the arm you would like for this model:"<<std::endl;
				std::cin >> arm_num;
				if(arm_num >= shop.number_of_arms()){
					std::cerr << "Error! Invalid input." << std::endl;
					return;
				}
                std::cin.ignore();
	//head
        std::cout << view.get_robot_parts(1) << std::endl;
		std::cout<<"Please input the part # for the head you would like for this model:"<<std::endl;
                std::cin >> head_num;
                if(arm_num >= shop.number_of_heads()){
					std::cerr << "Error! Invalid input." << std::endl;
					return;
				}
                std::cin.ignore();
	
	//torso
        std::cout << view.get_robot_parts(2) << std::endl;
		std::cout<<"Please input the part # for the torso you would like for this model:"<<std::endl;
				if(arm_num >= shop.number_of_torsos()){
					std::cerr << "Error! Invalid input." << std::endl;
					return;
				}
                std::cin >> torso_num;
                std::cin.ignore();
		
	//battery
        std::cout << view.get_robot_parts(4) << std::endl;
		std::cout<<"Please input the part # for the battery you would like for this model:"<<std::endl;
				if(arm_num >= shop.number_of_batteries()){
					std::cerr << "Error! Invalid input." << std::endl;
					return;
				}
                std::cin >> battery_num;
                std::cin.ignore();
	
	//locomotor
        std::cout << view.get_robot_parts(5) << std::endl;
		std::cout<<"Please input the part # for the arm you would like for this model:"<<std::endl;
				
				if(arm_num >= shop.number_of_locomotors()){
					std::cerr << "Error! Invalid input." << std::endl;
					return;
				}
                std::cin >> locomotor_num;
                std::cin.ignore();

	//put the parts together
		shop.create_new_robot_model(
		name,
		model_num,
		shop.get_robot_arm(arm_num),
		shop.get_robot_head(head_num),
		shop.get_robot_torso(torso_num),
		shop.get_robot_battery(battery_num),
		shop.get_robot_locomotor(locomotor_num));
		}
	}//end cmd 2
	
	//view parts
	else if(cmd == 3){
		int choice;
		std::string strInput;
		//submenu

		while(true){ //this loop validates integer input
			std::cout << view.parts_menu() << std::endl;

			std::cout << "Choose an action: ";
			getline(std::cin, strInput);

			//This will convert string to number safely
			std::stringstream myStream(strInput);
			if((myStream >> choice)){
				break;
			}
			std::cout << "\nPlease enter a valid integer" << std::endl;
		}

		if(choice < 1 || choice > 5){
			std::cerr << "Error! Invalid input" << std::endl;
			return;
		}

		//print a list of the specific parts
		std::cout << view.get_robot_parts(choice) << std::endl;

	}

	//view models
	else if(cmd == 4){
		
	std::cout << view.get_robot_models() << std::endl;

	}
	else if(cmd == 0){

	}
	else if(cmd == 99){//testing 
		shop.create_new_robot_arm("Arm1", 900);
		shop.create_new_robot_head("Head1", 12221);
		shop.create_new_robot_torso("Torso1", 8211);
		shop.create_new_robot_battery("Batter1", 11711);
		shop.create_new_robot_locomotor("Locomotor1", 1111);
		shop.create_new_robot_model("RoboMan", 999811,
									shop.get_robot_arm(0),
									shop.get_robot_head(0),
									shop.get_robot_torso(0),
									shop.get_robot_battery(0),
									shop.get_robot_locomotor(0));

	}
	else{
		std::cerr << "Error! Invalid input" << std::endl;
	}



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

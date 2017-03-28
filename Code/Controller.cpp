#include "Controller.h"

void Controller::execute_cmd(int cmd){
	
	//create a part
	if(cmd == 1){
		
		//variable declarations
		std::string name, strInput;
		int model_num, choice;
		
		//start submenu here

		choice = validate_integer(view.parts_menu()); //getting choice for main menu
		
		
		//post-select action
		std::cout << "Name?" << std::endl;
		getline(std::cin, name);

		model_num = validate_integer("Enter a model number: ");//getting user input for model number

		
		
		//actual storing 
		switch(choice){
		case 1: shop.create_new_robot_head(name, model_num); break;
		case 2: shop.create_new_robot_torso(name, model_num); break;
		case 3: shop.create_new_robot_arm(name, model_num); break;
		case 4: shop.create_new_robot_battery(name, model_num); break;
		case 5: shop.create_new_robot_locomotor(name, model_num); break;
		
		}

	}//****************** END cmd == 1 *********************	

	//create a model
	else if(cmd == 2){

		new_robot_model();
	
	
	}//****************** END cmd == 2 ********************* 
	
	//view parts
	else if(cmd == 3){
		int choice;
		std::string strInput;
		//submenu

		choice = validate_integer(view.parts_menu()); //getting user input for choice
		

		if(choice < 1 || choice > 5){
			std::cerr << "Error! Invalid input" << std::endl;
			return;
		}

		//print a list of the specific parts
		std::cout << view.get_robot_parts(choice) << std::endl;

	}//****************** END cmd == 3 ********************* 

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

	}//****************** END cmd == 4 ********************* 
	
	//create a customer
	else if (cmd == 5){
	
		//variable declaration
		std::string name, email, input;
		int id, phone;
	
		std::cout<<"Enter beloved customer's name: ";
		getline(std::cin, name);
		
		//ask for number and validate it is a number

		id = validate_integer("Enter the beloved customer's id: ");
                
		//ask for number and validate it is a number

		phone = validate_integer("Enter the beloved customer's phone number: ");
                
		
		std::cout<<"Enter beloved customer's email: ";
                getline(std::cin, email);
	
		shop.create_new_beloved_customer(name, id, phone, email);
	
	}//****************** END cmd == 5 ********************* 
	
	//create a sales associate
	else if (cmd == 6){
        	
		//variable declaration
                std::string name, input;
                int id;

                std::cout<<"Enter the sales associate's name: ";
                getline(std::cin, name); 
        
		//ask for number and validate it is a number

        id = validate_integer("Enter the sales associate's id: ");
		
        	
		shop.create_new_sales_associate(name, id);
		
        }//****************** END cmd == 6 *********************
	
	//load
	else if(cmd == 7){
	
	
	}//****************** END cmd == 7 *********************
	
	//save
	else if(cmd == 8){
	
	
	}//****************** END cmd == 8 *********************
	
	//for out of bound errors
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

int Controller::validate_integer(std::string prompt){
	std::string strInput;
	int num;

	while(true){ //this loop validates integer input
			std::cout << prompt;
			getline(std::cin, strInput);
			//This will convert string to number safely
			std::stringstream myStream(strInput);
			if((myStream >> num)){
				break;
			}
			std::cout << "\nPlease enter a valid integer" << std::endl;
		}

	return num;



}

void Controller::new_robot_model(){

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

                model_num = validate_integer("Enter a model number: "); //getting user input for model number
               
        //assigning parts to the model
	//arm
        std::cout << view.get_robot_parts(3) << std::endl;
        arm_num = validate_integer("Please input the part # for the arm you would like for this model:\n");
				if(arm_num >= shop.number_of_arms()){
					std::cerr << "Error! Invalid input." << std::endl;
					return;
				}
                
	//head
        std::cout << view.get_robot_parts(1) << std::endl;
        head_num = validate_integer("Please input the part # for the head you would like for this model:\n");
                if(head_num >= shop.number_of_heads()){
					std::cerr << "Error! Invalid input." << std::endl;
					return;
				}
                
	
	//torso
        std::cout << view.get_robot_parts(2) << std::endl;
        torso_num = validate_integer("Please input the part # for the torso you would like for this model:\n");
				if(torso_num >= shop.number_of_torsos()){
					std::cerr << "Error! Invalid input." << std::endl;
					return;
				}
                
		
	//battery
        std::cout << view.get_robot_parts(4) << std::endl;
        battery_num = validate_integer("Please input the part # for the battery you would like for this model:\n");
				if(battery_num >= shop.number_of_batteries()){
					std::cerr << "Error! Invalid input." << std::endl;
					return;
				}
                
	
	//locomotor
        std::cout << view.get_robot_parts(5) << std::endl;
        locomotor_num = validate_integer("Please input the part # for the arm you would like for this model:\n");
				
				if(locomotor_num >= shop.number_of_locomotors()){
					std::cerr << "Error! Invalid input." << std::endl;
					return;
				}
                

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

}

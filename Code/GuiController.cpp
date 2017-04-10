#include "GuiController.h"


void GuiController::execute_cmd(int cmd){
	
	switch(cmd){
		case 1: new_robot_part(); break;
		default: std::cerr << "Error! Invalid input" << std::endl; break;
	}
	


}

int GuiController::validate_integer(std::string title, std::string prompt, int min_num, int max_num){

	int num;
	std::string error = "\nPlease enter a valid integer";
	while(true){ //this loop validates integer input
			fl_message_title(title.c_str());
			fl_message_icon()->label("I");
			num = atoi(fl_input(prompt.c_str(), 0));
			if((min_num <= num && num <= max_num)){
				break;
			}else{
				fl_message_title("Invalid Input");
				fl_message_icon()->label("!");
				fl_message(error.c_str());
			}
		}

	return num;

}

double GuiController::validate_double(std::string title, std::string prompt, double min_num, double max_num){

        double  num;
        std::string error = "\nPlease enter a valid double";
        while(true){ //this loop validates integer input
                        fl_message_title(title.c_str());
                        fl_message_icon()->label("I");
                        num = atoi(fl_input(prompt.c_str(), 0));
                        if((0 <= min_num && num <= max_num)){
                                break;
                        }else{
                                fl_message_title("Invalid Input");
                                fl_message_icon()->label("!");
                                fl_message(error.c_str());
                        }
                }

        return num;

}


std::string GuiController::get_string(std::string title, std::string prompt){
	
	fl_message_title (title.c_str());
	fl_message_icon()->label("S");
	std::string result = fl_input(prompt.c_str(), 0);
	return result;
}

void GuiController::new_robot_part(){
	//variable declarations
		std::string name, description, part;
		int model_num, choice, price;
		int max_choice = 5, min_choice = 1;
		
		//start submenu here
		
		choice = validate_integer("Which part would you like to add?", view.create_a_part_menu(), min_choice, max_choice); //getting choice for main menu
			
		switch (choice){
		case 1: part = "Head" ;break;
		case 2: part = "Torso" ;break;
		case 3: part = "Arm" ;break;
		case 4: part = "Battery" ;break;
		case 5: part = "Locomotor" ;break;
		}
		
		//post-select action
		name = get_string(part, "Enter a name: ");

		model_num = validate_integer(part, "Enter a model number: ", 0, 9999999);//getting user input for model number

		price = validate_double(part, "Enter a price: ", 0, 99999999);
		 
		description = get_string(part, "Enter a description: ");	
		
		//actual storing 
		switch(choice){

		case 1: shop.create_new_robot_head(name, model_num, price, description); break;
		case 2: shop.create_new_robot_torso(name, model_num, price, description); break;
		case 3: shop.create_new_robot_arm(name, model_num, price, description); break;
		case 4: shop.create_new_robot_battery(name, model_num, price, description); break;
		case 5: shop.create_new_robot_locomotor(name, model_num, price, description); break;
		

		
		}
}




void GuiController::cli(){
	
	int cmd = -1;
	std::string menu = view.get_menu() + "\nCommand? ";
	
	while(cmd != 0){
		cmd = atoi(fl_input(menu.c_str(),0)); 
		execute_cmd(cmd);

	} //loops till manual exit at 0

}

#include "Controller.h"

void Controller::execute_cmd(int cmd){
	
	switch(cmd){
		case 1: new_robot_part(); break;
		case 2: new_robot_model(); break;
		case 3: view_robot_parts(); break;
		case 4: std::cout << view.get_robot_models() << std::endl; break;
		case 5: create_new_customer(); break;
		case 6: create_new_sales_associate(); break;
		case 7: create_order(); break;
		case 8: view_customers(); break;
		case 9: view_sales_associates(); break;
		case 10: view_orders(); break;
		case 11: load_data(); break; //load
		case 12: save_data(); break; //save
		case 0: break;//exit
		case 99: use_test(); break;
		default: std::cerr << "Error! Invalid input" << std::endl; break;
	}
	


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
			std::cout << "\nPlease enter a valid integer\n" << std::endl;
		}

	return num;



}

void Controller::new_robot_part(){
	//variable declarations
		std::string name, strInput, description;
		int model_num, choice, price;
		
		//start submenu here

		choice = validate_integer(view.create_a_part_menu()); //getting choice for main menu
		
		
		//post-select action
		std::cout << "Enter a name: " << std::endl;
		getline(std::cin, name);


		model_num = validate_integer("Enter a model number: ");//getting user input for model number

		

		
		while(true){ //this loop validates integer input
                        std::cout << "Enter a a price (usd): ";
                        getline(std::cin, strInput);
                        //This will convert string to number safely
                        std::stringstream myStream(strInput);
                        if((myStream >> price)){
                                break;
                        }
                        std::cout << "\nPlease enter a valid price\n" << std::endl;
                }
		
		std::cout << "Enter a description: " << std::endl;
                getline(std::cin, description);	
		
		//actual storing 
		switch(choice){

		case 1: shop.create_new_robot_head(name, model_num, price, description); break;
		case 2: shop.create_new_robot_torso(name, model_num, price, description); break;
		case 3: shop.create_new_robot_arm(name, model_num, price, description); break;
		case 4: shop.create_new_robot_battery(name, model_num, price, description); break;
		case 5: shop.create_new_robot_locomotor(name, model_num, price, description); break;
		

		
		}
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
		shop.get_robot_locomotor(locomotor_num),
		arm_num, head_num, torso_num, battery_num, locomotor_num);
		}

}

void Controller::view_robot_parts(){
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

}

void Controller::create_new_customer(){
	//variable declaration
		std::string name, email, input;
		int id, phone;
	
		std::cout<<"Enter beloved customer's name: ";
		getline(std::cin, name);
		
		//ask for number and validate it is a number
                while (true) {
                        std::cout << "Enter the beloved customer's id: ";
                        getline(std::cin, input);
                        std::stringstream myStream(input);
                        if((myStream >> id)){
                                break;
                        }
                        std::cout<<"\nPlease enter valid integers\n"<<std::endl;
                }
		
		//ask for number and validate it is a number
                while (true) {
                        std::cout << "Enter the beloved customer's phone number: ";
                        getline(std::cin, input);
                        std::stringstream myStream(input);
                        if((myStream >> phone)){
                                break;
                        }
                        std::cout<<"\nPlease enter valid integers\n"<<std::endl;
                }
		
		std::cout<<"Enter beloved customer's email: ";
                getline(std::cin, email);
	
		shop.create_new_beloved_customer(name, id, phone, email);
}

void Controller::create_new_sales_associate(){
	//variable declaration
    std::string name, input;
    int id;

    std::cout<<"Enter the sales associate's name: ";
    getline(std::cin, name); 
        
	//ask for number and validate it is a number
	while (true) {
		std::cout << "Enter the sales associate's id: ";
		getline(std::cin, input);
		std::stringstream myStream(input);
		if((myStream >> id)){
			break;
		}
		std::cout<<"\nPlease enter valid integers\n"<<std::endl;
	}
    	
	shop.create_new_sales_associate(name, id);
}

void Controller::create_order(){

	int model, seller, customer;

	//////// Choose a robot model /////////
	std::cout << view.get_robot_models() << std::endl;
	model = validate_integer("What robot model is being bought?: ");

	if(model < 0 || model >= shop.number_of_robot_models()){
			std::cerr << "Error! Invalid input" << std::endl;
			return;
	}

	Robot_model robot = shop.get_robot_model(model);

	//////// Chose a customer ///////////

	std::cout << view.view_customers_menu() << std::endl;
	customer = validate_integer("Who is buying this robot?: ");

	if(customer < 0 || customer >= shop.number_of_customers()){
			std::cerr << "Error! Invalid input" << std::endl;
			return;
	}

	Customer buyer = shop.get_customer(customer);

	//////// Chose a seller ////////////
	
	std::cout << view.view_sales_associates_menu() << std::endl;
	seller = validate_integer("Who is selling this robot?: ");

	if(seller < 0 || seller >= shop.number_of_associates()){
			std::cerr << "Error! Invalid input" << std::endl;
			return;
	}

	SalesAssociate sales_associate = shop.get_sales_associate(seller);

	//////// Creating order object and adding it to the shop //////////

	shop.create_order(robot, buyer, sales_associate, model, seller, customer);
	






}

void Controller::use_test(){
	shop.create_new_robot_arm("Arm1", 900, 87, "One piece's Franky style arm");
	shop.create_new_robot_head("Head1", 12221, 145, "itd compatiple");
	shop.create_new_robot_torso("Torso1", 8211, 99, "Savaged from the power rangers' last robot");
	shop.create_new_robot_battery("Batter1", 11711, 61, "The energizer bunny got nothing on this");
	shop.create_new_robot_locomotor("Locomotor1", 1111, 77, "The loco locomotor" );
	shop.create_new_robot_model("RoboMan", 999811,
								shop.get_robot_arm(0),
								shop.get_robot_head(0),
								shop.get_robot_torso(0),
								shop.get_robot_battery(0),
								shop.get_robot_locomotor(0),
								0, 0, 0, 0, 0);
	shop.create_new_beloved_customer("William Truong", 5612221, 8172221345, "customer@gmail.com");
	shop.create_new_sales_associate("Nathan Drake", 22111);
	shop.create_order(shop.get_robot_model(0), shop.get_customer(0), shop.get_sales_associate(0), 0, 0, 0);
}

void Controller::view_customers(){

	std::cout << view.view_customers_menu();

}

void Controller::view_sales_associates(){
	std::cout << view.view_sales_associates_menu();
}

void Controller::view_orders(){
	std::cout << view.view_orders_menu();
}

//load_data()
//we are using the Indentifers in the file to know how to load the data, once we see an identifer,
//we take specific actions to the various robots/customers/associates etc.
//we known what steps to follow because we saved the data in such a way where we can just create parts

void Controller::load_data(){ 
	std::ifstream ifs{"data.txt"};
	std::string input, name, model_num, id, email, 
	phone, description, cost, choice1, choice2, choice3, choice4, choice5;


	if(!ifs) //if file is not opened
		std::cerr << "Can't open input file" << std::endl;
	else
		std::cout << "File opened" << std::endl;

	while(!ifs.eof()){ 
		getline(ifs, input);
		
		if(input == "Arm_Identifier"){
			getline(ifs, name);
			getline(ifs, model_num);
			getline(ifs, cost);
			getline(ifs, description);
			shop.create_new_robot_arm(name, atoi(model_num.c_str()), atof(cost.c_str()), description);

		}
		else if(input == "Head_Identifier"){
			getline(ifs, name);
			getline(ifs, model_num);
			getline(ifs, cost);
			getline(ifs, description);
			shop.create_new_robot_head(name, atoi(model_num.c_str()), atof(cost.c_str()), description);

		}
		else if(input == "Torso_Identifier"){
			getline(ifs, name);
			getline(ifs, model_num);
			getline(ifs, cost);
			getline(ifs, description);
			shop.create_new_robot_torso(name, atoi(model_num.c_str()), atof(cost.c_str()), description);

		}
		else if(input == "Battery_Identifier"){
			getline(ifs, name);
			getline(ifs, model_num);
			getline(ifs, cost);
			getline(ifs, description);
			shop.create_new_robot_battery(name, atoi(model_num.c_str()), atof(cost.c_str()), description);

		}
		else if(input == "Locomotor_Identifier"){
			getline(ifs, name);
			getline(ifs, model_num);
			getline(ifs, cost);
			getline(ifs, description);

			shop.create_new_robot_locomotor(name, atoi(model_num.c_str()), atof(cost.c_str()), description);

		}
		else if(input == "Robot_Identifier"){
			int model, first, second, third, fourth, fifth;

			getline(ifs, name);
			getline(ifs, model_num);
			model = atoi(model_num.c_str());
			getline(ifs, choice1);
			first = atoi(choice1.c_str());
			getline(ifs, choice2);
			second = atoi(choice2.c_str());
			getline(ifs, choice3);
			third = atoi(choice3.c_str());
			getline(ifs, choice4);
			fourth = atoi(choice4.c_str());
			getline(ifs, choice5);
			fifth = atoi(choice5.c_str());


			shop.create_new_robot_model(name, model,
											shop.get_robot_arm(first),
											shop.get_robot_head(second),
											shop.get_robot_torso(third),
											shop.get_robot_battery(fourth),
											shop.get_robot_locomotor(fifth),
											first, second, third, fourth, fifth);

		}
		else if(input == "Customer_Identifier"){
			getline(ifs, name);
			getline(ifs, id);
			getline(ifs, phone);
			getline(ifs, email);
			shop.create_new_beloved_customer(name, atoi(id.c_str()), atof(phone.c_str()), email);

		}
		else if(input == "Sales_Associate_Identifier"){
			getline(ifs, name);
			getline(ifs, id);
			shop.create_new_sales_associate(name, atoi(id.c_str()));

		}
		else if(input == "Order_Identifier"){
			int first, second, third;
			getline(ifs, choice1);
			first = atoi(choice1.c_str());
			getline(ifs, choice2);
			second = atoi(choice2.c_str());
			getline(ifs, choice3);
			third = atoi(choice3.c_str());
			shop.create_order(shop.get_robot_model(first), 
							shop.get_customer(second), 
							shop.get_sales_associate(third),
							first, second, third);
		}

		

	}

}

//save_data()
//using the save_to_file methods, we can save the information of the robots/customers/orders etc in a specific format
//so that we can load the data later using load_data()
void Controller::save_data(){
	std::ofstream ofs{"data.txt"};

	if(!ofs) 
		std::cerr << "Can't open output file" << std::endl;

	///// Saving Arms /////
	for(int i = 0; i < shop.number_of_arms(); i++){
		ofs << shop.get_robot_arm(i).save_to_file() << std::endl;
	}

	//// Saving Heads ////
	for(int i = 0; i < shop.number_of_heads(); i++){
		ofs << shop.get_robot_head(i).save_to_file() << std::endl;
	}

	//// Saving Torsos ////
	for(int i = 0; i < shop.number_of_torsos(); i++){
		ofs << shop.get_robot_torso(i).save_to_file() << std::endl;
	}

	//// Saving Batteries ////
	for(int i = 0; i < shop.number_of_batteries(); i++){
		ofs << shop.get_robot_battery(i).save_to_file() << std::endl;
	}

	//// Saving Locomotors ////
	for(int i = 0; i < shop.number_of_locomotors(); i++){
		ofs << shop.get_robot_locomotor(i).save_to_file() << std::endl;
	}

	//// Saving Robot Models///
	for(int i = 0; i < shop.number_of_robot_models(); i++){
		ofs << shop.get_robot_model(i).save_to_file() << std::endl;
	}

	//// Saving Customers ////
	for(int i = 0; i < shop.number_of_customers(); i++){
		ofs << shop.get_customer(i).save_to_file() << std::endl;
	}

	//// Saving Sales Associates ////
	for(int i = 0; i < shop.number_of_associates(); i++){
		ofs << shop.get_sales_associate(i).save_to_file() << std::endl;
	}

	//// Saving orders ////
	for(int i = 0; i < shop.number_of_orders(); i++){
		ofs << shop.get_order(i).save_to_file() << std::endl;
	}

	std::cout << "Information saved!" << std::endl;

}


void Controller::cli(){
	int cmd = -1;
	while(cmd != 0){
		std::cout << view.get_menu() << std::endl;
		cmd = validate_integer("Choose an action: ");
		execute_cmd(cmd);

	} //loops till manual exit at 0


}
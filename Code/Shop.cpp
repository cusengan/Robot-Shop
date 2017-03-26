#include "Shop.h"

void Shop::create_new_robot_parts(){ //i am testing this code, it will change

	int choice;
	std::string name;
	int model_num;
	
	// std::cout << "What kind of part would you like to make?" 
	// 			<< std::endl;

	// std::cin >> choice;

	std::cout << "Name?" << std::endl;
	getline(std::cin, name);

	std::cout << "Model number?" << std::endl;
	std::cin >> model_num;
	std::cin.ignore();
	Torso Torso(name, model_num);
	torsos.push_back(Torso);
	std::cout << torsos[0].get_info();


}

void Shop::create_new_robot_model(){

}
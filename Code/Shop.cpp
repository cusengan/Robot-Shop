#include "Shop.h"

void Shop::create_new_robot_parts(){ 

}

void Shop::create_new_robot_arm(){

	std::string name;
	int model_num;

	std::cout << "Name?" << std::endl;
	getline(std::cin, name);

	std::cout << "Model number?" << std::endl;
	std::cin >> model_num;
	std::cin.ignore();

	Arm arm(name, model_num);
	arms.push_back(arm);

}

void Shop::create_new_robot_head(){

	std::string name;
	int model_num;

	std::cout << "Name?" << std::endl;
	getline(std::cin, name);

	std::cout << "Model number?" << std::endl;
	std::cin >> model_num;
	std::cin.ignore();

	Head head(name, model_num);
	heads.push_back(head);

}

void Shop::create_new_robot_torso(){

	

	std::string name;
	int model_num;

	std::cout << "Name?" << std::endl;
	getline(std::cin, name);

	std::cout << "Model number?" << std::endl;
	std::cin >> model_num;
	std::cin.ignore();

	Torso Torso(name, model_num);
	torsos.push_back(Torso);

	
	

}

void Shop::create_new_robot_battery(){

	std::string name;
	int model_num;

	std::cout << "Name?" << std::endl;
	getline(std::cin, name);

	std::cout << "Model number?" << std::endl;
	std::cin >> model_num;
	std::cin.ignore();

	Battery battery(name, model_num);
	batteries.push_back(battery);

}

void Shop::create_new_robot_locomotor(){

	std::string name;
	int model_num;

	std::cout << "Name?" << std::endl;
	getline(std::cin, name);

	std::cout << "Model number?" << std::endl;
	std::cin >> model_num;
	std::cin.ignore();

	Locomotor locomotor(name, model_num);
	locomotors.push_back(locomotor);

}

// std::string name;
// 	int model_num

// std::cout << "Name?" << std::endl;
// 	getline(std::cin, name);

// 	std::cout << "Model number?" << std::endl;
// 	std::cin >> model_num;
// 	std::cin.ignore();
// 	Torso Torso(name, model_num);
// 	torsos.push_back(Torso);
// 	std::cout << torsos[0].get_info();


void Shop::create_new_robot_model(){

}
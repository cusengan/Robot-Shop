#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>

class Customer{


public:
	Customer(std::string _name, int _id, int _phone, std::string _email) :
	name(_name), id(_id), phone(_phone), email(_email) {}
	
	std::string get_info();

private:
	std::string name, email;
	int id, phone;



};

#endif 

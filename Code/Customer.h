#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>

class Person{

private:
	std::string name, email;
	int id, phone;

public:
	Person (std::string _name, int _id, int _phone, std::string _email):
	name(_name), id(_id), phone(_phone), email(_email) {}
	
	std::string get_info();

}

#endif "CUSTOMER_H"

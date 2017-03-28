#ifndef SALES_ASSOCIATE_H
#define SALES_ASSOCIATE_H

#include <iostream>
#include <string>

class SalesAssociate{

private:
	std::string name;
	int id;

public:
	SalesAssociate(std::string _name, int _id):
	name (_name), id (_id) {}
	
	std::string get_info();

}

#endif "SALES_ASSOCIATE_H"

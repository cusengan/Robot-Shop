#ifndef SALES_ASSOCIATE_H
#define SALES_ASSOCIATE_H

#include <iostream>
#include <string>

class SalesAssociate{

public:
	SalesAssociate(std::string _name, int _id):
	name (_name), id (_id) {}
	std::string get_info();

private:
	std::string name;
	int id;



};

#endif 

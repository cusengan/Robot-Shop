#ifndef ORDER_H
#define ORDER_H

#include "Robot_model.h"
#include "SalesAssociate.h"
#include "Customer.h"

class Order{
public:
	Order(Robot_model _model, 
		Customer _customer, 
		SalesAssociate _seller) : 
			
		model(_model), 
		customer(_customer),
		seller(_seller) {}

	std::string get_info();

private:
	Robot_model model;
	Customer customer;
	SalesAssociate seller;


};

#endif

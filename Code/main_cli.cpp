#include "Robot_part.h"
#include "Robot_model.h"
#include "Shop.h"
#include "View.h"
#include "Controller.h"

int main(){
	Shop shop;
	View view(shop);
	Controller controller(shop, view);


}
#include "Controller.h"


int main(){
	Shop shop;
	View view(shop);
	Controller controller(shop, view);
	controller.cli();


}

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Box.H>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>


//
//  Robot Part
//

class Robot_part{
public:
   Robot_part(std::string _name, 
         int _model_number, 
         double _price,
         std::string _description) : 
         name(_name), 
         model_number(_model_number), 
         price (_price),
         description(_description){}

   std::string get_info();
   std::string save_to_file();
   double get_price();

protected:
   std::string name;
   int model_number;
   double price;
   std::string description;
   std::string image_filename;

};


std::string Robot_part::get_info(){

   std::string info = "Name: " + name + '\n'+ 
   "Model number: " + std::to_string(model_number) + '\n'+
   +"Price (usd): " + std::to_string(price) + '\n'+
   "Description: " + description + '\n';
   return info;
}

double Robot_part::get_price(){
   return price;
}

std::string Robot_part::save_to_file(){

   std::string info = name + "\n" + std::to_string(model_number) + "\n" + std::to_string(price)
                  + "\n" + description;
   return info;

}


//
// Torso
//

class Torso : public Robot_part{

public:
   Torso(std::string _name,    
              int _model_number,
              double _price,
              std::string _description) :
        Robot_part(_name,
                   _model_number,
                   _price,
                   _description) {} 
   std::string save_to_file();
   std::string get_info();

private:
   int battery_components;
   int max_arms;

};


std::string Torso::get_info(){

   std::string info = Robot_part::get_info();
   return info;

}

std::string Torso::save_to_file(){
   std::string info = "Torso_Identifier\n"  + Robot_part::save_to_file();
   return info;
}


//
//  Arm
//

class Arm : public Robot_part{

public:
   Arm(std::string _name, 
       int _model_number,
       double _price,
       std::string _description) : 
   Robot_part(_name,
            _model_number,
         _price,
         _description) {}
   
   std::string get_info();
   std::string save_to_file();
   

private:
   
   double length;
   double max_power;
};


std::string Arm::get_info(){
   std::string info = Robot_part::get_info();
   return info;
}

std::string Arm::save_to_file(){
   std::string info = "Arm_Identifier\n"  + Robot_part::save_to_file();
   return info;
}


//
//  Head
//


class Head : public Robot_part{

public:
   Head(std::string _name,    
             int _model_number,
             double _price,
             std::string _description) :
        Robot_part(_name,
                   _model_number,
                   _price,
                   _description) {}
   std::string save_to_file();
   std::string get_info();

private:
   double power;
   
};

std::string Head::get_info(){
   std::string info = Robot_part::get_info();
   return info;
}

std::string Head::save_to_file(){
   std::string info = "Head_Identifier\n"  + Robot_part::save_to_file();
   return info;
}


//
//  Locomotor
//  

class Locomotor : public Robot_part{

public:
   Locomotor(std::string _name,    
                  int _model_number,
                  double _price,
                  std::string _description) :
        Robot_part(_name,
                   _model_number,
                   _price,
                   _description) {} 
   std::string save_to_file();
   std::string get_info();

private:
   double max_power;
};

std::string Locomotor::get_info(){
   std::string info = Robot_part::get_info();
   return info;
}

std::string Locomotor::save_to_file(){
   std::string info = "Locomotor_Identifier\n"  + Robot_part::save_to_file();
   return info;
}


//
//  Battery
//

class Battery : public Robot_part{

public:
   Battery(std::string _name, 
               int _model_number,
               double _price,
               std::string _description) :
        Robot_part(_name,
                   _model_number, 
                   _price, 
                   _description) {}
  std::string save_to_file();
   std::string get_info();

private:
   double power_available;
   double max_energy;

};

std::string Battery::get_info(){
   std::string info = Robot_part::get_info();
   return info;
}

std::string Battery::save_to_file(){
   std::string info = "Battery_Identifier\n"  + Robot_part::save_to_file();
   return info;
}


//
//  Model
//

class Robot_model{
public:
   Robot_model(std::string _name, 
	    std::string _image,
            int _model_num,
            Arm _arm, 
            Head _head, 
            Torso _torso,
            Battery _battery, 
            Locomotor _locomotor) : 

            name(_name), 
	    image(_image),
            model_number(_model_num), 
            arm(_arm),
            head(_head),
            torso(_torso),
            battery(_battery),
            locomotor(_locomotor){ }
   std::string save_to_file();
   std::string get_info();
   Arm get_robot_arm();
   Head get_robot_head();
   Torso get_robot_torso();
   Battery get_robot_battery();
   Locomotor get_robot_locomotor();
   void add_choice(int choice);
   double cost();
   double max_speed();
   double max_battery_life();
   std::string get_image();

private:
   std::string image;
   std::string name;
   int model_number;
   Torso torso;
   Head head;
   Locomotor locomotor;
   Arm arm;
   Battery battery;
   std::vector<int> choices;//this vector keeps track of what was chosen

};

std::string Robot_model::get_image(){
	std::string result = image;
	return result;
}

std::string Robot_model::get_info(){
   std::string info = "Name: " + name + "\n" 
                  "Model number: " + std::to_string(model_number) + "\n"
                  "Cost: " + std::to_string(cost()) + "\n";
   return info;
}

std::string Robot_model::save_to_file(){
   std::string info = "Robot_Identifier\n" 
		  + name + "\n" 
		  + image + "\n"
                  + std::to_string(model_number) + "\n"
                  + std::to_string(choices[0]) + "\n"
                  + std::to_string(choices[1]) + "\n"
                  + std::to_string(choices[2]) + "\n"
                  + std::to_string(choices[3]) + "\n"
                  + std::to_string(choices[4]);
   return info;
}

Arm Robot_model::get_robot_arm(){
   return arm;

}

Head Robot_model::get_robot_head(){
   return head;
}

Torso Robot_model::get_robot_torso(){
   return torso;
}

Battery Robot_model::get_robot_battery(){
   return battery;
}

Locomotor Robot_model::get_robot_locomotor(){
   return locomotor;
}

double Robot_model::cost(){
   return torso.get_price() + head.get_price() + arm.get_price() + locomotor.get_price() + battery.get_price();

}

void Robot_model::add_choice(int choice){
   choices.push_back(choice);

}

double Robot_model::max_speed(){

}

double Robot_model::max_battery_life(){

}


//
//  Sales Associates
//

class SalesAssociate{

public:
   SalesAssociate(std::string _name, int _id, int _sales):
   name (_name), id (_id), sales(_sales) {}
   std::string save_to_file();
   std::string get_info();
   std::string get_name();
   std::string get_sales();
   int get_sales_num();
   
   void Increase_sales();

private:
   std::string name;
   int id;
   int sales;

};

void SalesAssociate::Increase_sales(){
	sales+=1;

}

std::string SalesAssociate::get_sales(){
	std::string info = std::to_string(sales);
	return info;

}

int SalesAssociate::get_sales_num(){
	return sales;

}

std::string SalesAssociate::get_name(){
	std::string info = name;
 	return info;
}

std::string SalesAssociate::get_info(){

   std::string info = 
   "Sales Associate's Name: " + name + '\n'+
   "Sales Associate's ID Number: " + std::to_string(id) + '\n'; 
   //+"Number of Orders Sold: " + std::to_string(sales) +  '\n';
   
   return info;

}

std::string SalesAssociate::save_to_file(){
   std::string info = "Sales_Associate_Identifier\n" + name + "\n" +
                  std::to_string(id);
   return info;
}


//
//  Customer
//


class Customer{


public:
   Customer(std::string _name, int _id, int _phone, std::string _email, double _debt) :
   name(_name), id(_id), phone(_phone), email(_email), debt(_debt) {}
   std::string save_to_file();
   std::string get_info();
   void Increase_debt(double cost);
   std::string get_name();
   double get_debt();

private:
   std::string name, email;
   int id, phone;
   double debt;



};

void Customer::Increase_debt(double cost){

	debt = cost + debt;
}

double Customer::get_debt(){
	
	double result = debt;
	return result;
}

std::string Customer::get_name(){

	std::string result = name;
	return result;

}

std::string Customer::get_info(){

        std::string info =
        "Beloved Customer's Name: " + name + '\n'+
        "Beloved Customer's ID Number: " + std::to_string(id) + '\n'+
   	"Beloved Customer's phone number (one continuous number): "+ std::to_string(phone) + '\n'+
   	"Beloved Customer's email: " + email +'\n'+"Bill: "+ std::to_string(debt)+'\n';
        return info;

}

std::string Customer::save_to_file(){
   std::string info = "Customer_Identifier\n" + name + "\n" 
                  + std::to_string(id) + "\n" + 
                  std::to_string(phone) + "\n" +
                  email;
   return info;
}

//
//  State Machine Header for Progress
//

enum Progress { building,
    built,
    shipped,
    delivered };



//
//  Order
//

class Order{
public:
   Order(Robot_model _model, 
      Customer _customer, 
      SalesAssociate _seller,
      Progress _current_state) : 
         
      model(_model), 
      customer(_customer),
      seller(_seller),
      current_state (_current_state) {}
   
   std::string save_to_file();
   std::string get_info();
   void add_choice(int choice);
   void change_state(Progress new_state, int order_num);
   SalesAssociate get_SA();
   Customer get_BC();

private:
   Robot_model model;
   Customer customer;
   SalesAssociate seller;
   Progress current_state;
   std::vector<int> choices;


};

SalesAssociate Order::get_SA(){
   	return seller; 
}

Customer Order::get_BC(){
   	return customer; 
}

void Order::change_state(Progress new_state, int order_num){

	int choice;	
	this->current_state = new_state;
	switch (new_state){
		case building: choice = 1; break;
    	case built: choice = 2; break;
		case shipped: choice = 3; break;
		case delivered: choice = 4; break;
	}
	this->choices[3] = choice;


}


std::string Order::get_info(){
   std::string state = "progress: ";
   switch (current_state){
  case building: state += "buidling"; break;
  case built: state += "built"; break;
  case shipped: state += "shipped"; break;
  case delivered: state += "delivered"; break;
  }
   std::string info = model.get_info() + '\n' + seller.get_info() + '\n' + customer.get_info() + '\n' + state + '\n';
   return info;
}

std::string Order::save_to_file(){
   std::string info = "Order_Identifier\n" + std::to_string(choices[0]) + "\n"
                  + std::to_string(choices[1]) + "\n"
                  + std::to_string(choices[2]) + "\n"
                  + std::to_string(choices[3]);
   return info;

}

void Order::add_choice(int choice){
   choices.push_back(choice);
}


//
//  Shop
//

class Shop{
public:
   void create_new_robot_arm(std::string name, int model_num, double price, std::string description);
   void create_new_robot_head(std::string name, int model_num, double price, std::string description);
   void create_new_robot_torso(std::string name, int model_num, double price, std::string description);
   void create_new_robot_battery(std::string name, int model_num, double price, std::string description);
   void create_new_robot_locomotor(std::string name, int model_num, double price, std::string description);
   void create_new_sales_associate(std::string name, int id, int sales);
   void create_new_beloved_customer(std::string name, int id, int phone, std::string email); 
   void create_order(Robot_model robot, Customer customer, SalesAssociate seller, Progress state, int model, int buyer, int associate, int state_num);
   void create_new_robot_model(std::string name,
			std::string image,
                        int model_num,
                        Arm arm, 
                        Head head, 
                        Torso torso,
                        Battery battery, 
                        Locomotor locomotor,
                        int arm_num, int head_num, int torso_num,  int battery_num,  int locomotor_num);


   Arm get_robot_arm(int index);
   Head get_robot_head(int index);
   Torso get_robot_torso(int index);
   Battery get_robot_battery(int index);
   Locomotor get_robot_locomotor(int index);
   Robot_model get_robot_model(int index);
   SalesAssociate get_sales_associate(int index);
   Customer get_customer(int index);
   Order get_order(int index);
   int number_of_robot_models();
   int number_of_arms();
   int number_of_torsos();
   int number_of_batteries();
   int number_of_heads();
   int number_of_locomotors();
   int number_of_models();
   int number_of_associates();
   int number_of_customers();
   int number_of_orders();
   
   void change_order_progress(int order_position, Progress new_state);

private:
   std::vector<Robot_model> robot_models;
   std::vector<Torso> torsos;
   std::vector<Head> heads;
   std::vector<Locomotor> locomotors;
   std::vector<Battery> batteries;
   std::vector<Arm> arms;
   std::vector<SalesAssociate> associates;
   std::vector<Customer> customers;
   std::vector<Order> orders;
};

void Shop::create_new_robot_arm(std::string name, int model_num, double price, std::string description){

   Arm arm(name, model_num, price, description);
   arms.push_back(arm);

}

void Shop::create_new_robot_head(std::string name, int model_num, double price, std::string description){

   Head head(name, model_num, price, description);
   heads.push_back(head);

}

void Shop::create_new_robot_torso(std::string name, int model_num, double price, std::string description){

   Torso Torso(name, model_num, price, description);
   torsos.push_back(Torso);

   
   

}

void Shop::create_new_robot_battery(std::string name, int model_num, double price, std::string description){

   Battery battery(name, model_num, price, description);
   batteries.push_back(battery);

}

void Shop::create_new_robot_locomotor(std::string name, int model_num, double price, std::string description){


   Locomotor locomotor(name, model_num, price, description);
   locomotors.push_back(locomotor);

}

void Shop::create_new_sales_associate(std::string name, int id, int sales){
   
   SalesAssociate associate(name, id, sales);
   associates.push_back(associate);

}

void Shop::create_new_beloved_customer
(std::string name, int id, int phone, std::string email){

   Customer customer(name, id, phone, email, 0);
   customers.push_back(customer);

}

Arm Shop::get_robot_arm(int index){
   return arms[index];

}

Head Shop::get_robot_head(int index){
   return heads[index];

}

Torso Shop::get_robot_torso(int index){
   return torsos[index];

}

Battery Shop::get_robot_battery(int index){
   return batteries[index];

}

Locomotor Shop::get_robot_locomotor(int index){
   return locomotors[index];
}

Robot_model Shop::get_robot_model(int index){
   return robot_models[index];
}

void Shop::create_new_robot_model(std::string name, std::string image,
                        int model_num,
                        Arm arm, 
                        Head head, 
                        Torso torso,
                        Battery battery, 
                        Locomotor locomotor,
                        int arm_num, int head_num, int torso_num,  int 				battery_num,  int locomotor_num){




   Robot_model Robot(name, image, model_num, arm, head, torso,
                  battery, locomotor);
   Robot.add_choice(arm_num);
   Robot.add_choice(head_num);
   Robot.add_choice(torso_num);
   Robot.add_choice(battery_num);
   Robot.add_choice(locomotor_num);

   robot_models.push_back(Robot);

}

int Shop::number_of_robot_models(){
   return robot_models.size();
}

int Shop::number_of_arms(){
   return arms.size();
}

int Shop::number_of_torsos(){
   return torsos.size();
}

int Shop::number_of_batteries(){
   return batteries.size();
}

int Shop::number_of_heads(){
   return heads.size();
}

int Shop::number_of_locomotors(){
   return locomotors.size();
}

int Shop::number_of_models(){
   return robot_models.size();
}

int Shop::number_of_associates(){
        return associates.size();
}

int Shop::number_of_customers(){
        return customers.size();
}

int Shop::number_of_orders(){
   return orders.size();
}

SalesAssociate Shop::get_sales_associate(int index){
   return associates[index];

}

Customer Shop::get_customer(int index){
   return customers[index];

}

void Shop::create_order(Robot_model robot, Customer customer, SalesAssociate seller, Progress state, int model, int buyer, int associate, int state_num){

   Order order(robot, customer, seller, state);
   order.add_choice(model);
   order.add_choice(buyer);

   //increase the saller's sales count and customer's debt
   associates[associate].Increase_sales(); 
   customers[buyer].Increase_debt(robot.cost()); 

   order.add_choice(associate);
   order.add_choice(state_num);
   orders.push_back(order);
}

Order Shop::get_order(int index){
   return orders[index];

}

void Shop::change_order_progress(int order_position, Progress new_state){

	
	orders[order_position].change_state(new_state, order_position);


}



//
//  View
//

class View{
public:
   View(Shop& market) : shop(market){}
   //std::string get_menu(); not needed when you have a menu or toolbar
   std::string get_robot_models();
   std::string get_each_model(int i);
   std::string parts_menu();
   std::string get_robot_parts(int choice);
   std::string create_a_part_menu();
   std::string view_customers_menu();
   std::string view_sales_associates_menu();
   std::string view_orders_menu();
   std::string state_menu();


private:
   Shop& shop;
};
/*
std::string View::get_menu(){

std::string menu = R"(
====================================================
Which one of these options would you like to choose? 
====================================================
1)Create a robot part 
2)Create a robot model 
3)View robot parts 
4)View robot models
5)Create a Customer
6)Create a Sales Associate
7)Create an Order
8)View Customers
9)View Sales Associates
10)View Orders
11)Load
12)Save
13)Save to specified file
0)Exit
====================================================
)";

return menu;

} */

std::string View::get_robot_models(){

std::string list = R"(
=====================
List of Robot Models 
=====================
)";

for (int i = 0; i < shop.number_of_models(); ++i) {
        list += "Robot Model #"+std::to_string(i)+'\n';
         list += shop.get_robot_model(i).get_info();

         list += "\nHead info:\n";
         list += shop.get_robot_model(i).get_robot_head().get_info();

         list +="\nTorso info:\n";
         list += shop.get_robot_model(i).get_robot_torso().get_info();

         list += "\nArm info:\n";
         list += shop.get_robot_model(i).get_robot_arm().get_info();

         list += "\nBattery info:\n";
         list += shop.get_robot_model(i).get_robot_battery().get_info();

         list += "\nLocomotor info:\n";
         list += shop.get_robot_model(i).get_robot_locomotor().get_info();

         list += "\n================================================\n";
   
   }




return list;

}

std::string View::get_each_model(int i){

std::string list = R"(
=====================
   Robot Model 
=====================
)";

        list += "Robot Model #"+std::to_string(i)+'\n';
         list += shop.get_robot_model(i).get_info();

         list += "\nHead info:\n";
         list += shop.get_robot_model(i).get_robot_head().get_info();

         list +="\nTorso info:\n";
         list += shop.get_robot_model(i).get_robot_torso().get_info();

         list += "\nArm info:\n";
         list += shop.get_robot_model(i).get_robot_arm().get_info();

         list += "\nBattery info:\n";
         list += shop.get_robot_model(i).get_robot_battery().get_info();

         list += "\nLocomotor info:\n";
         list += shop.get_robot_model(i).get_robot_locomotor().get_info();

         list += "\n================================================\n";

return list;

}
std::string View::parts_menu(){

std::string menu = R"(
============================================
Which of these parts would you like to view?
============================================
1) Head
2) Torso
3) Arm
4) Battery
5) Locomotor
============================================
)";

return menu;


}

std::string View::get_robot_parts(int choice){

std::string part;

if(choice == 1){
   part = "Heads";

}else if(choice == 2){
   part = "Torsos";
}else if(choice == 3){
   part = "Arms";
}else if(choice == 4){
   part = "Batteries";
}else if(choice == 5){
   part = "Locomotors";
}



std::string list = R"(
==================
List of )"+ part + R"( 
==================
)"; 

switch (choice) {

   case 1: part = "Heads";
      for (int i = 0; i < shop.number_of_heads(); ++i) {
         list += "Part #"+std::to_string(i)+'\n';
         list += shop.get_robot_head(i).get_info() +'\n';
         list += "--------------------------------------------\n";
         };break;

   case 2: part = "Torsos"; 
      for (int i = 0; i < shop.number_of_torsos(); ++i) {
         list += "Part #"+std::to_string(i)+'\n';
         list += shop.get_robot_torso(i).get_info() +'\n';
         list += "--------------------------------------------\n";
         };break;

   case 3: part = "Arms";
      for (int i = 0; i < shop.number_of_arms(); ++i) {
         list += "Part #"+std::to_string(i)+'\n';
         list += shop.get_robot_arm(i).get_info() +'\n';
         list += "--------------------------------------------\n";
         };break;

   case 4: part = "Batteries";
      for (int i = 0; i < shop.number_of_batteries(); ++i) {
         list += "Part #"+std::to_string(i)+'\n';
         list += shop.get_robot_battery(i).get_info() +'\n';
         list += "--------------------------------------------\n";
         };break;

   case 5: part = "Locomotors"; 
      for (int i = 0; i < shop.number_of_locomotors(); ++i) {
         list += "Part #"+std::to_string(i)+'\n';
         list += shop.get_robot_locomotor(i).get_info() +'\n';
         list += "--------------------------------------------\n";
         };break;

      }// end switch

return list;

}

std::string View::create_a_part_menu(){

std::string menu =R"(
============================================
Which of these parts would you like to create?
============================================
1) Head
2) Torso
3) Arm
4) Battery
5) Locomotor
============================================
)";

return menu;


}

std::string View::view_customers_menu(){

std::string list = R"(
=====================
List of Customers
=====================
)";

   for (int i = 0; i < shop.number_of_customers(); ++i) {
      list += "Customer #"+std::to_string(i)+'\n';
      list += shop.get_customer(i).get_info() +'\n';
      list += "--------------------------------------------\n";
   }

   return list;
}

std::string View::view_sales_associates_menu(){

std::string list = R"(
=========================
List of Sales Associates 
=========================
)";

   for (int i = 0; i < shop.number_of_associates(); ++i) {
      list += "Sales Associate #"+std::to_string(i)+'\n';
      list += shop.get_sales_associate(i).get_info() +'\n';
      list += "--------------------------------------------\n";
   }

   return list;

}

std::string View::view_orders_menu(){

std::string list =R"(
=========================
List of Orders 
=========================
)";

   for (int i = 0; i < shop.number_of_orders(); ++i) {
      list += "Order #"+std::to_string(i)+'\n';
      list += shop.get_order(i).get_info() +'\n';
      list += "--------------------------------------------\n";
   }

   return list;

}

std::string View::state_menu(){

std::string list =R"(
===============
Progress state    
=============== 
1)Building
2)Built
3)Shipped
4)Delivered
===============
)";

return list;

}


//
//    GuiController
//

class GuiController{
public:
   GuiController(Shop& _shop, View& _view) : shop(_shop), 
                                 view(_view) {}
   void execute_cmd(int cmd);
   void cli();
   int validate_integer(std::string title, std::string prompt, int min_num, int max_num);
   double validate_double(std::string title, std::string prompt, double min_num, double max_num);
   std::string get_string(std::string title, std::string prompt);

   void new_robot_part();
   void new_robot_model();
   void view_robot_parts();
   void create_new_customer();
   void create_new_sales_associate();
   void create_order();
   void view_orders();
   void use_test();
   void view_customers();
   void view_sales_associates();
   void load_data();
   void load_from_certain_file();
   void save_data();
   void save_to_certain_file();
   void edit_order_progress();
   void Orders_per_SA();
   void Orders_per_BC();
   void Num_Orders_per_SA();
   void view_model(int i);
   void view_all_models();
   void view_bill();
   
   

private:
   Shop& shop;
   View& view;


};


void GuiController::execute_cmd(int cmd){
   
   switch(cmd){
      case 1: new_robot_part(); break;
      case 2: new_robot_model(); break;
      case 3: view_robot_parts(); break;
      case 4: view_all_models(); break;
      case 5: create_new_customer(); break;
      case 6: create_new_sales_associate(); break;
      case 7: create_order(); break;
      case 8: fl_message(view.view_customers_menu().c_str()); break;
      case 9: fl_message(view.view_sales_associates_menu().c_str()); break;
      case 10: fl_message(view.view_orders_menu().c_str()); break;
      case 11: load_data(); break;
      case 12: save_data(); break;
      case 13: save_to_certain_file(); break;
      case 14: edit_order_progress(); break; 
      case 15: Num_Orders_per_SA(); break;
      case 16: Orders_per_SA(); break; 
      case 17: load_from_certain_file(); break;
      case 18: view_bill(); break;
      case 19: Orders_per_BC(); break;
      //case 99: use_test(); break;
      case 0: break;
      default: std::cerr << "Error! Invalid input" << std::endl; break;
   }
   


}

int GuiController::validate_integer(std::string title, std::string prompt, int min_num, int max_num){

   int num;
   std::string error = "\nPlease enter a valid integer";
   while(true){ //this loop validates integer input
         fl_message_title(title.c_str());
         fl_message_icon()->label("I");
         num = atoi(fl_input(prompt.c_str(), 0));
         if((min_num <= num && num <= max_num)){
            break;
         }else{
            fl_message_title("Invalid Input");
            fl_message_icon()->label("!");
            fl_message(error.c_str());
         }
      }

   return num;

}

double GuiController::validate_double(std::string title, std::string prompt, double min_num, double max_num){

        double  num;
        std::string error = "\nPlease enter a valid double";
        while(true){ //this loop validates integer input
                        fl_message_title(title.c_str());
                        fl_message_icon()->label("I");
                        num = atoi(fl_input(prompt.c_str(), 0));
                        if((0 <= min_num && num <= max_num)){
                                break;
                        }else{
                                fl_message_title("Invalid Input");
                                fl_message_icon()->label("!");
                                fl_message(error.c_str());
                        }
                }

        return num;

}


std::string GuiController::get_string(std::string title, std::string prompt){
   
   fl_message_title (title.c_str());
   fl_message_icon()->label("S");
   std::string result = fl_input(prompt.c_str(), 0);
   return result;
}

void GuiController::view_robot_parts(){
	
	int choice; 
	choice = validate_integer("Which type of part would you like to see?", view.parts_menu(), 1, 5);

	fl_message(view.get_robot_parts(choice).c_str());

}


void GuiController::view_all_models(){
   
   int cmd = 0, option = 0;
   if (shop.number_of_models() == 0){
      	fl_message("There are no models");
   }else{
   	while(cmd != -1){
      		std::string menu = "Type 1 to see next model.\nType 2 to see current model.\nType 3 to see previous model.\nType 0 to exit or continue till exit\n";
     		option = atoi(fl_input(menu.c_str(),0)); 
   		switch(option){
			case 0: cmd = -1; break;
			case 1: if (cmd == shop.number_of_models()){
					cmd = -1;
				}else{
					cmd += 1; 
					view_model(cmd); 
				};
					 break;
			case 2: view_model(cmd); break;
			case 3: if (cmd != 0){
					cmd -= 1;
					view_model(cmd);
				}else{
					fl_message("There is no previous model");
				}; 	
					break;
			}	
		} 
	}
}

//fl_message(view.get_robot_models().c_str());
void GuiController::view_model(int i){
   
    std::string ImageName = shop.get_robot_model(i).get_image();
    Fl_JPEG_Image *jpg = new Fl_JPEG_Image(ImageName.c_str());
    Fl_Image *pic = jpg->copy(100,100);
    std::string no_label = "";

    fl_message_title("Robot Model");
    fl_message_icon()->label(no_label.c_str());
    fl_message_icon()->labelsize(1);
    fl_message_icon()->image(*pic);
    fl_message(view.get_each_model(i).c_str());
    fl_message_icon()->image(0);

   	
}

void GuiController::new_robot_part(){
   //variable declarations
      std::string name, description, part;
      int model_num, choice, price;
      int max_choice = 5, min_choice = 1;
      
      //start submenu here
      
      choice = validate_integer("Which part would you like to add?", view.create_a_part_menu(), min_choice, max_choice); //getting choice for main menu
         
      switch (choice){
      case 1: part = "Head" ;break;
      case 2: part = "Torso" ;break;
      case 3: part = "Arm" ;break;
      case 4: part = "Battery" ;break;
      case 5: part = "Locomotor" ;break;
      }
      
      //post-select action
      name = get_string(part, "Enter a name: ");

      model_num = validate_integer(part, "Enter a model number: ", 0, 9999999);//getting user input for model number

      price = validate_double(part, "Enter a price: ", 0, 99999999);
       
      description = get_string(part, "Enter a description: "); 
      
      //actual storing 
      switch(choice){

      case 1: shop.create_new_robot_head(name, model_num, price, description); break;
      case 2: shop.create_new_robot_torso(name, model_num, price, description); break;
      case 3: shop.create_new_robot_arm(name, model_num, price, description); break;
      case 4: shop.create_new_robot_battery(name, model_num, price, description); break;
      case 5: shop.create_new_robot_locomotor(name, model_num, price, description); break;
      

      
      }
}



void GuiController::new_robot_model(){

  //variable declarations
      std::string name, null_part, image;
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
 
  //tells you which vectors are null
  if (shop.number_of_arms() == 0){
    null_part = null_part + "arm \n";
  }
  if (shop.number_of_heads() == 0){
    null_part = null_part + "head \n";
  }
  if (shop.number_of_torsos() == 0){
    null_part = null_part + "torso \n";
  }
  if (shop.number_of_batteries() == 0){
    null_part = null_part + "battery \n";
  }
  if (shop.number_of_locomotors() == 0) {
    null_part = null_part + "locomotor \n"; 
  } 

  fl_message_title("Invalid Input");
        fl_message_icon()->label("!");
  fl_message(("There are no parts available for the following component/s: \n"+ null_part).c_str() );
  
  }
  
  if ( 
        shop.number_of_arms() != 0 &&
        shop.number_of_heads() != 0 &&
        shop.number_of_torsos() != 0 &&
        shop.number_of_batteries() != 0 &&
  shop.number_of_locomotors() != 0 ){
  
  name = get_string("Robot Model", "Enter a name: ");

  image = get_string("Robot Model", "Enter image file name: ");
  
  model_num = validate_integer(name, "Enter a model number: ", 0, 9999999);
  arm_num = validate_integer("Please input the part # for the arm you would like for this model", view.get_robot_parts(3), 0, shop.number_of_arms()-1);

  head_num = validate_integer("Please input the part # for the head you would like for this model", view.get_robot_parts(1), 0, shop.number_of_heads()-1);
  
  torso_num = validate_integer("Please input the part # for the torso you would like for this model", view.get_robot_parts(2), 0, shop.number_of_torsos()-1);
  battery_num = validate_integer("Please input the part # for the battery you would like for this model", view.get_robot_parts(4), 0, shop.number_of_batteries()-1);

  locomotor_num = validate_integer("Please input the part # for the locomotors you would like for this model", view.get_robot_parts(5), 0, shop.number_of_locomotors()-1);
  
  
  //put the parts together
    shop.create_new_robot_model(
    name,
    image,
    model_num,
    shop.get_robot_arm(arm_num),
    shop.get_robot_head(head_num),
    shop.get_robot_torso(torso_num),
    shop.get_robot_battery(battery_num),
    shop.get_robot_locomotor(locomotor_num),
    arm_num, head_num, torso_num, battery_num, locomotor_num);
  }

}

void GuiController::create_new_customer(){
  std::string name, email, input;
    int id, phone;
  
    name = get_string("Customer", "Enter the name of the buyer");
    //getline(std::cin, name);
    
    //ask for number and validate it is a number
    id = validate_integer(name, "Enter the customer's id: ", 0, 9999999);
    
    //ask for number and validate it is a number
    phone = validate_integer(name, "Enter the customer's phone number: ", 0, 9999999);
    
    email = get_string(name, "Enter the customer's email address: ");
  
    shop.create_new_beloved_customer(name, id, phone, email);

}
void GuiController::create_new_sales_associate(){
  std::string name, email, input;
    int id, phone;
  
    name = get_string("Customer", "Enter the name of the seller: ");
    //getline(std::cin, name);
    
    //ask for number and validate it is a number
    id = validate_integer(name, "Enter the sale associate's id: ", 0, 9999999);
    
    //ask for number and validate it is a number
  
  
    shop.create_new_sales_associate(name, id, 0);

}
   
void GuiController::create_order(){

  if(shop.number_of_robot_models() == 0){
    fl_message("You do not have a robot part build");
    return;

  }
  if(shop.number_of_customers() == 0){
    fl_message("You do not have a customer saved");
    return;
  }
  if(shop.number_of_associates() == 0){
    fl_message("You do not have a sales associate saved");
    return;
  }

  int model, seller, customer;
  Progress starting_state = building;

  //////// Choose a robot model /////////
 
  model = validate_integer("What robot model is being bought?: ", view.get_robot_models(), 0, shop.number_of_robot_models()-1);


  Robot_model robot = shop.get_robot_model(model);

  //////// Chose a customer ///////////

  customer = validate_integer("Who is buying this robot?: ", view.view_customers_menu(), 0, shop.number_of_customers()-1);


  Customer buyer = shop.get_customer(customer);

  //////// Chose a seller ////////////
  
  seller = validate_integer("Who is selling this robot?: ", view.view_sales_associates_menu(), 0, shop.number_of_associates()-1);

  SalesAssociate sales_associate = shop.get_sales_associate(seller);

  //////// Creating order object and adding it to the shop //////////

  shop.create_order(robot, buyer, sales_associate, starting_state, model, seller, customer, 1);
  

}

void GuiController::edit_order_progress(){

Progress selected_state;
int order_num = validate_integer("Pick an order to edit", view.view_orders_menu(), 0, shop.number_of_orders());
int choice = validate_integer("Pick a new progress state", view.state_menu(), 1, 4);
  switch (choice){
    case 1: selected_state = building; break;
    case 2: selected_state = built; break;
    case 3: selected_state = shipped; break;
    case 4: selected_state = delivered; break;
  } 

shop.change_order_progress(order_num, selected_state);

}
/*
void GuiController::use_test(){ 
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
<<<<<<< HEAD

=======
>>>>>>> 4a9d09eef1cb688a70c34b4438cc89ddbf9eb655
}*/

void GuiController::load_data(){ 
  std::ifstream ifs{"data.txt"};
  std::string input, name, image, model_num, id, email, 
  phone, description, cost, choice1, choice2, choice3, choice4, choice5;


  if(!ifs){ //if file is not opened
    fl_message("Can't open input file");
    }
  else{
    fl_message("File opened");}
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
      getline(ifs, image);
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


      shop.create_new_robot_model(name, image, model,
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
      shop.create_new_sales_associate(name, atoi(id.c_str()), 0);
    }
    else if(input == "Order_Identifier"){
      int first, second, third, fourth;
      Progress state;
      getline(ifs, choice1);
      first = atoi(choice1.c_str());
      getline(ifs, choice2);
      second = atoi(choice2.c_str());
      getline(ifs, choice3);
      third = atoi(choice3.c_str());
      getline(ifs, choice4);
      fourth = atoi(choice4.c_str());
      switch (fourth){

		case 1: state = building; break;
        case 2: state = built; break;
		case 3: state = shipped; break;
		case 4: state = delivered; break;
	     	}

      shop.create_order(shop.get_robot_model(first), 
      shop.get_customer(second), 
      shop.get_sales_associate(third), 
      state,
      first, second, third, fourth);

    }
  }
}

void GuiController::load_from_certain_file(){ 
  
  std::string fileName = get_string("File name", "Enter the name of the file you wish to load");
  std::ifstream ifs{fileName};
  std::string input, name, image, model_num, id, email, 
  phone, description, cost, choice1, choice2, choice3, choice4, choice5;


  if(!ifs){ //if file is not opened
    fl_message("Can't open input file");
    }
  else{
    fl_message("File opened");}
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
      getline (ifs, image);
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


      shop.create_new_robot_model(name, image, model,
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
      shop.create_new_sales_associate(name, atoi(id.c_str()), 0);
    }
    else if(input == "Order_Identifier"){
      int first, second, third, fourth;
      Progress state;
      getline(ifs, choice1);
      first = atoi(choice1.c_str());
      getline(ifs, choice2);
      second = atoi(choice2.c_str());
      getline(ifs, choice3);
      third = atoi(choice3.c_str());
      getline(ifs, choice4);
      fourth = atoi(choice4.c_str());
      switch (fourth){

		case 1: state = building; break;
        case 2: state = built; break;
		case 3: state = shipped; break;
		case 4: state = delivered; break;
	     	}

      shop.create_order(shop.get_robot_model(first), 
      shop.get_customer(second), 
      shop.get_sales_associate(third), 
      state,
      first, second, third, fourth);

    }
  }
}

void GuiController::save_data(){
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

  fl_message("Information saved");

}
/*
void GuiController::cli(){
   
   int cmd = -1;
   std::string menu = view.get_menu() + "\nCommand? ";
   
   while(cmd != 0){
      cmd = atoi(fl_input(menu.c_str(),0)); 
      execute_cmd(cmd);

   } //loops till manual exit at 0

}	not needed when a menu/toolbar is present
*/
void GuiController::save_to_certain_file(){

  std::string fileName = get_string("File name", "Enter the name of the file you wish to save to");
  std::string info = "Information saved to " + fileName;
  std::ofstream ofs{fileName};

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


  fl_message(info.c_str());


}

void GuiController::Num_Orders_per_SA(){	
	std::string info = "";
	for (int i = 0; i < shop.number_of_associates(); ++i){
	info += "Name: " + shop.get_sales_associate(i).get_name() + "\n" 
	+ "Numbers of orders sold: " + shop.get_sales_associate(i).get_sales()+"\n\n";
	}
	fl_message(info.c_str());

}

void GuiController::view_bill(){
	std::string info = "";
	for (int i = 0; i < shop.number_of_customers(); ++i){
	info += "Name: " + shop.get_customer(i).get_name() + "\n" 
	+ "Amount own: " + std::to_string(shop.get_customer(i).get_debt())+"\n\n";
	}
	fl_message(info.c_str());

}

void GuiController::Orders_per_SA(){
   std::string info;
   std::string name;
   std::string losers = "List of loser, free-loading, useless employees that haven't sold anything:\n------------------------------------------------------------------------\n";
   for (int a = 0; a < shop.number_of_associates(); ++a){
      	name = shop.get_sales_associate(a).get_name();
        //this if makes sure not to print for those that haven't sold
	//if you want the same treatment then SELL SOMETHING
	if (shop.get_sales_associate(a).get_sales_num() != 0){ 
	info += name+"'s sales: "+'\n'+ 
	"----------------------------------------------" + '\n';
		for (int b = 0; b < shop.number_of_orders(); ++b){
		std::string temp_name = shop.get_order(b).get_SA().get_name();
			if (temp_name.compare(name) == 0){
			info += shop.get_order(b).get_info()+'\n';
			} //close inner if loop
		}//close inner for loop
	}//close outer if loop
	//this keeps track of SAs that haven't done anything
	if(shop.get_sales_associate(a).get_sales_num() == 0){	
		losers += "-"+shop.get_sales_associate(a).get_name() + '\n';
        }// close else
   }//close outer for loop
 
   //time to add the losers
   info += losers;

   fl_message(info.c_str()); //can finally print 
}

void GuiController::Orders_per_BC(){

 std::string info;
   std::string name;
   std::string losers = "List of loser, free-loading, useless customers that haven't bought anything:\n----------------------------------------------------------------------------\n";
   for (int a = 0; a < shop.number_of_customers(); ++a){
      	name = shop.get_customer(a).get_name();
        //this if makes sure not to print for those that haven't bought
	//if you want the same treatment then BUY SOMETHING
	if (shop.get_customer(a).get_debt() != 0){ 
	info += name+"'s orders: "+'\n'+ 
	"----------------------------------------------" + '\n';
		for (int b = 0; b < shop.number_of_orders(); ++b){
		std::string temp_name = shop.get_order(b).get_BC().get_name();
			if (temp_name.compare(name) == 0){
			info += shop.get_order(b).get_info()+'\n';
			} //close inner if loop
		}//close inner for loop
	}//close outer if loop
	//this keeps track of SAs that haven't done anything
	if(shop.get_customer(a).get_debt() == 0){	
		losers += "-"+shop.get_customer(a).get_name() + '\n';
        }// close else
   }//close outer for loop
 
   //time to add the losers
   info += losers;

   fl_message(info.c_str()); //can finally print 
}
	
//
//  Callback
//

// Widgets

Fl_Window *win;
Fl_Menu_Bar *menubar;
Shop shop;
View view{shop};
GuiController controller(shop, view);

// callbacks

//File submenu callbacks
void NewCB (Fl_Widget* w, void* p) {std::cout<<"New Shop"<<std::endl;}
void LoadCB (Fl_Widget* w, void* p) {controller.execute_cmd(11);}
void LoadFromCB (Fl_Widget* w, void* p) {controller.execute_cmd(17);}
void SaveCB (Fl_Widget* w, void* p) {controller.execute_cmd(12);}
void SaveToCB (Fl_Widget* w, void* p) {controller.execute_cmd(13);}
void ExitCB (Fl_Widget* w, void* p) {win->hide();}

//Edit submenu callbacks
void Order_ProgressCB (Fl_Widget* w, void* p) {controller.execute_cmd(14);}
void CopyCB (Fl_Widget* w, void* p) {std::cout<<"Copy"<<std::endl;}
void PasteCB (Fl_Widget* w, void* p) {std::cout<<"Paste"<<std::endl;}
void PrefCB (Fl_Widget* w, void* p) {std::cout<<"Preferences"<<std::endl;}

//Create submenu callbacks
void OrderCB (Fl_Widget* w, void* p) {controller.execute_cmd(7);}
void BL_CB (Fl_Widget* w, void* p) {controller.execute_cmd(5);}
void SA_CB (Fl_Widget* w, void* p) {controller.execute_cmd(6);}
void ModelCB (Fl_Widget* w, void* p) {controller.execute_cmd(2);}
void ComponentCB (Fl_Widget* w, void* p) {controller.execute_cmd(1);}

//View submenu callbacks
void OrdersCB (Fl_Widget* w, void* p) {controller.execute_cmd(10);}
void BLs_CB (Fl_Widget* w, void* p) {controller.execute_cmd(8);}
void BillCB (Fl_Widget* w, void* p) {controller.execute_cmd(18);}
void SAs_CB (Fl_Widget* w, void* p) {controller.execute_cmd(9);}
void ModelsCB (Fl_Widget* w, void* p) {controller.execute_cmd(4);}
void OrdersPerSACB (Fl_Widget* w, void* p) {controller.execute_cmd(16);}
void OrdersPerBCCB (Fl_Widget* w, void* p) {controller.execute_cmd(19);}
void SalesPerSACB (Fl_Widget* w, void* p) {controller.execute_cmd(15);}
void ComponentsCB (Fl_Widget* w, void* p) {controller.execute_cmd(3);}
// note that this menu shows list of the create
// all callbacks in view is a plural form of their create counterpart

//Tools submenu callbacks
//nothing so far (extra credit stuff)

//Help submenu callbacks
void QuickCB (Fl_Widget* w, void* p) {std::cout<<"Quick Start"<<std::endl;}
void ManualCB (Fl_Widget* w, void* p) {std::cout<<"Manual"<<std::endl;}
void AboutCB (Fl_Widget* w, void* p) {std::cout<<"About"<<std::endl;}


//
//	Master Menu
//

Fl_Menu_Item menuitems[] = {

   {"&File", 0, 0, 0, FL_SUBMENU},
    {"&New Shop", 0, (Fl_Callback *) NewCB}, 
    //use FL_ALT + 'key' as 2nd parameter for shortcut
    {"&Load Shop", 0, (Fl_Callback *) LoadCB},
    {"&Load From", 0, (Fl_Callback *) LoadFromCB},
    {"&Save Shop", 0, (Fl_Callback *) SaveCB},
    {"&Save To", 0, (Fl_Callback *) SaveToCB},
    {"&Exit", 0, (Fl_Callback *) ExitCB},
    {0},
 
   {"&Edit", 0,0,0, FL_SUBMENU},
    {"&Order Progress", 0, (Fl_Callback *) Order_ProgressCB},
    {"&Copy", 0, (Fl_Callback *) CopyCB},
    {"&Paste", 0, (Fl_Callback *) PasteCB},
    {"&Preferences", 0, (Fl_Callback *) PrefCB},
    {0},

   {"&Create", 0, 0, 0, FL_SUBMENU},
    {"&Order", 0, (Fl_Callback *) OrderCB},
    {"&Customer", 0, (Fl_Callback *) BL_CB},
    {"&Sales Associate", 0, (Fl_Callback *) SA_CB},
    {"&Robot Model", 0, (Fl_Callback *) ModelCB},
    {"&Robot Component", 0, (Fl_Callback *) ComponentCB},
    {0},
   
   {"&View", 0, 0, 0, FL_SUBMENU},
    {"&Customers", 0, (Fl_Callback *) BLs_CB},
    {"&Bills", 0, (Fl_Callback *) BillCB},
    {"&Sales Associates", 0, (Fl_Callback *) SAs_CB},
    {"&Orders", 0, 0, 0, FL_SUBMENU},
      {"&All Orders", 0, (Fl_Callback *) OrdersCB},
      {"&Orders by Sales Associates", 0, (Fl_Callback *) OrdersPerSACB},
      {"&Orders by Customers", 0, (Fl_Callback *) OrdersPerBCCB},
      {"&Number of Orders sold per Sales Associate", 0, (Fl_Callback *) SalesPerSACB},
      {0},
    {"&Robot Models", 0, (Fl_Callback *) ModelsCB},
    {"&Robot Components", 0, (Fl_Callback *) ComponentsCB},
    {0},

   {"&Tools", 0, 0, 0, FL_SUBMENU},
    //has nothing yet
    {0},
   
   {"&Help", 0, 0, 0, FL_SUBMENU},
    {"&Quick Start", 0, (Fl_Callback *) QuickCB},
    {"&Manual", 0, (Fl_Callback *) ManualCB},
    {"&About", 0, (Fl_Callback *) AboutCB},
    {0}, 
   
  {0}
 };


//
//	Sales Associate Menu
//

//	features removed:
//	1) make a customer
//	2) create order
//	3) view customer's bill
//	4) view orders per customer 

Fl_Menu_Item SA_menuitems[] = {

   {"&File", 0, 0, 0, FL_SUBMENU},
    {"&New Shop", 0, (Fl_Callback *) NewCB}, 
    //use FL_ALT + 'key' as 2nd parameter for shortcut
    {"&Load Shop", 0, (Fl_Callback *) LoadCB},
    {"&Load From", 0, (Fl_Callback *) LoadFromCB},
    {"&Save Shop", 0, (Fl_Callback *) SaveCB},
    {"&Save To", 0, (Fl_Callback *) SaveToCB},
    {"&Exit", 0, (Fl_Callback *) ExitCB},
    {0},
 
   {"&Edit", 0,0,0, FL_SUBMENU},
    {"&Order Progress", 0, (Fl_Callback *) Order_ProgressCB},
    {"&Copy", 0, (Fl_Callback *) CopyCB},
    {"&Paste", 0, (Fl_Callback *) PasteCB},
    {"&Preferences", 0, (Fl_Callback *) PrefCB},
    {0},

   {"&Create", 0, 0, 0, FL_SUBMENU},
    {"&Sales Associate", 0, (Fl_Callback *) SA_CB},
    {"&Robot Model", 0, (Fl_Callback *) ModelCB},
    {"&Robot Component", 0, (Fl_Callback *) ComponentCB},
    {0},
   
   {"&View", 0, 0, 0, FL_SUBMENU},
    {"&Customers", 0, (Fl_Callback *) BLs_CB},
    {"&Sales Associates", 0, (Fl_Callback *) SAs_CB},
    {"&Orders", 0, 0, 0, FL_SUBMENU},
      {"&All Orders", 0, (Fl_Callback *) OrdersCB},
      {"&Orders by Sales Associates", 0, (Fl_Callback *) OrdersPerSACB},
      {"&Number of Orders sold per Sales Associate", 0, (Fl_Callback *) SalesPerSACB},
      {0},
    {"&Robot Models", 0, (Fl_Callback *) ModelsCB},
    {"&Robot Components", 0, (Fl_Callback *) ComponentsCB},
    {0},

   {"&Tools", 0, 0, 0, FL_SUBMENU},
    //has nothing yet
    {0},
   
   {"&Help", 0, 0, 0, FL_SUBMENU},
    {"&Quick Start", 0, (Fl_Callback *) QuickCB},
    {"&Manual", 0, (Fl_Callback *) ManualCB},
    {"&About", 0, (Fl_Callback *) AboutCB},
    {0}, 
   
  {0}
 };


//
//	Beloved Customer Menu
//

//	Features remove
//	1) change order progress
//	2) create sales associate
//	3) create robot model
//	4) create robot component
//	5) view orders by SA
//	6) views orders # of orders sold per SA

Fl_Menu_Item BC_menuitems[] = {

   {"&File", 0, 0, 0, FL_SUBMENU},
    {"&New Shop", 0, (Fl_Callback *) NewCB}, 
    //use FL_ALT + 'key' as 2nd parameter for shortcut
    {"&Load Shop", 0, (Fl_Callback *) LoadCB},
    {"&Load From", 0, (Fl_Callback *) LoadFromCB},
    {"&Save Shop", 0, (Fl_Callback *) SaveCB},
    {"&Save To", 0, (Fl_Callback *) SaveToCB},
    {"&Exit", 0, (Fl_Callback *) ExitCB},
    {0},
 
   {"&Edit", 0,0,0, FL_SUBMENU},
    {"&Copy", 0, (Fl_Callback *) CopyCB},
    {"&Paste", 0, (Fl_Callback *) PasteCB},
    {"&Preferences", 0, (Fl_Callback *) PrefCB},
    {0},

   {"&Create", 0, 0, 0, FL_SUBMENU},
    {"&Order", 0, (Fl_Callback *) OrderCB},
    {"&Customer", 0, (Fl_Callback *) BL_CB},
    {0},
   
   {"&View", 0, 0, 0, FL_SUBMENU},
    {"&Customers", 0, (Fl_Callback *) BLs_CB},
    {"&Bills", 0, (Fl_Callback *) BillCB},
    {"&Sales Associates", 0, (Fl_Callback *) SAs_CB},
    {"&Orders", 0, 0, 0, FL_SUBMENU},
       {"&All Orders", 0, (Fl_Callback *) OrdersCB},
       {"&Orders by Customers", 0, (Fl_Callback *) OrdersPerBCCB},
       {0},
    {"&Robot Models", 0, (Fl_Callback *) ModelsCB},
    {"&Robot Components", 0, (Fl_Callback *) ComponentsCB},
    {0},

   {"&Tools", 0, 0, 0, FL_SUBMENU},
    //has nothing yet
    {0},
   
   {"&Help", 0, 0, 0, FL_SUBMENU},
    {"&Quick Start", 0, (Fl_Callback *) QuickCB},
    {"&Manual", 0, (Fl_Callback *) ManualCB},
    {"&About", 0, (Fl_Callback *) AboutCB},
    {0}, 
   
  {0}
 };


//
//main
//

int main(){

   const int x = 540;
   const int y = 330;

   std::string usr, password;
   bool run = true;

   //usr and password via fl_input throws segmentation fault
   //std::string usr = controller.get_string("", "Please enter a username: ");
   //std::string password = controller.get_string("", "Please enter a password: ");

   //basic, simple login via terminal
  
   //entering usr and password
   std::cout<<"Username is SA for sales associate, BC for beloved customer, Master for all options."<<std::endl<<"All password is currently 1\n"<<std::endl;

   std::cout<<"Enter your user name: "<<std::endl;
   getline(std::cin, usr);
   
   std::cout<<"Enter your password: "<<std::endl;
   getline(std::cin, password);
   
   // create window
   win = new Fl_Window(x,y, "lRobot");
   win->color(FL_WHITE);
      
   //install menu bar
   menubar = new Fl_Menu_Bar (0, 0, x, 30);

   //checking and change menu bar
   if (usr == "Master" && password == "1"){
   	//std::cout<<"clear"<<std::endl;
	menubar->menu(menuitems);
   }
   else if (usr == "SA" && password == "1"){
   	//std::cout<<"clear"<<std::endl;
	menubar->menu(SA_menuitems);
   }
   else if (usr == "BC" && password == "1"){
   	//std::cout<<"clear"<<std::endl;
	menubar->menu(BC_menuitems);
   }else{
	std::cout<<"Incorrect username or password"<<std::endl;	
	run = false;
   }

   if (run){
   //wrap it up and let FLTK do the rest
   win->end();
   win->show();
   return(Fl::run());
   }
}

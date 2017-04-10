#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_ask.H>
#include <Fl/Fl_Menu_Bar.H>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>


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



class Robot_model{
public:
   Robot_model(std::string _name,
            int _model_num,
            Arm _arm, 
            Head _head, 
            Torso _torso,
            Battery _battery, 
            Locomotor _locomotor) : 

            name(_name), 
            model_number(_model_num), 
            arm(_arm),
            head(_head),
            torso(_torso),
            battery(_battery),
            locomotor(_locomotor) { }
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

private:
   std::string name;
   int model_number;
   Torso torso;
   Head head;
   Locomotor locomotor;
   Arm arm;
   Battery battery;
   std::vector<int> choices;//this vector keeps track of what was chosen

};

std::string Robot_model::get_info(){
   std::string info = "Name: " + name + "\n" 
                  "Model number: " + std::to_string(model_number) + "\n"
                  "Cost: " + std::to_string(cost()) + "\n";
   return info;
}

std::string Robot_model::save_to_file(){
   std::string info = "Robot_Identifier\n" + name + "\n" 
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

class SalesAssociate{

public:
   SalesAssociate(std::string _name, int _id):
   name (_name), id (_id) {}
   std::string save_to_file();
   std::string get_info();

private:
   std::string name;
   int id;



};

std::string SalesAssociate::get_info(){

   std::string info = 
   "Sales Associate's Name: " + name + '\n'+
   "Sales Associate's ID Number: " + std::to_string(id) + '\n';
   
   return info;

}

std::string SalesAssociate::save_to_file(){
   std::string info = "Sales_Associate_Identifier\n" + name + "\n" +
                  std::to_string(id);
   return info;
}


class Customer{


public:
   Customer(std::string _name, int _id, int _phone, std::string _email) :
   name(_name), id(_id), phone(_phone), email(_email) {}
   std::string save_to_file();
   std::string get_info();

private:
   std::string name, email;
   int id, phone;



};


std::string Customer::get_info(){

        std::string info =
        "Beloved Customer's Name: " + name + '\n'+
        "Beloved Customer's ID Number: " + std::to_string(id) + '\n'+
   "Beloved Customer's phone number (one continuous number): "+ std::to_string(phone) + '\n'+
   "Beloved Customer's email: " + email +'\n';
        return info;

}

std::string Customer::save_to_file(){
   std::string info = "Customer_Identifier\n" + name + "\n" 
                  + std::to_string(id) + "\n" + 
                  std::to_string(phone) + "\n" +
                  email;
   return info;
}

class Order{
public:
   Order(Robot_model _model, 
      Customer _customer, 
      SalesAssociate _seller) : 
         
      model(_model), 
      customer(_customer),
      seller(_seller) {}
   std::string save_to_file();
   std::string get_info();
   void add_choice(int choice);

private:
   Robot_model model;
   Customer customer;
   SalesAssociate seller;
   std::vector<int> choices;


};


std::string Order::get_info(){

   std::string info = model.get_info() + '\n' + seller.get_info() + '\n' + customer.get_info() + '\n';
   return info;
}

std::string Order::save_to_file(){
   std::string info = "Order_Identifier\n" + std::to_string(choices[0]) + "\n"
                  + std::to_string(choices[1]) + "\n"
                  + std::to_string(choices[2]);
   return info;

}

void Order::add_choice(int choice){
   choices.push_back(choice);
}



class Shop{
public:
   void create_new_robot_arm(std::string name, int model_num, double price, std::string description);
   void create_new_robot_head(std::string name, int model_num, double price, std::string description);
   void create_new_robot_torso(std::string name, int model_num, double price, std::string description);
   void create_new_robot_battery(std::string name, int model_num, double price, std::string description);
   void create_new_robot_locomotor(std::string name, int model_num, double price, std::string description);
   void create_new_sales_associate(std::string name, int id);
   void create_new_beloved_customer(std::string name, int id, int phone, std::string email); 
   void create_order(Robot_model robot, Customer customer, SalesAssociate seller, int model, int buyer, int associate);
   void create_new_robot_model(std::string name,
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

void Shop::create_new_sales_associate(std::string name, int id){
   
   SalesAssociate associate(name, id);
   associates.push_back(associate);

}

void Shop::create_new_beloved_customer
(std::string name, int id, int phone, std::string email){

   Customer customer(name, id, phone, email);
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

void Shop::create_new_robot_model(std::string name,
                        int model_num,
                        Arm arm, 
                        Head head, 
                        Torso torso,
                        Battery battery, 
                        Locomotor locomotor,
                        int arm_num, int head_num, int torso_num,  int battery_num,  int locomotor_num){




   Robot_model Robot(name, model_num, arm, head, torso,
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

void Shop::create_order(Robot_model robot, Customer customer, SalesAssociate seller, int model, int buyer, int associate){
   Order order(robot, customer, seller);
   order.add_choice(model);
   order.add_choice(buyer);
   order.add_choice(associate);
   orders.push_back(order);
}

Order Shop::get_order(int index){
   return orders[index];

}

class View{
public:
   View(Shop& market) : shop(market){}
   std::string get_menu();
   std::string get_robot_models();
   std::string parts_menu();
   std::string get_robot_parts(int choice);
   std::string create_a_part_menu();
   std::string view_customers_menu();
   std::string view_sales_associates_menu();
   std::string view_orders_menu();


private:
   Shop& shop;
};

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
0)Exit

====================================================
)";

return menu;

}

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
   part = "Batteries";
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

   for (int i = 0; i < shop.number_of_customers(); ++i) {
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
   void save_data();


private:
   Shop& shop;
   View& view;


};


void GuiController::execute_cmd(int cmd){
   
   switch(cmd){
      case 1: new_robot_part(); break;
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




void GuiController::cli(){
   
   int cmd = -1;
   std::string menu = view.get_menu() + "\nCommand? ";
   
   while(cmd != 0){
      cmd = atoi(fl_input(menu.c_str(),0)); 
      execute_cmd(cmd);

   } //loops till manual exit at 0

}






int main(){

   Fl_Window beacon (1,1);
   beacon.show();
   Shop shop;
   View view{shop};
   GuiController controller(shop, view);
   controller.cli();


	
}


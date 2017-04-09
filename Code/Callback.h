#ifndef CALLBACK_H
#define CALLBACK_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/fl_ask.H>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Robot_part.cpp"
#include "Arm.cpp"
#include "Head.cpp"
#include "Torso.cpp"
#include "Battery.cpp"
#include "Locomotor.cpp"
#include "Robot_model.cpp"
#include "Order.cpp"
#include "View.cpp"
#include "Shop.cpp"
#include "Customer.cpp"
#include "SalesAssociate.cpp"



//Widgets

Fl_Window *win;
Fl_Menu_Bar *menubar;

Shop shop;
View view(shop);
GuiController controller(shop, view);

#endif 

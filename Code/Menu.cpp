
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <iostream>

using namespace std;


// Widgets

Fl_Window *win;
Fl_Menu_Bar *menubar;


// callbacks

//File submenu callbacks
void NewCB (Fl_Widget* w, void* p) {cout<<"New Shop"<<endl;}
void LoadCB (Fl_Widget* w, void* p) {cout<<"Load Shop"<<endl;}
void SaveCB (Fl_Widget* w, void* p) {cout<<"Save  Shop"<<endl;}
void ExitCB (Fl_Widget* w, void* p) {win->hide();}

//Edit submenu callbacks
void CutCB (Fl_Widget* w, void* p) {cout<<"Cut"<<endl;}
void CopyCB (Fl_Widget* w, void* p) {cout<<"Copy"<<endl;}
void PasteCB (Fl_Widget* w, void* p) {cout<<"Paste"<<endl;}
void PrefCB (Fl_Widget* w, void* p) {cout<<"Preferences"<<endl;}

//Create submenu callbacks
void OrderCB (Fl_Widget* w, void* p) {cout<<"Order"<<endl;}
void BL_CB (Fl_Widget* w, void* p) {cout<<"Customer"<<endl;}
void SA_CB (Fl_Widget* w, void* p) {cout<<"Sales Associate"<<endl;}
void ModelCB (Fl_Widget* w, void* p) {cout<<"Robot Model"<<endl;}
void ComponentCB (Fl_Widget* w, void* p) {cout<<"Robot Component"<<endl;}

//View submenu callbacks
void OrdersCB (Fl_Widget* w, void* p) {cout<<"Orders"<<endl;}
void BLs_CB (Fl_Widget* w, void* p) {cout<<"Customers"<<endl;}
void SAs_CB (Fl_Widget* w, void* p) {cout<<"Sales Associates"<<endl;}
void ModelsCB (Fl_Widget* w, void* p) {cout<<"Robot Models"<<endl;}
void ComponentsCB (Fl_Widget* w, void* p) {cout<<"Robot Components"<<endl;}
// note that this menu shows list of the create
// all callbacks in view is a plural form of their create counterpart

//Tools submenu callbacks
//nothing so far (extra credit stuff)

//Help submenu callbacks
void QuickCB (Fl_Widget* w, void* p) {cout<<"Quick Start"<<endl;}
void ManualCB (Fl_Widget* w, void* p) {cout<<"Manual"<<endl;}
void AboutCB (Fl_Widget* w, void* p) {cout<<"About"<<endl;}


//Menu

Fl_Menu_Item menuitems[] = {

   {"&File", 0, 0, 0, FL_SUBMENU},
    {"&New Shop", 0, (Fl_Callback *) NewCB}, 
    //use FL_ALT + 'key' as 2nd parameter for shortcut
    {"&Load Shop", 0, (Fl_Callback *) LoadCB},
    {"&Save Shop", 0, (Fl_Callback *) SaveCB},
    {"&Exit", 0, (Fl_Callback *) ExitCB},
    {0},
 
   {"&Edit", 0,0,0, FL_SUBMENU},
    {"&Cut", 0, (Fl_Callback *) CutCB},
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
    {"&Orders", 0, (Fl_Callback *) OrdersCB},
    {"&Customers", 0, (Fl_Callback *) BLs_CB},
    {"&Sales Associates", 0, (Fl_Callback *) SAs_CB},
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


//main

int main(){

   const int x = 1080;
   const int y = 660;

   // create window
   win = new Fl_Window(x,y, "Can't think of a name robot shop");
   win->color(FL_WHITE);

   //install menu bar
   menubar = new Fl_Menu_Bar (0, 0, x, 30);
   menubar->menu(menuitems);

   //wrap it up and let FLTK do the rest
   win->end();
   win->show();
   return(Fl::run());
}


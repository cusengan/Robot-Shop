#include "Callback.h"
#include "Callback.cpp"


int main(){

   const int x = 1080;
   const int y = 660;

   // create window
   win = new Fl_Window(x,y, "lRobot");
   win->color(FL_WHITE);

   //install menu bar
   menubar = new Fl_Menu_Bar (0, 0, x, 30);
   menubar->menu(menuitems);

   //wrap it up and let FLTK do the rest
   win->end();
   win->show();
   return(Fl::run());
}


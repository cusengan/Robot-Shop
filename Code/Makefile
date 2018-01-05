# Makefile for Project
CC = g++
CFLAGS = -g -w -std=c++11 -c 

CXXFLAGS = -std=c++11
LDFLAGS = -L/usr/local/lib -lfltk -lX11 -lm -Wl,-Bsymbolic-functions -lfltk_images -lfltk -lX11

all: gui

rebuild: clean gui

gui: GuiMain.cpp
	$(CXX) $(CXXFLAGS) $(fltk-config --use-images --cxxflags) -o gui GuiMain.cpp $(LDFLAGS)
main: Robot_model.o Shop.o View.o Battery.o Head.o Arm.o Torso.o Locomotor.o Robot_part.o Controller.o Customer.o SalesAssociate.o Order.o
	$(CC) Robot_model.o Shop.o View.o Battery.o Head.o Arm.o Torso.o Locomotor.o Customer.o SalesAssociate.o Robot_part.o Controller.o Order.o -o cli main_cli.cpp
Locomotor.o: Locomotor.cpp Locomotor.h
	$(CC) $(CFLAGS) Locomotor.cpp
Battery.o: Battery.cpp Battery.h
	$(CC) $(CFLAGS) Battery.cpp
Head.o: Head.cpp Head.h
	$(CC) $(CFLAGS) Head.cpp
Arm.o: Arm.cpp Arm.h
	$(CC) $(CFLAGS) Arm.cpp
Torso.o: Torso.cpp Torso.h
	$(CC) $(CFLAGS) Torso.cpp
Robot_part.o: Robot_part.cpp Robot_part.h
	$(CC) $(CFLAGS) Robot_part.cpp
Robot_model.o: Robot_model.cpp Robot_model.h
	$(CC) $(CFLAGS) Robot_model.cpp 
Shop.o: Shop.cpp Shop.h
	$(CC) $(CFLAGS) Shop.cpp
View.o: View.cpp View.h
	$(CC) $(CFLAGS) View.cpp
Controller.o: Controller.cpp Controller.h
	$(CC) $(CFLAGS) Controller.cpp
Customer.o: Customer.cpp Customer.h
	$(CC) $(CFLAGS) Customer.cpp
SalesAssociate.o: SalesAssociate.cpp SalesAssociate.h
	$(CC) $(CFLAGS) SalesAssociate.cpp
Order.o: Order.cpp Order.h
	$(CC) $(CFLAGS) Order.cpp


clean:
	-rm  -f *.o a.out gui cli


CC = g++
CFLAGS = -g -w -std=c++11 -c 

main: Robot_model.o Shop.o View.o Battery.o Head.o Arm.o Torso.o Locomotor.o Robot_part.o Controller.o Customer.o SalesAssociate.o
	$(CC) Robot_model.o Shop.o View.o Battery.o Head.o Arm.o Torso.o Locomotor.o Customer.o SalesAssociate.o Robot_part.o Controller.o main_cli.cpp
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

clean:
	-rm *.o a.out


CC = g++
CFLAGS = -g -w -std=c++11 -c 

main: Robot_model.o Shop.o View.o Torso.o Robot_part.o
	$(CC) Robot_model.o Shop.o View.o Torso.o Robot_part.o main_cli.cpp
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



clean:
	-rm *.o a.out
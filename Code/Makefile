
CC = g++
CFLAGS = -g -w -std=c++11 -c 

main: Robot_model.o
	$(CC) Robot_model.o main_cli.cpp
Robot_model.o: Robot_model.cpp Robot_model.h
	$(CC) $(CFLAGS) Robot_model.cpp



clean:
	-rm *.o a.out
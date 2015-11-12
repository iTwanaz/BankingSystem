#Makefile for 3307 Assignment 1
#Copyright 2015 Jieni Hou

all: BankingSystem
BankingSystem: main.o Account.o Customers.o Managers.o Maintenance.o User.o
	g++ -Wall -o BankingSystem main.o Account.o Customers.o Managers.o Maintenance.o User.o
main.o: main.cpp User.h User.cpp Account.h Account.cpp Customers.h Customers.cpp Managers.h Managers.cpp Maintenance.h Maintenance.cpp
	g++ -Wall -c main.cpp
Customers.o: Customers.cpp Customers.h User.cpp User.h Account.cpp Account.h
	g++ -Wall -c Customers.cpp
Managers.o: Managers.cpp Managers.h User.cpp User.h
	g++ -Wall -c Managers.cpp
Maintenance.o: Maintenance.cpp Maintenance.h User.cpp User.h
	g++ -Wall -c Maintenance.cpp
User.o: User.cpp User.h Account.cpp Account.h
	g++ -Wall -c User.cpp
Account.o: Account.cpp Account.h
	g++ -Wall -c Account.cpp
clean:
	rm -f sample *.o core *.gch
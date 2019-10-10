all: zoo

zoo: main.o Animal.o NewAnimal.o Tiger.o Penguin.o Turtle.o Zoo.o
	g++ -std=c++11 main.o Animal.o NewAnimal.o Tiger.o Penguin.o Turtle.o Zoo.o -o zoo

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Animal.o: Animal.cpp
	g++ -std=c++11 -c Animal.cpp

NewAnimal.o: NewAnimal.cpp
	g++ -std=c++11 -c NewAnimal.cpp

Tiger.o: Tiger.cpp
	g++ -std=c++11 -c Tiger.cpp

Penguin.o: Penguin.cpp
	g++ -std=c++11 -c Penguin.cpp
	
Turtle.o: Turtle.cpp
	g++ -std=c++11 -c Turtle.cpp

Zoo.o: Zoo.cpp
	g++ -std=c++11 -c Zoo.cpp
	
zip:
	zip Project2_Lee_David.zip -D *.cpp *.hpp *.pdf makefile 

clean:
	rm *.o zoo
/*********************************************************************
** Program name: Zoo.hpp
** Author: David Lee
** Date: 04/28/2019
** Description: Header file for Zoo class in project 2 program.
 *              The Zoo class control the zoo program:
 *              Contains data members to keep track of animal object point arrays, animal counts, day count and cash.
 *              Class member functions contains constructor, destructor, inputFile / outputFile functions, accessor and mutator for data members.
 *              Input validations and menu that contains program functions.
 *              Random event functions and next day functions change the animal object properties.
*********************************************************************/
#ifndef ZOO_HPP
#define ZOO_HPP
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "NewAnimal.hpp"
#include <string>
using std::string;



class Zoo {
private:
    Tiger** tigerArray; //pointer array to hold tiger object addresses
    Penguin** penguinArray; //pointer array to hold penguin object addresses
    Turtle** turtleArray; //pointer array to hold turtle object addresses
    NewAnimal** newAnimalArray; //pointer array to hold newAnimal object addresses
    int tigerArraySize; //array size for tigerArray
    int penguinArraySize; //array size for penguinArray
    int turtleArraySize; //array size for turtleArray
    int newAnimalArraySize; //array size for newAnimalArray
    int cash; //stores cash for user
    int tigerCount; //stores total count of tigers
    int penguinCount; //stores total count of penguins
    int turtleCount; //stores total count of turtles
    int newAnimalCount; //stores total count of newAnimals
    int day; //stores and keeps track of day count
    int randomBonus; //stores boom bonus in randomEvent()
    bool allowNewAnimal; //conditional flag to let program know if user wants new animal
    int newAnimalCost; //store new animal cost defined by user
    int newAnimalNumberOfBabies; //store new animal number of babies defined by user
    int newAnimalFoodCost; //store new animal food cost defined by user
    int newAnimalPayoff; //store new animal payoff defined by user
    int startNewAnimalCount; //store count of how many new animals user wants to purchase at start
    string newAnimalName; //store string of new animal type name
    string randomString; //store string used in randomEvent(), console print


public:
    Zoo(); //Constructor for Zoo class
    ~Zoo(); //Destructor for Zoo class
    void startZoo(); //function defines the first day of the zoo. User purchase every animal type.
    void nextDay(); //function to change animal object properties each new day.
    void addAdultTiger(); //user purchase adult tiger, age 3
    void addAdultPenguin(); //user purchase adult penguin, age 3
    void addAdultTurtle(); //user purchase adult turtle, age 3
    void addAdultNewAnimal(); //user purchase adult new animal, age 3
    void addBabyTiger(); //function will add tiger baby
    void addBabyPenguin(); //function will add penguin baby
    void addBabyTurtle(); //function will add turtle baby
    void addBabyNewAnimal(); //function will add new animal baby
    void doubleTigerArray(); //double tigerArray if all blocks are filled
    void doublePenguinArray(); //double penguinArray if all blocks are filled
    void doubleTurtleArray(); //double turtleArray if all blocks are filled
    void doubleNewAnimalArray(); //double newAnimalArray if all blocks are filled
    void removeTiger(); //function invoked when tiger dies
    void removePenguin(); //function invoked when penguin dies
    void removeTurtle(); //function invoked when turtle dies
    void removeNewAnimal(); //function invoked when new animal dies
    void animalDeath(); //function containing removeTiger(), removePenguin(), removeTurtle(), removeNewAnimal()
    int attendBonus(); //computes bonus amount for randomEvent boom
    void animalBorn(); //function containing addBabyTiger(), addBabyPenguin(), addBabyTurtle(), addBabyNewAnimal()
    void randomEvent(); //function that controls the randomEvent once a day
    void ledgerSummary(); //console print of daily summary and status of zoo
    int inputValidation(string message, int min, int max); //reusable input validation
    void menu(); //asks if user wants to play
    void randomEventExtract(int random); //exports random event into text file (extra credit)
    void randomEventImport(); //imports random event from text file (extra credit)

};


#endif

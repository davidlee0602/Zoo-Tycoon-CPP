/*********************************************************************
** Program name: Zoo.cpp
** Author: David Lee
** Date: 04/28/2019
** Description: Implementation file for Zoo class in project 2 program. Class member functions defined.
 *              The Zoo class control the zoo program:
 *              Contains data members to keep track of animal object point arrays, animal counts, day count and cash.
 *              Class member functions contains constructor, destructor, inputFile / outputFile functions, accessor and mutator for data members.
 *              Input validations and menu that contains program functions.
 *              Random event functions and next day functions change the animal object properties.
*********************************************************************/

#include "Zoo.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;
using std::stringstream;
using std::ofstream; //output
using std::ifstream; //input

//Constructor for Zoo class
Zoo::Zoo() { //how many animals of each //user input for initial count of animals (1 or 2)
    tigerArraySize = 10;
    penguinArraySize = 10;
    turtleArraySize = 10;
    newAnimalArraySize = 10;
    tigerCount = 0;
    penguinCount = 0;
    turtleCount = 0;
    newAnimalCount = 0;
    day = 1;
    randomBonus = 0;
    tigerArray = new Tiger* [tigerArraySize];
    penguinArray = new Penguin* [penguinArraySize];
    turtleArray = new Turtle* [turtleArraySize];
    newAnimalArray = new NewAnimal* [newAnimalArraySize];
    for(int i = 0; i < 10; i++){
        tigerArray[i] = nullptr;
        penguinArray[i] = nullptr;
        turtleArray[i] = nullptr;
        newAnimalArray[i] = nullptr;
    }
    cash = 100000;
    srand(time(0));
    allowNewAnimal = false;
    newAnimalCost = 0;
    newAnimalNumberOfBabies = 0;
    newAnimalFoodCost = 0;
    newAnimalPayoff = 0;
    startNewAnimalCount = 0;
    string newAnimalName = "";
    string randomString = "";
}

void Zoo::startZoo(){ //function defines the first day of the zoo. User purchase every animal type.
    //day 1
    int startTigerCount = inputValidation("How many tigers? (Choose 1 or 2)", 1, 2);
    for (int i = 0; i < startTigerCount ; i++) {
        tigerArray[i] = new Tiger(1); //all tigers on first day is 1 day old
        tigerCount++;
        cash -= tigerArray[i]->getCost();
    }
    int startPenguinCount = inputValidation("How many penguins? (Choose 1 or 2)", 1, 2);
    for (int i = 0; i < startPenguinCount ; i++) {
        penguinArray[i] = new Penguin(1); //all penguins on first day is 1 day old
        penguinCount++;
        cash -= penguinArray[i]->getCost();
    }
    int startTurtleCount = inputValidation("How many turtles? (Choose 1 or 2)", 1, 2);
    for (int i = 0; i < startTurtleCount ; i++) {
        turtleArray[i] = new Turtle(1); //all turtles on first day is 1 day old
        turtleCount++;
        cash -= turtleArray[i]->getCost();
    }
    int includeNewAnimal = inputValidation("Would you like to add your own new animal? (Choose 1 for YES or 2 for NO)", 1, 2);
    if (includeNewAnimal == 1){
        allowNewAnimal = true;
    }
    if (allowNewAnimal == true){
        newAnimalCost = inputValidation("How much should the new animal cost? (Choose a number between 1 to 10000 (inclusive))", 1, 10000);
        newAnimalNumberOfBabies = inputValidation("how many babies should this new animal be able to procreate at once? (Choose a number between 1 to 10 (inclusive))", 1, 10);
        newAnimalFoodCost = inputValidation("How much should the new animal food cost? (Choose a number between 1 to 100 (inclusive))", 1, 100);
        newAnimalPayoff = inputValidation("How much payoff should the new animal be able to generate? (Choose a number between 1 to 10000 (inclusive))", 1, 10000);
        startNewAnimalCount = inputValidation("How many of the new animal? (Choose 1 or 2)", 1, 2);
        cout << "Please name/specify the new animal type." << endl;
        getline(cin,newAnimalName);
        for (int i = 0; i < startNewAnimalCount ; i++) {
            newAnimalArray[i] = new NewAnimal(1, newAnimalCost, newAnimalNumberOfBabies, newAnimalFoodCost, newAnimalPayoff);
            newAnimalCount++;
            cash -= newAnimalArray[i]->getCost();
        }
    }

    ledgerSummary();
}

void Zoo::nextDay(){ //function to change animal object properties each new day.
    if(allowNewAnimal == false){
        bool continuePlaying = true;
        while (continuePlaying == true && cash > 0){
            day++; //add day to age to all existing animals
            cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
            cout << "Day " << day << " Start:" << endl;
            cout << "*************************************************************" << endl;
            cout << "Starting day cash: " << cash << endl;
            for (int i = 0; i < tigerCount; i++){
                tigerArray[i]->dayOlder();
            }
            for (int i = 0; i < penguinCount; i++){
                penguinArray[i]->dayOlder();
            }
            for (int i = 0; i < turtleCount; i++){
                turtleArray[i]->dayOlder();
            }
            cout << "*************************************************************" << endl;
            cout << "All animals gained a day in age." << endl;
            //deduct food cost
            //calculate food cost
            int tigerFoodCostTotal = 0;
            int penguinFoodCostTotal = 0;
            int turtleFoodCostTotal = 0;
            for (int i = 0; i < tigerCount; i++){
                cash -= tigerArray[i]->get_base_food_cost();
                tigerFoodCostTotal += tigerArray[i]->get_base_food_cost();

            }
            for (int i = 0; i < penguinCount; i++){
                cash -= penguinArray[i]->get_base_food_cost();
                penguinFoodCostTotal += penguinArray[i]->get_base_food_cost();
            }
            for (int i = 0; i < turtleCount; i++){
                cash -= turtleArray[i]->get_base_food_cost();
                turtleFoodCostTotal += turtleArray[i]->get_base_food_cost();
            }
            cout << "*************************************************************" << endl;
            cout << "Tiger food total cost: " << tigerFoodCostTotal << endl;
            cout << "Penguin food total cost: " << penguinFoodCostTotal << endl;
            cout << "Turtle food total cost: " << turtleFoodCostTotal << endl;
            cout << "*************************************************************" << endl;
            //random event
            randomEvent();

            //calculate pay off
            int tigerPayoffTotal = 0;
            int penguinPayoffTotal = 0;
            int turtlePayoffTotal = 0;
            for (int i = 0; i < tigerCount; i++){
                cash += tigerArray[i]->getPayoff(); //add tiger bonus
                tigerPayoffTotal += (tigerArray[i]->getPayoff() + randomBonus);
            }
            for (int i = 0; i < penguinCount; i++){
                cash += penguinArray[i]->getPayoff();
                penguinPayoffTotal += penguinArray[i]->getPayoff();
            }
            for (int i = 0; i < turtleCount; i++){
                cash += turtleArray[i]->getPayoff();
                turtlePayoffTotal += turtleArray[i]->getPayoff();
            }
            cout << "*************************************************************" << endl;
            cout << "Tiger total payout: " << tigerPayoffTotal << endl;
            cout << "(Tiger bonus included in payout: " << randomBonus << " x " << tigerCount << " = " << (randomBonus*tigerCount) << ")" << endl;
            cout << "Penguin total payout: " << penguinPayoffTotal << endl;
            cout << "Turtle total payout: " << turtlePayoffTotal << endl;
            cout << "*************************************************************" << endl;
            cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
            //buy adult animal?
            int buyAdultAnimal = inputValidation("Would you like to buy an adult animal? Press 1 for Yes. Press 2 for No.", 1, 2);
            if (buyAdultAnimal == 1){
                int buyAdultAnimalChoice = inputValidation("Which animal? Press 1 for Tiger. Press 2 for Penguin. Press 3 for Turtle", 1, 3);
                if (buyAdultAnimalChoice == 1){
                    addAdultTiger(); //cost deducted within function
                }
                else if (buyAdultAnimalChoice == 2){
                    addAdultPenguin(); //cost deducted within function
                }
                else if (buyAdultAnimalChoice == 3){
                    addAdultTurtle(); //cost deducted within function
                }else{
                    cout << "Entry error." << endl;
                }
                cout << "Adult animal purchase completed." << endl;
            }
            ledgerSummary();
            if(cash > 0) {
                int continueGame = inputValidation("Keep playing? Press 1 for YES. Press 2 for No", 1, 2);
                if (continueGame == 1){
                    continuePlaying = true;
                }else if (continueGame == 2){
                    continuePlaying = false;
                    cout << "Thank you for playing Zoo Tycoon!" << endl;
                }else{
                    cout << "Entry error" << endl;
                }
            }else{
                cout << "You are bankrupt. Game over." << endl;
                cout << "Cash : " << cash << endl;
                continuePlaying = false;
            }
        }
    }
    else{
        bool continuePlaying = true;
        while (continuePlaying == true && cash > 0){
            day++; //add day to age to all existing animals
            cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
            cout << "Day " << day << " Start:" << endl;
            cout << "*************************************************************" << endl;
            cout << "Starting day cash: " << cash << endl;
            for (int i = 0; i < tigerCount; i++){
                tigerArray[i]->dayOlder();
            }
            for (int i = 0; i < penguinCount; i++){
                penguinArray[i]->dayOlder();
            }
            for (int i = 0; i < turtleCount; i++){
                turtleArray[i]->dayOlder();
            }
            for (int i = 0; i < newAnimalCount; i++){
                newAnimalArray[i]->dayOlder();
            }
            cout << "*************************************************************" << endl;
            cout << "All animals gained a day in age." << endl;
            //deduct food cost
            //calculate food cost
            int tigerFoodCostTotal = 0;
            int penguinFoodCostTotal = 0;
            int turtleFoodCostTotal = 0;
            int newAnimalFoodCostTotal = 0;
            for (int i = 0; i < tigerCount; i++){
                cash -= tigerArray[i]->get_base_food_cost();
                tigerFoodCostTotal += tigerArray[i]->get_base_food_cost();

            }
            for (int i = 0; i < penguinCount; i++){
                cash -= penguinArray[i]->get_base_food_cost();
                penguinFoodCostTotal += penguinArray[i]->get_base_food_cost();
            }
            for (int i = 0; i < turtleCount; i++){
                cash -= turtleArray[i]->get_base_food_cost();
                turtleFoodCostTotal += turtleArray[i]->get_base_food_cost();
            }
            for (int i = 0; i < newAnimalCount; i++){
                cash -= newAnimalArray[i]->get_base_food_cost();
                newAnimalFoodCostTotal += newAnimalArray[i]->get_base_food_cost();
            }
            cout << "*************************************************************" << endl;
            cout << "Tiger food total cost: " << tigerFoodCostTotal << endl;
            cout << "Penguin food total cost: " << penguinFoodCostTotal << endl;
            cout << "Turtle food total cost: " << turtleFoodCostTotal << endl;
            cout << newAnimalName <<" food total cost: " << newAnimalFoodCostTotal << endl;
            cout << "*************************************************************" << endl;
            //random event
            randomEvent();

            //calculate pay off
            int tigerPayoffTotal = 0;
            int penguinPayoffTotal = 0;
            int turtlePayoffTotal = 0;
            int newAnimalPayoffTotal = 0;
            for (int i = 0; i < tigerCount; i++){
                cash += tigerArray[i]->getPayoff(); //add tiger bonus
                tigerPayoffTotal += (tigerArray[i]->getPayoff() + randomBonus);
            }
            for (int i = 0; i < penguinCount; i++){
                cash += penguinArray[i]->getPayoff();
                penguinPayoffTotal += penguinArray[i]->getPayoff();
            }
            for (int i = 0; i < turtleCount; i++){
                cash += turtleArray[i]->getPayoff();
                turtlePayoffTotal += turtleArray[i]->getPayoff();
            }
            for (int i = 0; i < newAnimalCount; i++){
                cash += newAnimalArray[i]->getPayoff();
                newAnimalPayoffTotal += newAnimalArray[i]->getPayoff();
            }
            cout << "*************************************************************" << endl;
            cout << "Tiger total payout: " << tigerPayoffTotal << endl;
            cout << "(Tiger bonus included in payout: " << randomBonus << " x " << tigerCount << " = " << (randomBonus*tigerCount) << ")" << endl;
            cout << "Penguin total payout: " << penguinPayoffTotal << endl;
            cout << "Turtle total payout: " << turtlePayoffTotal << endl;
            cout << newAnimalName << " total payout: " << newAnimalPayoffTotal << endl;
            cout << "*************************************************************" << endl;
            cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
            //buy adult animal?
            int buyAdultAnimal = inputValidation("Would you like to buy an adult animal? Press 1 for Yes. Press 2 for No.", 1, 2);
            if (buyAdultAnimal == 1){
                int buyAdultAnimalChoice = inputValidation("Which animal? Press 1 for Tiger. Press 2 for Penguin. Press 3 for Turtle. Press 4 for " + newAnimalName + "." , 1, 4);
                if (buyAdultAnimalChoice == 1){
                    addAdultTiger(); //cost deducted within function
                }
                else if (buyAdultAnimalChoice == 2){
                    addAdultPenguin(); //cost deducted within function
                }
                else if (buyAdultAnimalChoice == 3){
                    addAdultTurtle(); //cost deducted within function
                }
                else if (buyAdultAnimalChoice == 4){
                    addAdultNewAnimal(); //cost deducted within function
                }
                else{
                    cout << "Entry error." << endl;
                }
                cout << "Adult animal purchase completed." << endl;
            }
            ledgerSummary();
            if(cash > 0) {
                int continueGame = inputValidation("Keep playing? Press 1 for YES. Press 2 for No", 1, 2);
                if (continueGame == 1){
                    continuePlaying = true;
                }else if (continueGame == 2){
                    continuePlaying = false;
                    cout << "Thank you for playing Zoo Tycoon!" << endl;
                }else{
                    cout << "Entry error" << endl;
                }
            }else{
                cout << "You are bankrupt. Game over." << endl;
                cout << "Cash : " << cash << endl;
                continuePlaying = false;
            }
        }
    }

}

void Zoo::addAdultTiger(){ //user purchase adult tiger, age 3
    doubleTigerArray();
    tigerArray[tigerCount] = new Tiger(3);
    cash -= tigerArray[tigerCount]->getCost();
    tigerCount++;
}

void Zoo::addAdultTurtle() { //user purchase adult turtle, age 3
    doubleTurtleArray();
    turtleArray[turtleCount] = new Turtle(3);
    cash -= turtleArray[turtleCount]->getCost();
    turtleCount++;
}

void Zoo::addAdultPenguin() { //user purchase adult penguin, age 3
    doublePenguinArray();
    penguinArray[penguinCount] = new Penguin(3);
    cash -= penguinArray[penguinCount]->getCost();
    penguinCount++;
}

void Zoo::addAdultNewAnimal() { //user purchase adult new animal, age 3
    doubleNewAnimalArray();
    newAnimalArray[newAnimalCount] = new NewAnimal(3, newAnimalCost, newAnimalNumberOfBabies, newAnimalFoodCost, newAnimalPayoff);
    cash -= newAnimalArray[newAnimalCount]->getCost();
    newAnimalCount++;
}

void Zoo::addBabyTiger(){ //function will add tiger baby
    for(int i = 0; i < tigerArray[0]->get_number_of_babies(); i++){ //if Array[0] is null due to death, function will not run
        doubleTigerArray();
        tigerArray[tigerCount] = new Tiger(0);
        tigerCount++;
        cout << "Baby tiger born!" << endl;
        randomString = "Baby tiger born!";
    }
}

void Zoo::addBabyPenguin(){ //function will add penguin baby
    for(int i = 0; i < penguinArray[0]->get_number_of_babies(); i++) { //if Array[0] is null due to death, function will not run
        doublePenguinArray();
        penguinArray[penguinCount] = new Penguin(0);
        penguinCount++;
        cout << "Baby penguin born!" << endl;
        randomString = "Baby penguin born!";
    }
}

void Zoo::addBabyTurtle() { //function will add turtle baby
    for (int i = 0; i < turtleArray[0]->get_number_of_babies(); i++) { //if Array[0] is null due to death, function will not run
        doubleTurtleArray();
        turtleArray[turtleCount] = new Turtle(0);
        turtleCount++;
        cout << "Baby turtle born!" << endl;
        randomString = "Baby turtle born!";
    }
}

void Zoo::addBabyNewAnimal() { //function will add new animal baby
    for (int i = 0; i < newAnimalArray[0]->get_number_of_babies(); i++) { //if Array[0] is null due to death, function will not run
        doubleNewAnimalArray();
        newAnimalArray[newAnimalCount] = new NewAnimal(0, newAnimalCost, newAnimalNumberOfBabies, newAnimalFoodCost, newAnimalPayoff);
        newAnimalCount++;
        cout << newAnimalName << " animal baby born!" << endl;
        randomString = newAnimalName + " animal baby born!";
    }
}

void Zoo::doubleTigerArray(){ //double tigerArray if all blocks are filled
    if(tigerArray[tigerArraySize - 1] != nullptr){
        int tempTigerArraySize = tigerArraySize * 2;
        Tiger** tempTigerArray = new Tiger*[tempTigerArraySize];
        for(int i = 0; i < tempTigerArraySize; i++) {
            tempTigerArray[i] = nullptr;
        }
        for(int i = 0; i < tigerArraySize; i++) {
            tempTigerArray[i] = tigerArray[i];
        }
        delete [] tigerArray;
        tigerArray = tempTigerArray;
        tigerArraySize = tempTigerArraySize;

    }
}

void Zoo::doublePenguinArray(){ //double penguinArray if all blocks are filled
    if(penguinArray[penguinArraySize - 1] != nullptr){
        int tempPenguinArraySize = penguinArraySize * 2;
        Penguin** tempPenguinArray = new Penguin*[tempPenguinArraySize];
        for(int i = 0; i < tempPenguinArraySize; i++) {
            tempPenguinArray[i] = nullptr;
        }
        for(int i = 0; i < penguinArraySize; i++) {
            tempPenguinArray[i] = penguinArray[i];
        }
        delete [] penguinArray;
        penguinArray = tempPenguinArray;
        penguinArraySize = tempPenguinArraySize;

    }
}

void Zoo::doubleTurtleArray(){ //double turtleArray if all blocks are filled
    if(turtleArray[turtleArraySize - 1] != nullptr){
        int tempTurtleArraySize = turtleArraySize * 2;
        Turtle** tempTurtleArray = new Turtle*[tempTurtleArraySize];
        for(int i = 0; i < tempTurtleArraySize; i++) {
            tempTurtleArray[i] = nullptr;
        }
        for(int i = 0; i < turtleArraySize; i++) {
            tempTurtleArray[i] = turtleArray[i];
        }
        delete [] turtleArray;
        turtleArray = tempTurtleArray;
        turtleArraySize = tempTurtleArraySize;

    }
}

void Zoo::doubleNewAnimalArray(){ //double newAnimalArray if all blocks are filled
    if(newAnimalArray[newAnimalArraySize - 1] != nullptr){
        int tempNewAnimalArraySize = newAnimalArraySize * 2;
        NewAnimal** tempNewAnimalArray = new NewAnimal*[tempNewAnimalArraySize];
        for(int i = 0; i < tempNewAnimalArraySize; i++) {
            tempNewAnimalArray[i] = nullptr;
        }
        for(int i = 0; i < newAnimalArraySize; i++) {
            tempNewAnimalArray[i] = newAnimalArray[i];
        }
        delete [] newAnimalArray;
        newAnimalArray = tempNewAnimalArray;
        newAnimalArraySize = tempNewAnimalArraySize;

    }
}

void Zoo::removeTiger() { //function invoked when tiger dies
    if (tigerArray[0] != nullptr) {
        delete tigerArray[tigerCount - 1];
        tigerArray[tigerCount - 1] = nullptr;
        tigerCount--;
        cout << "A tiger dies." << endl;
        randomString = "A tiger dies.";
    }
}

void Zoo::removePenguin() { //function invoked when penguin dies
    if (penguinArray[0] != nullptr) {
        delete penguinArray[penguinCount - 1];
        penguinArray[penguinCount - 1] = nullptr;
        penguinCount--;
        cout << "A penguin dies." << endl;
        randomString = "A penguin dies.";
    }
}

void Zoo::removeTurtle() { //function invoked when turtle dies
    if (turtleArray[0] != nullptr) {
        delete turtleArray[turtleCount - 1];
        turtleArray[turtleCount - 1] = nullptr;
        turtleCount--;
        cout << "A turtle dies." << endl;
        randomString = "A turtle dies.";
    }
}

void Zoo::removeNewAnimal() { //function invoked when new animal dies
    if (newAnimalArray[0] != nullptr) {
        delete newAnimalArray[newAnimalCount - 1];
        newAnimalArray[newAnimalCount - 1] = nullptr;
        newAnimalCount--;
        cout << "A "<< newAnimalName << " dies." << endl;
        randomString = "A " + newAnimalName + " dies.";
    }
}

void Zoo::menu(){ //starts game menu
    int userInput;
    userInput = inputValidation("Welcome to Zoo Tycoon. Press 1 to START. Press 2 to END.", 1, 2);
    if(userInput == 1){
        startZoo();
        nextDay();
    }else{
        cout << "Program ended." << endl;
    }
}

void Zoo::randomEvent() { //function that controls the randomEvent once a day
    bool randomCheck = true;
    bool anyAnimalAdult = false; //checks if animal is of adult age
    bool anyAnimalAlive = false; //checks if animals are available
    if(allowNewAnimal == false){
        for(int i = 0; i < tigerCount; i++){
            if(tigerArray[i]->getAge() >= 3){
                anyAnimalAdult = true;
            }
        }
        for(int i = 0; i < penguinCount; i++){
            if(penguinArray[i]->getAge() >= 3){
                anyAnimalAdult = true;
            }
        }
        for(int i = 0; i < turtleCount; i++){
            if(turtleArray[i]->getAge() >= 3){
                anyAnimalAdult = true;
            }
        }
        if(tigerCount > 0 || penguinCount > 0 || turtleCount >0){
            anyAnimalAlive = true;
        }
    }
    else{
        for(int i = 0; i < tigerCount; i++){
            if(tigerArray[i]->getAge() >= 3){
                anyAnimalAdult = true;
            }
        }
        for(int i = 0; i < penguinCount; i++){
            if(penguinArray[i]->getAge() >= 3){
                anyAnimalAdult = true;
            }
        }
        for(int i = 0; i < turtleCount; i++){
            if(turtleArray[i]->getAge() >= 3){
                anyAnimalAdult = true;
            }
        }
        for(int i = 0; i < newAnimalCount; i++){
            if(newAnimalArray[i]->getAge() >= 3){
                anyAnimalAdult = true;
            }
        }
        if(tigerCount > 0 || penguinCount > 0 || turtleCount > 0 || newAnimalCount > 0){
            anyAnimalAlive = true;
        }
    }


    while(randomCheck == true){
        int random = rand() % 4 + 1;
        if(random == 1 && anyAnimalAlive == true){
            cout << "Random Event: Sickness occurs to an animal in the zoo." << endl;
            animalDeath();
            randomBonus = 0;
            randomEventExtract(1);
            randomCheck = false;
        }
        else if(random == 2 && tigerCount > 0) {
            cout << "Random Event: A boom in zoo attendance occurs." << endl;
            randomBonus = attendBonus();
            randomEventExtract(2);
            randomCheck = false;
        }
        else if(random == 3 && anyAnimalAdult == true){
            cout << "Random Event: A baby animal is born." << endl;
            animalBorn(); //need recover if all animals are babies
            randomBonus = 0;
            randomEventExtract(3);
            randomCheck = false;
        }
        else if(random == 4){
            cout << "Random Event: Nothing happens." << endl;
            randomBonus = 0;
            randomEventExtract(4);
            randomCheck = false;
        }
        else{
            cout << "Random Event: Re-rolling. Due to unmet conditions." << endl;
            randomBonus = 0;
            randomEventExtract(5);
            randomCheck = true;

        }
    }
    randomEventImport();
}

void Zoo::animalDeath() { //function containing removeTiger(), removePenguin(), removeTurtle(), removeNewAnimal()
    bool animalCountCheck = true;
    while(animalCountCheck){
        if(allowNewAnimal == false){
            int pickAnimal = rand() % 3 + 1;
            if (pickAnimal == 1 && (tigerCount > 0)){
                removeTiger();
                animalCountCheck = false;
            }
            else if (pickAnimal == 2 && (penguinCount > 0)){
                removePenguin();
                animalCountCheck = false;
            }
            else if (pickAnimal == 3 && (turtleCount > 0)){
                removeTurtle();
                animalCountCheck = false;
            }
            else{
                animalCountCheck = true;
            }
        }
        else{
            int pickAnimal = rand() % 4 + 1;
            if (pickAnimal == 1 && (tigerCount > 0)){
                removeTiger();
                animalCountCheck = false;
            }
            else if (pickAnimal == 2 && (penguinCount > 0)){
                removePenguin();
                animalCountCheck = false;
            }
            else if (pickAnimal == 3 && (turtleCount > 0)){
                removeTurtle();
                animalCountCheck = false;
            }
            else if (pickAnimal == 4 && (newAnimalCount > 0)){
                removeNewAnimal();
                animalCountCheck = false;
            }
            else{
                animalCountCheck = true;
            }
        }
    }
}

int Zoo::attendBonus() { //computes bonus amount for randomEvent boom
    int bonus = rand() % 251 + 250;
    return bonus;
}

void Zoo::animalBorn() { //function containing addBabyTiger(), addBabyPenguin(), addBabyTurtle(), addBabyNewAnimal()
    if(allowNewAnimal == false){
        bool choice = true;
        while (choice == true) {
            int pickAnimal = rand() % 3 + 1;
            bool tigerAdultCheck = false;
            bool penguinAdultCheck = false;
            bool turtleAdultCheck = false;
            for (int i = 0; i < tigerCount; i++) {
                if (tigerArray[i]->getAge() >= 3) {
                    tigerAdultCheck = true;
                }
            }
            for (int i = 0; i < penguinCount; i++) {
                if (penguinArray[i]->getAge() >= 3) {
                    penguinAdultCheck = true;
                }
            }
            for (int i = 0; i < turtleCount; i++) {
                if (turtleArray[i]->getAge() >= 3) {
                    turtleAdultCheck = true;
                }
            }
            if (pickAnimal == 1 && tigerAdultCheck == true) {
                addBabyTiger();
                choice = false;
            }
            else if (pickAnimal == 2 && penguinAdultCheck == true) {
                addBabyPenguin();
                choice = false;
            }
            else if (pickAnimal == 3 && turtleAdultCheck == true) {
                addBabyTurtle();
                choice = false;
            }
            else {
                choice = true;
            }
        }
    }
    else{
        bool choice = true;
        while (choice == true) {
            int pickAnimal = rand() % 4 + 1;
            bool tigerAdultCheck = false;
            bool penguinAdultCheck = false;
            bool turtleAdultCheck = false;
            bool newAnimalAdultCheck = false;
            for (int i = 0; i < tigerCount; i++) {
                if (tigerArray[i]->getAge() >= 3) {
                    tigerAdultCheck = true;
                }
            }
            for (int i = 0; i < penguinCount; i++) {
                if (penguinArray[i]->getAge() >= 3) {
                    penguinAdultCheck = true;
                }
            }
            for (int i = 0; i < turtleCount; i++) {
                if (turtleArray[i]->getAge() >= 3) {
                    turtleAdultCheck = true;
                }
            }
            for (int i = 0; i < newAnimalCount; i++) {
                if (newAnimalArray[i]->getAge() >= 3) {
                    newAnimalAdultCheck = true;
                }
            }
            if (pickAnimal == 1 && tigerAdultCheck == true) {
                addBabyTiger();
                choice = false;
            }
            else if (pickAnimal == 2 && penguinAdultCheck == true) {
                addBabyPenguin();
                choice = false;
            }
            else if (pickAnimal == 3 && turtleAdultCheck == true) {
                addBabyTurtle();
                choice = false;
            }
            else if (pickAnimal == 4 && newAnimalAdultCheck == true) {
                addBabyNewAnimal();
                choice = false;
            }
            else {
                choice = true;
            }
        }
    }
}

int Zoo::inputValidation(string message, int min, int max){ //reusable input validation
    double input;
    bool repeatEntry = true;
    char errorTest;
    string inputLine;
    while (repeatEntry == true) {
        cout << message << endl;
        getline(cin, inputLine);
        stringstream lineStream(inputLine);
        if (!(lineStream >> input)) {
            cout << "Input was not a number. Please try again." << endl;
        } else if ((input < min) || (input > max)) {
            cout << "Input out of range. Please try again." << endl;
        } else if (input - static_cast<int>(input) != 0) {
            cout << "Input with decimals and not an integer. Please try again." << endl;
        } else if (lineStream >> errorTest) {
            cout << "Input with extra symbols and/or characters. Please try again." << endl;
        } else {
            repeatEntry = false;
            input = input;
            cout << "Input accepted." << endl;
        }
    }
    return input;
}

Zoo::~Zoo(){ //Destructor for Zoo class
    for (int i = 0; i < tigerArraySize; i++) {
        delete tigerArray[i];
    }
    delete [] tigerArray;
    tigerArray = nullptr;

    for (int i = 0; i < penguinArraySize; i++) {
        delete penguinArray[i];
    }
    delete [] penguinArray;
    penguinArray = nullptr;

    for (int i = 0; i < turtleArraySize; i++) {
        delete turtleArray[i];
    }
    delete [] turtleArray;
    turtleArray = nullptr;

    for (int i = 0; i < newAnimalArraySize; i++) {
        delete newAnimalArray[i];
    }
    delete [] newAnimalArray;
    newAnimalArray = nullptr;

}

void Zoo::ledgerSummary(){ //console print of daily summary and status of zoo
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "Day "<< day << " End:"<<endl;
    cout << "*************************************************************" << endl;
    cout << "Cash left: " << cash <<endl;
    cout << "*************************************************************" << endl;
    cout << "Tiger count: " << tigerCount << endl;
    cout << "Penguin count: " << penguinCount << endl;
    cout << "Turtle count: " << turtleCount << endl;
    if(allowNewAnimal == true){
        cout << newAnimalName <<" count: " << newAnimalCount << endl;
    }
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
}

void Zoo::randomEventExtract(int random) { //exports random event into text file (extra credit)
    string fileNameExtension;
    ofstream outputFile;
    while (!(outputFile.is_open())) { //loop until file is created
        string dayToString = to_string(day);
        fileNameExtension = "Random_Event_Day_" + dayToString + ".txt";
        outputFile.open(fileNameExtension);
        if (outputFile.is_open()) { //status display
            cout << "Extra Credit: Success: " << fileNameExtension << " is now open." << endl;
            cout << "Extra Credit: Success: " << fileNameExtension << " is written." << endl;
        }else{
            cout << "Failed: Incorrect file name format. Please try again." << endl;
        }
        if(random == 1){
            outputFile << "From Random Event File: Sickness occurs to an animal in the zoo. " << randomString << endl;
        }
        else if(random == 2){
            outputFile << "From Random Event File: A boom in zoo attendance occurs." << "Each tiger makes additional $" << randomBonus << endl;
        }
        else if(random == 3){
            outputFile << "From Random Event File: A baby animal is born. " << randomString << endl;
        }
        else if(random == 4){
            outputFile << "From Random Event File: Nothing happens." << endl;
        }
        else{
            outputFile << "Choice Error" << endl;
        }
    }outputFile.close(); //close new file
}

void Zoo::randomEventImport(){ //imports random event from text file (extra credit)
    string paragraph;
    ifstream inputFile;
    while(!(inputFile.is_open())) { //loop until file is found
        string dayToString = to_string(day);
        string fileNameRead = "Random_Event_Day_" + dayToString + ".txt";
        inputFile.open(fileNameRead.c_str());
        if (inputFile.is_open()) { //status display
            cout << "Extra Credit: File: " << fileNameRead << " is now open." << endl;
            cout << "Extra Credit: Success: " << fileNameRead << " is read." << endl;
            while (inputFile && !inputFile.eof()) {
                getline(inputFile, paragraph);
                cout << paragraph << endl;
            }
        }else{
            cout << "Failed: File specified does not exist. Please try again." << endl;
        }
    }inputFile.close(); //close ifstream file
}
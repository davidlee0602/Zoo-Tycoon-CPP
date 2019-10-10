/*********************************************************************
** Program name: Animal.cpp
** Author: David Lee
** Date: 04/28/2019
** Description: Implementation file for Animal class in project 2 program. Class member functions defined.
 *              Acts as the base, parent class for Tiger, Penguin, Turtle and NewAnimal classes.
 *              Member functions include constructor with data member initialization parameters, accessor for individual data members,
 *              and dayOlder() function that acts as a mutator by adding one to animal object age.
*********************************************************************/

#include "Animal.hpp"
Animal::Animal(int age, int cost, int number_of_babies, int base_food_cost, int payoff){ //base constructor with parameters
    this->age = age;
    this->cost = cost;
    this->number_of_babies = number_of_babies;
    this->base_food_cost = base_food_cost;
    this->payoff = payoff;
}

void Animal::dayOlder() { //mutator that adds one day to animal age
    age += 1;
}

int Animal::getAge() { //accessor returns age
    return age;
}

int Animal::getCost(){ //accessor returns cost
    return cost;
}

int Animal::get_number_of_babies(){ //accessor returns number of babies
    return number_of_babies;
}

int Animal::get_base_food_cost(){ //accessor returns food cost
    return base_food_cost;
}

int Animal::getPayoff(){ //accessor returns payoff
    return payoff;
}

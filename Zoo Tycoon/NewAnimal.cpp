/*********************************************************************
** Program name: NewAnimal.cpp
** Author: David Lee
** Date: 04/28/2019
** Description: Implementation file for Turtle class in project 2 program.
 *              Inherits from Animal Class (base).
 *              Constructor with age parameter calls base constructor and uses age in base constructor parameter.
*********************************************************************/

#include "NewAnimal.hpp"
NewAnimal::NewAnimal(int age, int cost, int number_of_babies, int base_food_cost, int payoff) : Animal(age, cost, number_of_babies, base_food_cost, payoff){

}
//NewAnimal constructor calls base constructor and initialize
// age to user provided age,
// cost to cost,
// number_of_babies to number_of_babies,
// base_food_cost to base_food_cost and
// payoff to payoff
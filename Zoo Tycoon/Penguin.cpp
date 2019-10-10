/*********************************************************************
** Program name: Penguin.cpp
** Author: David Lee
** Date: 04/28/2019
** Description: Implementation file for Penguin class in project 2 program.
 *              Inherits from Animal Class (base).
 *              Constructor with age parameter calls base constructor and uses age in base constructor parameter.
*********************************************************************/

#include "Penguin.hpp"
Penguin::Penguin(int age) : Animal(age, 1000, 5, 10, 100){

}
//Penguin constructor calls base constructor and initialize
// age to user provided age,
// cost to 1000,
// number_of_babies to 5,
// base_food_cost to 10 (1 times base food cost) and
// payoff to 100(10 percent of cost)
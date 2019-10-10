/*********************************************************************
** Program name: Turtle.cpp
** Author: David Lee
** Date: 04/28/2019
** Description: Implementation file for Turtle class in project 2 program.
 *              Inherits from Animal Class (base).
 *              Constructor with age parameter calls base constructor and uses age in base constructor parameter.
*********************************************************************/

#include "Turtle.hpp"
Turtle::Turtle(int age) : Animal(age, 100, 10, 5, 5){

}
//Turtle constructor calls base constructor and initialize
// age to user provided age,
// cost to 100,
// number_of_babies to 10,
// base_food_cost to 5 (1/2 times base food cost) and
// payoff to 5(5 percent of cost)
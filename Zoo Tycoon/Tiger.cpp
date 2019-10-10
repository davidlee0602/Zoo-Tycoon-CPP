/*********************************************************************
** Program name: Tiger.cpp
** Author: David Lee
** Date: 04/28/2019
** Description: Implementation file for Tiger class in project 2 program.
 *              Inherits from Animal Class (base).
 *              Constructor with age parameter calls base constructor and uses age in base constructor parameter.
*********************************************************************/

#include "Tiger.hpp"
Tiger::Tiger(int age) : Animal(age, 10000, 1, 50, 2000){

}
//Tiger constructor calls base constructor and initialize
// age to user provided age,
// cost to 10000,
// number_of_babies to 1,
// base_food_cost to 50 (5 times base food cost) and
// payoff to 2000(20 percent of cost)
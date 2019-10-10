/*********************************************************************
** Program name: NewAnimal.hpp
** Author: David Lee
** Date: 04/28/2019
** Description: Header file for NewAnimal class in project 2 program.
 *              Inherits from Animal Class (base).
 *              Constructor with age parameter calls base constructor and uses age in base constructor parameter.
*********************************************************************/

#ifndef NEWANIMAL_HPP
#define NEWANIMAL_HPP
#include "Animal.hpp"

class NewAnimal : public Animal { //inherits from Animal class
public: //constructor for NewAnimal object with age, cost, number_of_babies, base_food_cost and payoff parameter
    NewAnimal(int age, int cost, int number_of_babies, int base_food_cost, int payoff);
};



#endif

/*********************************************************************
** Program name: Animal.hpp
** Author: David Lee
** Date: 04/28/2019
** Description: Header file for Animal class in project 2 program.
 *              Acts as the base, parent class for Tiger, Penguin, Turtle and NewAnimal classes.
 *              Data members age, cost, number_of_babies, base_food_cost, payoff used as shared properties for all animals.
 *              Member functions include constructor with data member initialization parameters, accessor for individual data members,
 *              and dayOlder() function that acts as a mutator by adding one to animal object age.
*********************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP


class Animal {
private:
    int age; //store age of animal
    int cost; //store cost of animal
    int number_of_babies; //store count of babies per animal
    int base_food_cost; //store food cost of animal
    int payoff; //store animal payoff
public:
    Animal(int age, int cost, int number_of_babies, int base_food_cost, int payoff); //base constructor with parameters
    void dayOlder(); //mutator that adds one day to animal age
    int getAge(); //accessor returns age
    int getCost(); //accessor returns cost
    int get_number_of_babies(); //accessor returns number of babies
    int get_base_food_cost(); //accessor returns food cost
    int getPayoff(); //accessor returns payoff

};


#endif

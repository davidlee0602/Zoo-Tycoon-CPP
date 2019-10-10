/*********************************************************************
** Program name: Turtle.hpp
** Author: David Lee
** Date: 04/28/2019
** Description: Header file for Turtle class in project 2 program.
 *              Inherits from Animal Class (base).
 *              Constructor with age parameter calls base constructor and uses age in base constructor parameter.
*********************************************************************/

#ifndef TURTLE_HPP
#define TURTLE_HPP
#include "Animal.hpp"

class Turtle : public Animal { //inherits from Animal class
public:
    Turtle(int age); //constructor for Turtle object with age parameter
};

#endif

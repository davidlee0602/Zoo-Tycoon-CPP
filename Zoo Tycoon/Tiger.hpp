/*********************************************************************
** Program name: Tiger.hpp
** Author: David Lee
** Date: 04/28/2019
** Description: Header file for Tiger class in project 2 program.
 *              Inherits from Animal Class (base).
 *              Constructor with age parameter calls base constructor and uses age in base constructor parameter.
*********************************************************************/

#ifndef TIGER_HPP
#define TIGER_HPP
#include "Animal.hpp"

class Tiger : public Animal { //inherits from Animal class
public:
    Tiger(int age); //constructor for Tiger object with age parameter
};

#endif

/*********************************************************************
** Program name: Penguin.hpp
** Author: David Lee
** Date: 04/28/2019
** Description: Header file for Penguin class in project 2 program.
 *              Inherits from Animal Class (base).
 *              Constructor with age parameter calls base constructor and uses age in base constructor parameter.
*********************************************************************/

#ifndef PENGUIN_HPP
#define PENGUIN_HPP
#include "Animal.hpp"

class Penguin : public Animal { //inherits from Animal class
public:
    Penguin(int age); //constructor for Penguin object with age parameter
};

#endif

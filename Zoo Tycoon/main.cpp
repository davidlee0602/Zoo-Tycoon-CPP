/*********************************************************************
** Program name: main.cpp
** Author: David Lee
** Date: 04/28/2019
** Description: Main function and entry point for the project 2 program.
 *              The program implements inheritance.
 *              The program is Zoo Tycoon game simulation. Zoo tycoon is a game that allows players to run a zoo business.
 *              Different types of animals prices with different upkeep costs and return a different profit at the end of each day.
 *              For this game, the player manage a virtual zoo that has tigers, penguins, turtles and their own specified animal(if they choose).
*********************************************************************/

#include <iostream>
#include "Zoo.hpp"

int main() {
    Zoo zoo; //initialize Zoo object
    zoo.menu(); //starts Zoo game
    return 0;
}
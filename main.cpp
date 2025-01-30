/**
* Solution to course project #6
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2024/2025
* 
* @author Maksim Hristov
* @idnumber 4MI0600466 @compiler GCC 
* 
* <start of the program>
*/

#include <iostream>
#include "menuSystem.h"

int main() {
  short role = 0; //0 - user, 1 - admin, 2 - exit
  signIn(role);
  showMenu(role);
  
  return 0;
}
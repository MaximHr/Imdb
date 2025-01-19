#include <iostream>
#include "menuSystem.h"

int main() {
  short role = 0; //0 - user, 1 - admin, 2 - exit
  signIn(role);
  showMenu(role);
  
  return 0;
}
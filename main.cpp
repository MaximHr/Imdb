#include <iostream>
#include "menuSystem.h"

int main() {
  bool isAdmin;
  signIn(isAdmin);
  showMenu(isAdmin);

  return 0;
}
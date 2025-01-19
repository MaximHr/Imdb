#include <iostream>
#include "menuSystem.h"
#include "constants.h"
#include "helperFunctions.h"
#include "movies.h"

const char* getMenuArray(bool isAdmin, int index);
void handleOption(const char* option, bool& isAdmin);

void handleOption(const char* option, bool& isAdmin) {
  if(option == nullptr) return;
  short role = isAdmin;
  
  if(areEqualStr(option, "Add a movie")) {
    addMovie();
  } else if(areEqualStr(option, "Search for a movie")) {
    searchMovie();
  } else if(areEqualStr(option, "View all movies")) {
    viewMovies();
  } else if(areEqualStr(option, "Edit a movie")) {
    editMovie();
  } else if(areEqualStr(option, "Delete a movie")) {
    deleteMovie();
  } else if(areEqualStr(option, "Sort movies")) {
    sortMovie();
  } else if(areEqualStr(option, "Rate a movie")) {
    rateMovie();
  } else if(areEqualStr(option, "Filter movies by rating")) {
    filterByRating();
  } else if(areEqualStr(option, "Log out")) {
    signIn(role);
    showMenu(role);
  } else {
    std::cout << "Invalid option" << std::endl;
  }
  if(role != 2) showMenu(isAdmin);
}

const char* getMenuArray(bool isAdmin, int index) {
  return (isAdmin ? ADMIN_MENU_OPTIONS[index] : USER_MENU_OPTIONS[index]);
}

void showMenu(short role) {
  if(role == 2) return;
  const unsigned length = (role ? ADMIN_OPTIONS_LENGTH : USER_OPTIONS_LENGTH);
  unsigned choice;
  for(int i = 0;i < length;i++) {
    std::cout << i + 1 << ". " << getMenuArray(role, i) << '\n';
  }
  do {
    std::cin >> choice;
  } while(choice > length || choice < 1);
  const char* option = getMenuArray(role, choice - 1);
  bool isAdmin = role;
  handleOption(option, isAdmin);
}


void signIn(short& role) {
  std::cout << "Welcom to IMDB !" << std::endl;
  std::cout << "1. Log in as user" << std::endl;
  std::cout << "2. Log in as admin" << std::endl;
  std::cout << "3. Exit" << std::endl;
  char options[] = {'1', '2', '3'};
  role = chooseOption(options) - 1; //0 - user, 1 - admin
}
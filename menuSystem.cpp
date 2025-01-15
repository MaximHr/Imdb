#include <iostream>
#include "menuSystem.h"
#include "constants.h"
#include "helperFunctions.h"
#include "movies.h"

const char* getMenuArray(bool isAdmin, int index);
void handleOption(const char* option, bool& isAdmin);

void handleOption(const char* option, bool& isAdmin) {
  if(option == nullptr) return;
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
    signIn(isAdmin);
    showMenu(isAdmin);
  }
}

const char* getMenuArray(bool isAdmin, int index) {
  return (isAdmin ? ADMIN_MENU_OPTIONS[index] : USER_MENU_OPTIONS[index]);
}

void showMenu(bool& isAdmin) {
  const unsigned length = (isAdmin ? ADMIN_OPTIONS_LENGTH : USER_OPTIONS_LENGTH);
  unsigned choice;
  for(int i = 0;i < length;i++) {
    std::cout << i + 1 << ". " << getMenuArray(isAdmin, i) << '\n';
  }
  do {
    std::cin >> choice;
  } while(choice > length || choice < 1);
  const char* option = getMenuArray(isAdmin, choice - 1);
  handleOption(option, isAdmin);
}

void signIn(bool& isAdmin) {
  std::cout << "Welcom to IMDB !" << std::endl;
  std::cout << "Enter the number in front of the option you want" << std::endl;
  std::cout << "1. Log in as user" << std::endl;
  std::cout << "2. Log in as admin" << std::endl;
  int userInput;
  do {
    std::cin >> userInput;
    // user can type either 1 - to access normal user options or 2 - to access admin options
  } while(userInput > 2 || userInput < 1); 
  isAdmin = (userInput - 1);
}
/**
* Solution to course project #6
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2024/2025
* 
* @author Maksim Hristov
* @idnumber 4MI0600466 @compiler GCC 
* 
* <menu logic>
*/

#include <iostream>
#include "menuSystem.h"
#include "constants.h"
#include "helperFunctions.h"
#include "movies.h"
#include "filesHelper.h"

const char* getMenuArray(bool isAdmin, int index);

void handleOption(const char* option, short& role) {
  if(option == nullptr) return;
  
  if(areEqualStr(option, "Add a movie")) {
    addMovie();
  } else if(areEqualStr(option, "Search for a movie")) {
    searchMovie();
  } else if(areEqualStr(option, "View all movies")) {
    readFromFile(DATABASE, &printAllMovies);
  } else if(areEqualStr(option, "Edit a movie")) {
    readFromFile(DATABASE, &getLineByTitleAndEdit);
    changeFiles();
  } else if(areEqualStr(option, "Delete a movie")) {
    readFromFile(DATABASE, &getLineByTitleAndDelete);
    changeFiles();
  } else if(areEqualStr(option, "Sort movies")) {
    sortMovie();
  } else if(areEqualStr(option, "Rate a movie")) {
    readFromFile(DATABASE, &getLineByTitleAndRate);
    changeFiles();
  } else if(areEqualStr(option, "Filter movies by rating")) {
    readFromFile(DATABASE, &printFilteredMovies);
  } else if(areEqualStr(option, "Log out")) {
    signIn(role);
    showMenu(role);
  } else {
    std::cout << "Invalid option" << std::endl;
  }
  showMenu(role);
}

const char* getMenuArray(bool isAdmin, int index) {
  return (isAdmin ? ADMIN_MENU_OPTIONS[index] : USER_MENU_OPTIONS[index]);
}

void showMenu(short role) {
  if(role > 1) return;
  const unsigned length = (role ? ADMIN_OPTIONS_LENGTH : USER_OPTIONS_LENGTH);
  unsigned choice;
  for(int i = 0;i < length;i++) {
    std::cout << i + 1 << ". " << getMenuArray(role, i) << '\n';
  }
  do {
    std::cin >> choice;
    if(!isNumber(choice)) {
      continue;
    }
  } while(choice > length || choice < 1);
  
  const char* option = getMenuArray(role, choice - 1);
  handleOption(option, role);
}


void signIn(short& role) {
  std::cout << "Welcom to IMDB !" << std::endl;
  std::cout << "1. Log in as user" << std::endl;
  std::cout << "2. Log in as admin" << std::endl;
  std::cout << "3. Exit" << std::endl;
  char options[] = {'1', '2', '3'};
  role = chooseOption(options) - 1; //0 - user, 1 - admin
  if(role == 2) {
    exit(0);
  }
}
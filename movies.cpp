#include <iostream>
#include <fstream>
#include "filesHelper.h"
#include "constants.h"

void addMovie() {
  
}
void searchMovie() {

}
void editMovie() {

}
void deleteMovie() {

}
void sortMovie() {

}
void rateMovie() {

}
void filterByRating() {

}

void printAllMovies(std::ifstream &file , char* line) {
  std::cout << "List of movies: " << std::endl;
  while(file.getline(line, MENU_MAX_CHARACTERS)) {
    std::cout << line << std::endl;
  }
}
void viewMovies() {
  readFromFile(DATABASE, &printAllMovies);
}
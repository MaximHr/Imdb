#include <iostream>
#include <fstream>
#include "movies.h"
#include "filesHelper.h"
#include "constants.h"
#include "helperFunctions.h"

char* getStrInput(const char* printText) {
  char temp[1024];
  unsigned length = 0;
  bool hasSeparator = false;
  do {
    if(printText != nullptr) {
      std::cout <<  printText;
    }
    std::cin.getline(temp, 1024);
    length = strLength(temp) + 1;
    hasSeparator = strContains(temp, SEPARATING_CHAR);
    if(hasSeparator) std::cout << "Input can not contain character " << SEPARATING_CHAR << '\n';

  } while(length <= 1 || length > 2024 || hasSeparator);
  
  char* string = new char[length];
  copyStr(string, temp);

  return string;
}

char* createLine(const char* title, const char* genre, const char* releaseDate, float rating, const char* director){
  if(title == nullptr || genre == nullptr || director == nullptr) return nullptr;
  const unsigned titleLength = strLength(title), genreLength = strLength(genre);
  const unsigned releaseDateLength = strLength(releaseDate), directorLength = strLength(director);
  // 4 допълнителна места за SEPARATING_CHAR-oвете и 1 за терминиращата нула. общо 5
  const unsigned totalLength = titleLength + genreLength + directorLength + releaseDateLength + 5;
  char* result = new char[totalLength];
  copyStr(result, title);
  strConcat(result, SEPARATING_CHAR);
  strConcat(result, genre);
  strConcat(result, SEPARATING_CHAR);
  strConcat(result, releaseDate);
  strConcat(result, SEPARATING_CHAR);
  strConcat(result, "5.0");
  strConcat(result, SEPARATING_CHAR);
  strConcat(result, director);

  return result;
}

void addMovie() {
  clearInputBuffer();
  const char* title = getStrInput("Title: ");
  const char* genre = getStrInput("Genre: ");
  
  char* releaseDate = nullptr;
  unsigned short releaseDateNumber = 0;
  do {
    if(releaseDate != nullptr) {
      delete[] releaseDate;
    }
    releaseDate = getStrInput("Release Date: ");
    releaseDateNumber = getNumber(releaseDate);
  } while(releaseDateNumber < 1800 || releaseDateNumber > 9999);

  const char* director = getStrInput("Director: ");
  
  char* line = createLine(title, genre, releaseDate, 5, director);
  if(line != nullptr) {
    addNewLineToFile(DATABASE, line);
    std::cout << "Movie added succesfully";
  } 
  delete[] title;
  delete[] genre;
  delete[] director;
  delete[] releaseDate;
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
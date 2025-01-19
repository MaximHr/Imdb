#include <iostream>
#include <fstream>
#include "movies.h"
#include "filesHelper.h"
#include "constants.h"
#include "helperFunctions.h"

void searchByTitle(std::ifstream &file , char* line);
void searchByGenre(std::ifstream &file , char* line);
void searchByAnyCriteria(std::ifstream &file , char* line);
void getLineByTitleAndEdit(std::ifstream &file , char* line);
void getLineByTitleAndDelete(std::ifstream &file , char* line);
char* findMovieDetail(const char* str, char symbol, int n);

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

char* createLine(const char* title, const char* genre, const char* releaseDate, const char* rating, const char* director){
  if(title == nullptr || genre == nullptr || director == nullptr) return nullptr;
  const unsigned titleLength = strLength(title), genreLength = strLength(genre);
  const unsigned releaseDateLength = strLength(releaseDate), directorLength = strLength(director);
  // 4 допълнителна места за SEPARATING_CHAR-oвете и 1 за терминиращата нула. общо 5
  const unsigned totalLength = titleLength + genreLength + directorLength + releaseDateLength + 5;
  char* result = new char[totalLength];
  // title|genre|releaseDate|rating|director
  copyStr(result, title);
  strConcat(result, SEPARATING_CHAR);
  strConcat(result, genre);
  strConcat(result, SEPARATING_CHAR);
  strConcat(result, releaseDate);
  strConcat(result, SEPARATING_CHAR);
  strConcat(result, rating);
  strConcat(result, SEPARATING_CHAR);
  strConcat(result, director);

  return result;
}

char* getReleaseDate() {
  char* releaseDate = nullptr;
  unsigned short releaseDateNumber = 0;
  do {
    if(releaseDate != nullptr) {
      delete[] releaseDate;
    }

    releaseDate = getStrInput("Release Date: ");
    releaseDateNumber = getNumber(releaseDate);
  } while(releaseDateNumber < 1800 || releaseDateNumber > 9999);

  return releaseDate;
}

void addMovie() {
  clearInputBuffer();
  const char* title = getStrInput("Title: ");
  const char* genre = getStrInput("Genre: ");
  const char* releaseDate = getReleaseDate();
  const char* director = getStrInput("Director: ");
  char* line = createLine(title, genre, releaseDate, "5.0", director);

  if(line != nullptr) {
    addNewLineToFile(DATABASE, line);
    std::cout << "Movie added succesfully";
  } else {
    std::cout << "Failed to add movie. Please try again.";
  }
  delete[] line;
  delete[] title;
  delete[] genre;
  delete[] director;
  delete[] releaseDate;

}

void searchMovie() {
  std::cout << "Type 1 to search by genre" << '\n';
  std::cout << "Type 2 to search by title" << '\n';
  std::cout << "Type 3 to search by any criteria" << '\n';
  int choice = chooseOption("123"); // same as { '1', '2', '3' }

  switch(choice) {
    case 1:
      readFromFile(DATABASE, searchByGenre);
      break;
    case 2:
      readFromFile(DATABASE, searchByTitle);
      break;
    case 3:
      readFromFile(DATABASE, searchByAnyCriteria);
      break;
  }
}
void editMovie() {
  readFromFile(DATABASE, &getLineByTitleAndEdit);
}
void deleteMovie() {
  readFromFile(DATABASE, &getLineByTitleAndDelete);
}
void sortMovie() {
  std::cout << "Type 1 to sort movies by title" << '\n';
  std::cout << "Type 2 to sort movies by rating" << '\n';
  int choice = chooseOption("12"); // same as { '1', '2' }
  if(choice == 1) {
    //sort by title
  } else {
    //sort by rating
  }
}
void rateMovie() {

}
void printFilteredMovies(std::ifstream &file , char* line) {
  clearInputBuffer();

  const char* rating = nullptr;
  float ratingNumber = 0;
  do {
    if(rating != nullptr) {
      delete[] rating;
    }
    rating = getStrInput("Enter rating: ");
    ratingNumber = getFloatNumber(rating);
  } while(!isBetween(ratingNumber, 0, MAXIMUM_RATING));
  
  std::cout << "Movies with rating greater or equal to " << ratingNumber << '\n'; 
  while(file.getline(line, LINE_MAX_CHARACTERS)) {
    char* movieRating = findMovieDetail(line, SEPARATING_CHAR, 3);
    float movieRatingNumber = getFloatNumber(movieRating);
    if(movieRatingNumber >= ratingNumber) {
      std::cout << line << std::endl;
    }
    delete[] movieRating;
  }

  delete[] rating;
}
void filterByRating() {
  readFromFile(DATABASE, &printFilteredMovies);
}

//finds string between the n-th 1symbol and n-th + 1 separating symbol
char* findMovieDetail(const char* str, char symbol, int n) {
  if(str == nullptr) return nullptr;
  int count = 0;
  while(*str != '\0') {
    if(*str == symbol) {
      count++;
    }
    if(count == n) {
      //copy array till the next separator
      if(count > 0) str++;
      char maxLength = strLength(str);
      char temp[maxLength];
      unsigned i = 0;
      while(*str != symbol) {
        temp[i] = *str; 
        str++;
        i++;
      }
      temp[i] = '\0';
      char* result = new char[i + 1];
      copyStr(result, temp);
      return result;
    }
    str++;
  }
  return nullptr;
}

void searchByAnyCriteria(std::ifstream &file , char* line) {
  clearInputBuffer();
  char* criteria = getStrInput("Enter criteria: ");
  while(file.getline(line, LINE_MAX_CHARACTERS)) {
    if(strContains(line, criteria, false)) {
      std::cout << line << std::endl;
    }
  }
  delete[] criteria;
}
void searchByTitle(std::ifstream &file , char* line) {
  clearInputBuffer();
  char* title = getStrInput("Enter title: ");
  while(file.getline(line, LINE_MAX_CHARACTERS)) {
    char* movieTitle = findMovieDetail(line, SEPARATING_CHAR, 0);
    if(movieTitle != nullptr && strContains(movieTitle, title, false)) {
      std::cout << line << std::endl;
    }
    delete[] movieTitle;
  }
  delete[] title;
}

void getLineByTitleAndDelete(std::ifstream &file , char* line) {
  clearInputBuffer();
  char* title = getStrInput("Enter title: ");
  while(file.getline(line, LINE_MAX_CHARACTERS)) {
    char* movieTitle = findMovieDetail(line, SEPARATING_CHAR, 0);
    if(movieTitle != nullptr && areEqualStr(movieTitle, title)) {
      std::cout << line << std::endl;
      deleteLineFromFile(DATABASE, line);
    }
    delete[] movieTitle;
  }
  delete[] title;
}
void getLineByTitleAndEdit(std::ifstream &file , char* line) {
  clearInputBuffer();
  char* title = getStrInput("Enter title: ");
  
  while(file.getline(line, LINE_MAX_CHARACTERS)) {
    char* movieTitle = findMovieDetail(line, SEPARATING_CHAR, 0);
    if(movieTitle != nullptr && areEqualStr(movieTitle, title)) {
      std::cout << line << std::endl;
      const char* title = getStrInput("New title: ");
      const char* genre = getStrInput("New genre: ");
      const char* releaseDate = getReleaseDate();
      const char* director = getStrInput("New director: ");
      const char* rating = findMovieDetail(line, SEPARATING_CHAR, 3);
      char* newLine = createLine(title, genre, releaseDate, rating, director);
      editLineInFile(DATABASE, line, newLine);
      delete[] newLine;
      delete[] title;
      delete[] genre;
      delete[] rating;
      delete[] director;
      delete[] releaseDate;

    }
    delete[] movieTitle;
  }
  delete[] title;
  
}

void searchByGenre(std::ifstream &file , char* line) {
  clearInputBuffer();
  char* genre = getStrInput("Enter genre: ");
  while(file.getline(line, LINE_MAX_CHARACTERS)) {
    char* movieGenre = findMovieDetail(line, SEPARATING_CHAR, 1);
    if(movieGenre != nullptr && areEqualStr(movieGenre, genre)) {
      std::cout << line << std::endl;
    }
    delete[] movieGenre;
  }
  delete[] genre;
}
void printAllMovies(std::ifstream &file , char* line) {
  std::cout << "List of movies: " << std::endl;
  while(file.getline(line, LINE_MAX_CHARACTERS)) {
    std::cout << line << std::endl;
  }
}
void viewMovies() {
  readFromFile(DATABASE, &printAllMovies);
}
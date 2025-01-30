#include <iostream>
#include <fstream>
#include "movies.h"
#include "filesHelper.h"
#include "constants.h"
#include "helperFunctions.h"

void searchByTitle(std::ifstream &file , char* line);
void searchByGenre(std::ifstream &file , char* line);
void searchByAnyCriteria(std::ifstream &file , char* line);
char* findMovieDetail(const char* str, char symbol, int n);
void getLineByTitleAndRate(std::ifstream &file, char* line);
void getLineByTitleAndEdit(std::ifstream &file , char* line);
void getLineByTitleAndDelete(std::ifstream &file , char* line);

char* getStrInput(const char* printText) {
  char temp[LINE_MAX_CHARACTERS];
  unsigned length = 0;
  bool hasSeparator = false;
  do {
    if(printText != nullptr) {
      std::cout <<  printText;
    }
    std::cin.getline(temp, LINE_MAX_CHARACTERS);
    length = strLength(temp) + 1;
    hasSeparator = strContains(temp, SEPARATING_CHAR);
    if(hasSeparator) std::cout << "Input can not contain character " << SEPARATING_CHAR << '\n';

  } while(length <= 1 || length > LINE_MAX_CHARACTERS || hasSeparator);
  char* string = new char[length];
  copyStr(string, temp);

  return string;
}

char* createLine(const char* title, const char* genre, const char* releaseDate, const char* rating, const char* cast){
  if(title == nullptr || genre == nullptr || cast == nullptr || rating == nullptr || releaseDate == nullptr) return nullptr;
  const unsigned titleLength = strLength(title);
  const unsigned genreLength = strLength(genre);
  const unsigned releaseDateLength = strLength(releaseDate);
  const unsigned castLength = strLength(cast);
  const unsigned ratingLength = strLength(rating);

  // 4 допълнителна места за SEPARATING_CHAR-oвете и 1 за терминиращата нула. общо 5
  const unsigned totalLength = ratingLength + titleLength + genreLength + castLength + releaseDateLength + 5;
  char* result = new char[totalLength];

  // title|genre|releaseDate|rating|cast
  copyStr(result, title);
  strConcat(result, SEPARATING_CHAR);
  strConcat(result, genre);
  strConcat(result, SEPARATING_CHAR);
  strConcat(result, releaseDate);
  strConcat(result, SEPARATING_CHAR);
  strConcat(result, rating);
  strConcat(result, SEPARATING_CHAR);
  strConcat(result, cast);

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

void setRating(const char* rating, float& ratingNumber) {
  do {
    if(rating != nullptr) {
      delete[] rating;
    }
    rating = getStrInput("Enter rating: ");
    ratingNumber = roundNumber(getFloatNumber(rating));
  } while(!isBetween(ratingNumber, 0, MAXIMUM_RATING));
}

void addMovie() {
  clearInputBuffer();
  const char* title = getStrInput("Title: ");
  const char* genre = getStrInput("Genre: ");
  const char* releaseDate = getReleaseDate();
  const char* cast = getStrInput("Cast and crew: ");
  char* line = createLine(title, genre, releaseDate, "5.0", cast);

  if(line != nullptr) {
    addNewLineToFile(DATABASE, line);
    std::cout << "Movie added succesfully" << '\n';
  } else {
    std::cout << "Failed to add movie. Please try again." << '\n';
  }
  delete[] line;
  delete[] title;
  delete[] genre;
  delete[] cast;
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

void deleteMovie(){
  readFromFile(DATABASE, &getLineByTitleAndDelete);
  if(fileExists(TEMP_FILE)) {
    remove(DATABASE);
    rename(TEMP_FILE, DATABASE);
  }
}
void editMovie(){
  readFromFile(DATABASE, &getLineByTitleAndEdit);
  if(fileExists(TEMP_FILE)) {
    remove(DATABASE);
    rename(TEMP_FILE, DATABASE);
  }
}
void rateMovie(){
  readFromFile(DATABASE, &getLineByTitleAndRate);
  if(fileExists(TEMP_FILE)) {
    remove(DATABASE);
    rename(TEMP_FILE, DATABASE);
  }
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

void getLineByTitleAndRate(std::ifstream &file, char* line) {
  clearInputBuffer();
  const char* title = getStrInput("Enter title: ");
  
  while(file.getline(line, LINE_MAX_CHARACTERS)) {
    const char* movieTitle = findMovieDetail(line, SEPARATING_CHAR, 0);
    if(movieTitle != nullptr && areEqualStr(movieTitle, title)) {
      const char* genre = findMovieDetail(line, SEPARATING_CHAR, 1);
      const char* releaseDate = findMovieDetail(line, SEPARATING_CHAR,2);
      const char* cast = findMovieDetail(line, SEPARATING_CHAR, 4);
      const char* oldRating = findMovieDetail(line, SEPARATING_CHAR, 3);
      float oldRatingNumber = roundNumber(getFloatNumber(oldRating));
      
      const char* updatedRating = nullptr;
      float updatedRatingNumber = 0;
      setRating(updatedRating, updatedRatingNumber);
      delete[] updatedRating;
      updatedRatingNumber = (oldRatingNumber + updatedRatingNumber) / 2; //average rating
      updatedRatingNumber = roundNumber(updatedRatingNumber);
      updatedRating = floatToString(updatedRatingNumber);
      std::cout << updatedRating << '\n';
      char* newLine = createLine(movieTitle, genre, releaseDate, updatedRating, cast);
      editLineInFile(DATABASE, line, newLine);

      delete[] newLine;
      delete[] genre;
      delete[] oldRating;
      delete[] cast;
      delete[] releaseDate;
      delete[] updatedRating;

    }
    delete[] movieTitle;
  }
  delete[] title;
}

void printFilteredMovies(std::ifstream &file , char* line) {
  clearInputBuffer();

  char* rating = nullptr;
  float ratingNumber = 0;
  setRating(rating, ratingNumber);
  
  std::cout << "Movies with rating greater or equal to " << ratingNumber << '\n'; 
  while(file.getline(line, LINE_MAX_CHARACTERS)) {
    const char* movieRating = findMovieDetail(line, SEPARATING_CHAR, 3);
    float movieRatingNumber = roundNumber(getFloatNumber(movieRating));
    if(movieRatingNumber >= ratingNumber) {
      std::cout << line << std::endl;
    }
    delete[] movieRating;
  }

  delete[] rating;
}

//finds string between the n-th separating symbol and n-th + 1 separating symbol
char* findMovieDetail(const char* str, char symbol, int n) {
  if (str == nullptr) return nullptr;

  int count = 0;
  const char* start = nullptr;

  // Find the nth separator
  if (n == 0) {
    start = str;
  } else {
    while (*str != '\0') {
      if (*str == symbol) {
        count++;
        if (count == n) {
          start = str + 1; // Move to the character after the nth separator
          break;
        }
      }
      str++;
    }
  }

  // If nth separator is not found, return nullptr
  if (start == nullptr || *start == '\0') return nullptr;

  // Find the length of the substring until the next separator or end of string
  const char* end = start;
  while (*end != symbol && *end != '\0') {
    end++;
  }

  // Allocate memory for the substring and copy it
  size_t length = end - start;
  char* result = new char[length + 1]; // +1 for the null terminator
  for (size_t i = 0; i < length; i++) {
    result[i] = start[i];
  }
  result[length] = '\0'; // Null-terminate the string

  return result;
}


void searchByAnyCriteria(std::ifstream &file , char* line) {
  clearInputBuffer();
  const char* criteria = getStrInput("Enter criteria: ");
  while(file.getline(line, LINE_MAX_CHARACTERS)) {
    if(strContains(line, criteria, false)) {
      std::cout << line << std::endl;
    }
  }
  delete[] criteria;
}

void searchByTitle(std::ifstream &file , char* line) {
  clearInputBuffer();
  const char* title = getStrInput("Enter title: ");
  
  while(file.getline(line, LINE_MAX_CHARACTERS)) {
    const char* movieTitle = findMovieDetail(line, SEPARATING_CHAR, 0);
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
    const char* movieTitle = findMovieDetail(line, SEPARATING_CHAR, 0);
    if(movieTitle != nullptr && areEqualStr(movieTitle, title)) {
      std::cout << "Movie Deleted" << std::endl;
      deleteLineFromFile(DATABASE, line);
    }
    delete[] movieTitle;
  }
  delete[] title;
}

void getLineByTitleAndEdit(std::ifstream &file , char* line) {
  clearInputBuffer();
  const char* title = getStrInput("Enter title: ");
  
  while(file.getline(line, LINE_MAX_CHARACTERS)) {
    const char* movieTitle = findMovieDetail(line, SEPARATING_CHAR, 0);
    if(movieTitle != nullptr && areEqualStr(movieTitle, title)) {
      std::cout << line << std::endl;
      const char* title = getStrInput("New title: ");
      const char* genre = getStrInput("New genre: ");
      const char* releaseDate = getReleaseDate();
      const char* cast = getStrInput("New cast and crew: ");
      const char* rating = findMovieDetail(line, SEPARATING_CHAR, 3);
      char* newLine = createLine(title, genre, releaseDate, rating, cast);
      
      editLineInFile(DATABASE, line, newLine);
      delete[] newLine;
      delete[] title;
      delete[] genre;
      delete[] rating;
      delete[] cast;
      delete[] releaseDate;
    }
    delete[] movieTitle;
  }
  delete[] title;
}

void searchByGenre(std::ifstream &file , char* line) {
  clearInputBuffer();
  const char* genre = getStrInput("Enter genre: ");
  while(file.getline(line, LINE_MAX_CHARACTERS)) {
    const char* movieGenre = findMovieDetail(line, SEPARATING_CHAR, 1);
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
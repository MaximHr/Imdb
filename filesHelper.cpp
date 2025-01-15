#include <iostream>
#include <fstream>
#include "filesHelper.h"
#include "constants.h"

void addNewLineToFile(const char* filename, const char* content) {
  if(filename == nullptr || content == nullptr) return;

  std::ofstream file(filename, std::ios::app);
  if (file.is_open()) {
    file << content << std::endl;
  } else {
    std::cout << "Failed to connect to the database. Please try again." << std::endl;
  }
  file.close();
}

void readFromFile(const char* filename, void (*queryDatabase)(std::ifstream& file , char* line)) {
  if(filename == nullptr || queryDatabase == nullptr) return;

  std::ifstream file(filename);
  if(file.is_open()) {
    char line[LINE_MAX_CHARACTERS];
    queryDatabase(file, line);
  } else {
    std::cout << "Failed to connect to the database. Please try again." << std::endl;
  }
  file.close();
}
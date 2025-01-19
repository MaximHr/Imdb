#include <iostream>
#include <fstream>
#include "filesHelper.h"
#include "helperFunctions.h"
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


void editLineInFile(const char* filename, const char* lineToEdit, const char* newLine) {
  if(filename == nullptr || lineToEdit == nullptr || newLine == nullptr) return;

  std::ifstream file(filename);
  if(file.is_open()) {
    std::ofstream tempFile("temp.txt");
    char line[LINE_MAX_CHARACTERS];
    while(file.getline(line, LINE_MAX_CHARACTERS)) {
      if(areEqualStr(line, lineToEdit)) {
        tempFile << newLine << std::endl;
      } else {
        tempFile << line << std::endl;
      }
    }
    file.close();
    tempFile.close();
    std::remove(filename);
    std::rename("temp.txt", DATABASE);
  } else {
    std::cout << "Failed to connect to the database. Please try again." << std::endl;
  }
}

void deleteLineFromFile(const char* filename, const char* lineToDelete) {
  if(filename == nullptr || lineToDelete == nullptr) return;

  std::ifstream file(filename);
  if(file.is_open()) {
    std::ofstream tempFile("temp.txt");
    char line[LINE_MAX_CHARACTERS];
    while(file.getline(line, LINE_MAX_CHARACTERS)) {
      if(!areEqualStr(line, lineToDelete)) {
        tempFile << line << std::endl;
      }
    }
    file.close();
    tempFile.close();
    int res = std::remove(filename);
    
    std::rename("temp.txt", filename);
  } else {
    std::cout << "Failed to connect to the database. Please try again." << std::endl;
  }
}
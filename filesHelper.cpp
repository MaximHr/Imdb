/**
* Solution to course project #6
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2024/2025
* 
* @author Maksim Hristov
* @idnumber 4MI0600466 @compiler GCC 
* 
* <files logic>
*/

#include <iostream>
#include <fstream>
#include "filesHelper.h"
#include "helperFunctions.h"
#include "constants.h"

bool fileExists(const char* filename) {
	if (filename == nullptr) return false;
 	std::ifstream file(filename);
 	if (file.good()) {
  	file.close();
    return true;
  }
  return false;
}

void changeFiles() {
  if (fileExists(TEMP_FILE)) {
    remove(DATABASE);
    rename(TEMP_FILE, DATABASE);
  }
}

void addNewLineToFile(const char* filename, const char* content) {
	if (filename == nullptr || content == nullptr) return;

  std::ofstream file(filename, std::ios::app);
  if (file.is_open()) {
    file << content << std::endl;
  } else {
    std::cout << "Failed to connect to the database. Please try again." << std::endl;
  }
  file.close();
}

void readFromFile(const char* filename, void (*queryDatabase)(std::ifstream& file , char* line)) {
  if (filename == nullptr || queryDatabase == nullptr) return;

  std::ifstream file(filename);
  if (file.is_open()) {
    char line[LINE_MAX_CHARACTERS];
    queryDatabase(file, line);
  } else {
    std::cout << "Failed to connect to the database. Please try again." << std::endl;
  }
  file.close();
}

void editLineInFile(const char* filename, const char* lineToEdit, const char* newLine) {
  if (filename == nullptr || lineToEdit == nullptr || newLine == nullptr) return;

  std::ifstream file(filename);
  if (file.is_open()) {
  	std::ofstream tempFile(TEMP_FILE);
    char line[LINE_MAX_CHARACTERS];
    while (file.getline(line, LINE_MAX_CHARACTERS)) {
      if (areEqualStr(line, lineToEdit)) {
      	tempFile << newLine << std::endl;
      } else {
        tempFile << line << std::endl;
      }
    }
    file.close();
    tempFile.close();
  } else {
    std::cout << "Failed to connect to the database. Please try again." << std::endl;
  }
}

void deleteLineFromFile(const char* filename, const char* lineToDelete) {
  if (filename == nullptr || lineToDelete == nullptr) return;

  std::ifstream file(filename);
  if (file.is_open()) {
    std::ofstream tempFile(TEMP_FILE);
    char line[LINE_MAX_CHARACTERS];
    while (file.getline(line, LINE_MAX_CHARACTERS)) {
      if (!areEqualStr(line, lineToDelete)) {
        tempFile << line << std::endl;
      }
    }
    file.close();
    tempFile.close();
  } else {
    std::cout << "Failed to connect to the database. Please try again." << std::endl;
  }
}
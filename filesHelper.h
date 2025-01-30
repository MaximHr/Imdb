/**
* Solution to course project #6
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2024/2025
* 
* @author Maksim Hristov
* @idnumber 4MI0600466 @compiler GCC 
* 
* <files helper functions>
*/

#include <iostream>
#pragma once

bool fileExists(const char* filename);
void addNewLineToFile(const char* filename, const char* content);
void readFromFile(const char* filename, void (*queryDatabase)(std::ifstream& file , char* line));
void editLineInFile(const char* filename, const char* lineToEdit, const char* newLine);
void deleteLineFromFile(const char* filename, const char* lineToDelete);
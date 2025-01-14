#include <iostream>
#pragma once

void addNewLineToFile(const char* filename, const char* content);
void readFromFile(const char* filename, void (*queryDatabase)(std::ifstream& file , char* line));
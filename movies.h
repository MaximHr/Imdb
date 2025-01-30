/**
* Solution to course project #6
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2024/2025
* 
* @author Maksim Hristov
* @idnumber 4MI0600466 @compiler GCC 
* 
* <definition of movie functions>
*/

#pragma once

void getLineByTitleAndRate(std::ifstream &file, char* line);
void getLineByTitleAndDelete(std::ifstream &file , char* line);
void getLineByTitleAndEdit(std::ifstream &file , char* line);
void addMovie();
void searchMovie();
void sortMovie();
void printFilteredMovies(std::ifstream &file , char* line);
void printAllMovies(std::ifstream &file , char* line);
void changeFiles();

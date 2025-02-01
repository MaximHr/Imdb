/**
* Solution to course project #6
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2024/2025
* 
* @author Maksim Hristov
* @idnumber 4MI0600466 @compiler GCC 
* 
* <constants used in the program>
*/

#pragma once

// movies
constexpr unsigned MAXIMUM_RATING = 10;

//files
constexpr char DATABASE[] = "database.txt";
constexpr char TEMP_FILE[] = "temp.txt";
constexpr char SEPARATING_CHAR = '|';
constexpr unsigned MAX_ROWS = 1000;
constexpr unsigned LINE_MAX_CHARACTERS = 1000;
//there are three string fields - title,genre,cast and a total of 10 chars for (rating and year)
constexpr unsigned INPUT_MAX_CHARS = LINE_MAX_CHARACTERS / 3 - 10;

//menu
constexpr unsigned MENU_MAX_CHARACTERS = 50; //max characters for each menu option
constexpr unsigned ADMIN_OPTIONS_LENGTH = 8;
constexpr unsigned USER_OPTIONS_LENGTH = 6;
constexpr char ADMIN_MENU_OPTIONS[ADMIN_OPTIONS_LENGTH][MENU_MAX_CHARACTERS] = {
  "Add a movie",
  "Search for a movie",
  "View all movies",
  "Edit a movie",
  "Delete a movie",
  "Filter movies by rating",
  "Sort movies",
  "Log out",
};
constexpr char USER_MENU_OPTIONS[USER_OPTIONS_LENGTH][MENU_MAX_CHARACTERS] = {
  "Search for a movie",
  "View all movies",
  "Sort movies",
  "Rate a movie",
  "Filter movies by rating",
  "Log out",
};

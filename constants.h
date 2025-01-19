#pragma once

// movies
constexpr unsigned MAXIMUM_RATING = 10;

//files
constexpr char DATABASE[] = "C:\\Users\\hrist\\OneDrive\\Documents\\Maxim programming 6\\imdb\\database.txt";
constexpr char SEPARATING_CHAR = '|';
constexpr unsigned LINE_MAX_CHARACTERS = 100;

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

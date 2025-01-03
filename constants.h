#pragma once

constexpr unsigned MENU_MAX_CHARACTERS = 50; //max characters for each menu option
constexpr unsigned ADMIN_OPTIONS_LENGTH = 7;
constexpr unsigned USER_OPTIONS_LENGTH = 6;
constexpr char ADMIN_MENU_OPTIONS[ADMIN_OPTIONS_LENGTH][MENU_MAX_CHARACTERS] = {
  "Add a movie",
  "Search for a movie",
  "Preview all movies",
  "Edit a movie",
  "Delete a movie",
  "Sort movies",
  "Log out",
};
constexpr char USER_MENU_OPTIONS[USER_OPTIONS_LENGTH][MENU_MAX_CHARACTERS] = {
  "Search for a movie",
  "Preview all movies",
  "Sort movies",
  "Rate a movie",
  "Filter movies by rating",
  "Log out",
};

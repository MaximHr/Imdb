#include <limits>
#include <iostream>
#include "helperFunctions.h"

void clearInputBuffer() {
	std::cin.clear();
	std::cin.sync();
	std::cin.ignore();	
}

char toLower(char letter) {
  if(letter >= 'A' && letter <= 'Z') {
    return letter + ('a' - 'A');
  }
  return letter;
}
bool isPrefix(const char* text, const char* expectedPrefix) {
	if(!text || !expectedPrefix) return false;

	while(*expectedPrefix) {
		if(*text != *expectedPrefix) {
			return false;
		}
		text++;
		expectedPrefix++;
	}

	return true;
}
bool isCaseSensitivePrefix(const char* text, const char* expectedPrefix) {
  if(!text || !expectedPrefix) return false;
  const short dif = 'a' - 'A';

  while(*expectedPrefix) {
    if(toLower(*text) != toLower(*expectedPrefix)) {
      return false;
    }
    text++;
    expectedPrefix++;
  }

  return true;
}

bool strContains(const char* str, const char* searchedText, bool caseSensitive) {
	if(!str || !searchedText) return false;

	while(*str) {
		if(caseSensitive && isPrefix(str, searchedText)) {
			return true;
		} else if(!caseSensitive && isCaseSensitivePrefix(str, searchedText)) {
      return true;
    }
		str++;
	}
	return false;
}

bool strContains(const char* str, char letter) {
  if(!str) return false;
  while (*str != '\0') {
    if(*str == letter) return true;
    ++str;
  }
  return false;
}

// char toChar(unsigned num) { return (num + '0'); }
int toNumber(char letter) { 
  if(isNumber(letter)) {
    return (letter - '0');
  } 
  return -1;
}
bool isNumber(char letter) { return (letter >= '0' && letter <= '9'); }

unsigned getNumber(const char* str) {
  if(!str) return 0;
  int result = 0;

  while(*str != '\0') {
    if(isNumber(*str)) {
      result *= 10;
      result += toNumber(*str);
    } else {
      return 0;
    }
    str++;
  }
  return result;
}
// unsigned numLength(unsigned short num) {
//   if(num == 0) return 1;

//   unsigned result = 0;
//   while(num > 0) {
//     num /= 10;
//     result++;
//   }
//   return result;
// }
unsigned strLength(const char* str) {
  if(!str) return 0;

  unsigned length = 0;
  while(str[length] != '\0') {
    length++;
  }
  return length; 
}
void copyStr(char* dest, const char* src) {
  if(!src || !dest) return;
  while(*src != '\0') {
    *dest = *src;
    dest++;
    src++;
  }
  *dest = '\0';
}

//case insensitive
bool areEqualStr(const char* str1, const char* str2) {
  if(!str1 || !str2) return 0;
  
  while(*str1 != '\0' && *str2 != '\0') {
    if(toLower(*str1) != toLower(*str2)) return false;
    str1++;
    str2++;
  }
  return (*str1 == '\0' && *str2 == '\0');
}
char* strConcat(char* dest, const char* src) {
  if(!dest || !src) return dest;

  char* destEnd = dest;
  while(*destEnd != '\0') {
    destEnd++;
  }
  while (*src != '\0') {
    *destEnd = *src;
    destEnd++;
    src++;
  }
  *destEnd = '\0';
  
  return dest;
}

char* strConcat(char* dest, char src) {
  if(!dest) return dest; 

  char* destEnd = dest;
  while (*destEnd != '\0') {
    destEnd++;
  }
  *destEnd = src;
  destEnd++;
  *destEnd = '\0';

  return dest;
}
int choseOption(const char* arr) {
  if(!arr) return -1;
  char userInput[2]; //If it is a single char (not an array of 1 char) it will cause bugs.
  do {
    std::cout << "Enter the number in front of the option you want" << std::endl;
    std::cin >> userInput;
     if(std::cin.fail()) {
        std::cin.clear();
        std::cout << "Invalid input. Please try again." << std::endl;
        continue;
    }
  } while(!strContains(arr, userInput[0]) || strLength(userInput) > 1); 
  int number = toNumber(userInput[0]);

  return number;
}
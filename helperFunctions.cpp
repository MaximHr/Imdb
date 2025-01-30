#include <limits>
#include <iostream>
#include "helperFunctions.h"

float roundNumber(float num){
  return (int)(num * 100 + 0.5) / 100.0;
}
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

int toNumber(char letter) { 
  if(isNumber(letter)) {
    return (letter - '0');
  } 
  return -1;
}
bool isNumber(char letter) { return (letter >= '0' && letter <= '9'); }

int pow(int base, int power) {
  int result = base;  
  for(int i = 1; i < power; i++) {
    result *= base;
  }
  return result;
}
const char* floatToString(float num) {
  char* result = new char[5]; //max 3 digits + '.' + '\0'
  int intPart = (int)num;
  int decimalPart = (int)((num - intPart) * 100);
  result[0] = intPart + '0';
  result[1] = '.';
  result[2] = decimalPart / 10 + '0';
  result[3] = decimalPart % 10 + '0';  

  return result;
}


float getFloatNumber(const char* str) {
  if(!str) return -1;
  float result = 0;
  unsigned short dotPos = 0, i = 0;

  while(*str != '\0') {
    if(isNumber(*str)) {
      result *= 10;
      result += toNumber(*str);
    } else if(*str == '.' && dotPos == 0) {
      dotPos = i;
    } else {
      return -1;
    }
    i++;
    str++;
  }
  if(dotPos != 0) {
    result /= pow(10, i - dotPos - 1);
  }
  return result;
}

bool isBetween(float num, float min, float max) {
  const float epsilon = 0.000001;
  bool isBigger = (num + epsilon >= min);
  bool isSmaller = (num - epsilon <= max);

  return (isBigger && isSmaller);
}

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
int chooseOption(const char* arr) {
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
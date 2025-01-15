#include <iostream>
#include "helperFunctions.h"

void clearInputBuffer() {
	std::cin.clear();
	std::cin.sync();
	std::cin.ignore();	
}

bool strContains(char* str, char letter) {
  if (str == nullptr) return false;
  while (*str != '\0') {
    if(*str == letter) return true;
    ++str;
  }
  return false;
}

// char toChar(unsigned num) { return (num + '0'); }
unsigned toNumber(char letter) { return (letter - '0'); }
bool isNumber(char letter) { return (letter >= '0' && letter <= '9'); }

unsigned getNumber(const char* str) {
  if(str == nullptr) return 0;
  unsigned result = 0;

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
  if(str == nullptr) return 0;

  unsigned length = 0;
  while(str[length] != '\0') {
    length++;
  }
  return length; 
}
void copyStr(char* dest, const char* src) {
  if(src == nullptr || dest == nullptr) return;
  while(*src != '\0') {
    *dest = *src;
    dest++;
    src++;
  }
  *dest = '\0';
}

bool areEqualStr(const char* str1, const char* str2) {
  if(str1 == nullptr || str2 == nullptr) return 0;
  
  while(*str1 != '\0' && *str2 != '\0') {
    if(*str1 != *str2) return false;
    str1++;
    str2++;
  }
  return (*str1 == '\0' && *str2 == '\0');
}
char* strConcat(char* dest, const char* src) {
  if(dest == nullptr || src == nullptr) return dest;

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
  if(dest == nullptr) return dest; 

  char* destEnd = dest;
  while (*destEnd != '\0') {
    destEnd++;
  }
  *destEnd = src;
  destEnd++;
  *destEnd = '\0';

  return dest;
}
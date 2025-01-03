#include "stringFunctions.h"

void copyStr(char* dest, const char* src) {
  if (src == nullptr || dest == nullptr) return;
  while (*src != '\0') {
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

#pragma once


float getFloatNumber(const char* str);
bool isBetween(float num, float min, float max);
int toNumber(char letter);
char* strConcat(char* dest, char src);
char* strConcat(char* dest, const char* src);
bool strContains(const char* str, char letter);
bool strContains(const char* str, const char* searchedText, bool caseSensitive);
unsigned getNumber(const char* str);
bool isNumber(char letter);
int chooseOption(const char* arr);
void clearInputBuffer();
unsigned strLength(const char* str);
void copyStr(char* dest, const char* src);
bool areEqualStr(const char* str1, const char* str2);
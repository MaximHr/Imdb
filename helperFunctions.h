#pragma once

int choseOption(const char* arr);
int toNumber(char letter);
char* strConcat(char* dest, char src);
char* strConcat(char* dest, const char* src);
bool strContains(const char* str, char letter);
bool strContains(const char* str, const char* searchedText, bool caseSensitive);
unsigned getNumber(const char* str);
bool isNumber(char letter);
void clearInputBuffer();
unsigned strLength(const char* str);
void copyStr(char* dest, const char* src);
bool areEqualStr(const char* str1, const char* str2);
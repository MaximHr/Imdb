#pragma once

char* strConcat(char* dest, char src);
char* strConcat(char* dest, const char* src);
bool strContains(char* str, char letter);
unsigned getNumber(const char* str);
bool isNumber(char letter);
void clearInputBuffer();
unsigned strLength(const char* str);
void copyStr(char* dest, const char* src);
bool areEqualStr(const char* str1, const char* str2);
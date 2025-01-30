/**
* Solution to course project #6
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2024/2025
* 
* @author Maksim Hristov
* @idnumber 4MI0600466 @compiler GCC 
* 
* <helper functions>
*/

#pragma once

int strCompare(const char* str1, const char* str2);
const char* floatToString(float num);
float roundNumber(float num);
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
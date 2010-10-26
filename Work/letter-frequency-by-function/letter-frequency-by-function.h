//
//  Header file for my square pyramid program
//  that calculates surface area and volume
//
#pragma once
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

int main();
void countLetters(const string& text, const char firstLetter, const char lastLetter, int LetterCounts[]);
int findMost(const int LetterCounts, const int range);
int findNextMost(const int LetterCounts, const int range);
int findLeast(const int LetterCounts, const int range);
int findNextLeast(const int LetterCounts, const int range);

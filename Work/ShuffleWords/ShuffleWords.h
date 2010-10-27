//
//  Program that shuffles words
//
#pragma once
#include <cstdlib>
#include <iostream>
using namespace std;

int readSeed();
int readWords(string words[], const int SIZE);
void shuffleWords(string words[], const int counter);
int main();

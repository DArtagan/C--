//
//  Header file for a program that simulates a student's schedule
//
#pragma once
#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

int main();

int readSeed();
void blocking( int schedule[], const int hours, const int buildings, const int lectures );
void shuffler( int schedule[], const int hours );

//
//  Header file for a program that finds the threshold values for data
//  and outputs those data values to a file classified by their threshold point
//
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main();

istream& readData( istream& inputf, int array[], int& size, int MAX );
int findMax( const int data[], const int size );
void threshold( int data[], const int size, double high, double low );
ostream& outputData( ostream& outputf, const int array[], const int size );

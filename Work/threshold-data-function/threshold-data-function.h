//
//
//
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main();

istream& readData( istream& inputf, int array[], int& size );
int findMax( const int data[], const int size );
void threshold( int data[], const int size, double high, double low );
ostream& outputData( ostream& outputf, const int array[], const int size );

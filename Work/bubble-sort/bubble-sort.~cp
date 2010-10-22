//
//  Program to find the surface area and volume
//  of a user defined square bottomed pyramid
//
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void bubblesort( int array[], int count );

int main() {
    /*  Variables */
    const int SIZE(50000);
    int data[SIZE] = {};
    int counter(0);

	/*  Header  */
	cout << "-- Bubble Sort --" << endl << endl;
    
	/*  Open file for reading, check for validity  */
    ifstream inFile( "UNSORTED.DAT" );
    if( !inFile ) {
        cout << "Error opening file." << endl << endl << endl;
        system("PAUSE");
        exit(1);
    }
    ofstream outFile( "SORTED.DAT" );
    if( !outFile ) {
        cout << "Error opening file." << endl;
        system("PAUSE");
        exit(1);
    }
    
    /*  Store Data  */
    for( ; counter < SIZE; counter++) {
        if(!( inFile >> data[counter] )) break;
    }
    
   	/*  Close Read File  */
    inFile.close();
    
    /*  Call Bubble Sort  */
    bubblesort( data, counter );
    
    /*  Write to Sorted File  */
    for(int i(0); i < counter; i++){
        outFile << data[i] << endl;
    }
    
    /*  Close Write File  */
    outFile.close(); 

	/*  Concluding Text, Print the Volume  */
    for(int i(0); i < counter; i++){
        cout << data[i] << " , ";
    }
    cout << endl << endl << endl << endl;
	
    system("PAUSE");
    //  Exit program
}

void bubblesort( int data[], const int counter ){
    /*  Variables  */
    int trans;
    int x;
    
    x = counter;
    
    for(int i(0); i < counter; i++) {
        for(int j(1); j < x; j++) {
            if(data[j] < data[j - 1]) {
                trans = data[j];
                data[j] = data[j - 1];
                data[j - 1] = trans;
            }
        }
        x--;
    }
    
    return;
}

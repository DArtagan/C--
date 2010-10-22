//
//  Program to sort data
//
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*  Prototypes  */
void bubblesort( int array[], int count );

/*  Main function, handles input and output  */
int main() {
    /*  Variables */
    const int SIZE(50000);
    int data[SIZE] = {};
    int counter(0);

	/*  Header  */
	cout << "-- Bubble Sort --" << endl << endl;
	cout << "This program sorts data located in the file 'UNSORTED.DAT'." << endl << endl;
    
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

	/*  Footer  */
    cout << endl << "Sorting complete." << endl << "Sorted data stored in the file 'SORTED.DAT'." << endl << endl << endl;
	
    system("PAUSE");
    //  Exit program
}

/*  bubblesort function, sorts data in numrical order  */
void bubblesort( int data[], const int counter ){
    /*  Variables  */
    int trans;
    int x;
    
    /*  Sub-Counter  */
    x = counter;
    
    /*  Bubble Search  */
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

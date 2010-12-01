//
//  Main routine for a program that tests the Triangle class
//
#include <cstdlib>
#include <iostream>
#include <fstream>

#include "Triangle.h"

using namespace std;

void bubblesort( Triangle array[], const int counter );

int main()
{
    /*  Constants  */
    
    /*  Variables  */
    Triangle testTriangle;
    int counter(0);
    
    /*  Header  */
    cout << " -- Allocated Triangles Assignment --" << endl << endl << endl;
    
    /*  Open file for reading, check for validity  */
    ifstream inFile( "TRIANGLES.dat" );
    if( !inFile ) {
        cout << "Error opening file." << endl;
        system("PAUSE");
        exit(1);
    }	
    
    /*  Write the names of the equilateral triangles and count the non-equilateral ones  */
    while( inFile >> testTriangle ) {
        if( testTriangle.isEquilateral() ) {
            cout << testTriangle.getName() << endl;
        } else {
            counter++;
        }
    }
    
    /*  Close Read File  */
    inFile.close();
    
    /*  Check that the number of non-equilateral triangles is odd  */
    if( counter % 2 ) {
        cout << "Congratulations, the number of non-equilateral triangles is odd (" << counter << ")." << endl;
    } else {
        cout << "Fail, The number of non-equilateral triangles is even (" << counter << ")." << endl;
    }
    
    /*  Make an array of triangles for the non-equilateral triangles  */
    Triangle* const NonEquilateralTriangles = new(nothrow) Triangle[counter];
    if( NonEquilateralTriangles == NULL ) {
        cout << "Unable to get memory, sorry.";
        delete NonEquilateralTriangles;
        exit(1);
    }
    
    /*  Store the non-equilateral trinagles into that newly allocated array   */
    ifstream sourceTriangles( "TRIANGLES.dat" );
    if( !sourceTriangles ) {
        cout << "Error opening file." << endl;
        system("PAUSE");
        exit(1);
    }	
    
    /*  Store Triangles  */
    int i(0);
    while( sourceTriangles >> testTriangle ) {
        if( !(testTriangle.isEquilateral()) ) {
            NonEquilateralTriangles[i] = testTriangle;
            i++;
        }
    }

    /*  Sort the non-equilateral triangles  */
    bubblesort( NonEquilateralTriangles, counter );
    cout << NonEquilateralTriangles[0].getName() << " "\
    << NonEquilateralTriangles[counter / 2].getName() << " "\
    << NonEquilateralTriangles[counter - 1].getName()\
    << endl;
    
    /*  Close Read File  */
    sourceTriangles.close();
    
    /*  Deallocate NonEquilateralTriangle memory  */
    delete[] NonEquilateralTriangles;
    
    /*  Footer  */
    cout << endl << endl;
    
    system("PAUSE");
    return 0;
}

/*  bubblesort function, sorts triangles by perimeter order  */
void bubblesort( Triangle data[], const int counter ){
    /*  Variables  */
    Triangle trans;
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

//
//  Test program
//
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int test( ) 
{
	int thisNumber(100);
	thisNumber = thisNumber * .85;
	return thisNumber;
}
	

int main()
{
    /*  Header  */
    cout << " -- Driver Application for the Triangle class --" << endl << endl << endl;
    
	int spent(0);
	int random;
	int theBool;
	
	/*for( int i(0); i < 10; i++) {
		random = rand() % 10;
		theBool = bool( random );
		spent += random * 100;
		cout << random << ", " << theBool << ", " << spent << endl;
	}*/
	
	for( int i(0); i < 10; i++ ) {
		cout << test( ) << endl;
	}
    
    /*  Footer  */
    cout << endl << endl << endl;
    
    system("PAUSE");
    return 0;
}


//
//  Program to find a particular word
//
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    /*  Declare/Identify Variables  */
	const int SIZE(50000);
	string haystack[SIZE] = {};
	int counter(0);
	string needle;
	int left;
	int right;
	int middle;
    
	/*  Open file for reading, check for validity  */
    ifstream inFile( "SORTED.DAT" );
    if( !inFile ) {
        cout << "Error opening file." << endl;
        system("PAUSE");
        exit(1);
    }	
	
	/*  Ask for user chosen word  */
    cout << "-- Binary Search --" << endl << endl;
	cout << "What word would you like to find?" << endl;
	cin >> needle;
    cout << endl;

	/*  Store data into haystack  */
	for(int i(0); i < 50000; i++) {
		inFile >> haystack[i];
		if (haystack[i] == "") break;
		counter++;
	}
	
	/*  Find left and right values  */
	left = 0;
	right = counter - 1;
	
	/*  Search  */
	while( left <= right) {
		middle = (left + right) / 2;
		if(needle < haystack[middle]) {
			right = middle - 1;
		} else if(needle == haystack[middle]) {
			left = middle;
			right = middle;
			break;
		} else {
			left = middle + 1;
		}
	}
	
	/*  Which side is valid?  */
	if(left < counter && right > -1) {
		if(left == right) {
			cout << "The needle, " << haystack[left] << ", is at point " << left << "." << endl;
		} else {
			cout << "The needle is between " << haystack[right] << " and " << haystack[left] << "." << endl;
		}
	} else {
		if(!(left < counter)) {
			cout << "The needle is too big." << endl;
		} else {
			cout << "The needle is too small." << endl;
		}
	}
	
	/*  Concluding Text  */
    cout << endl << endl;
    /*  for(int i(0); i < counter; i++) {
		cout << haystack[i] << endl;
	} */
	cout << left << " , " << right << endl;
	cout << needle << endl;
	cout << haystack[left] << " , " << haystack[right];
    cout << endl << endl << endl << endl;    
    
	/*  Close Write File  */
    inFile.close();

	system("PAUSE");
    //  Exit Program
    return 0;
}

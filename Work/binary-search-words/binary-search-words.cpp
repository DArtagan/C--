//
//  Program to find a particular word using binary search
//
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    /*  Declare/Identify Variables  */
	// Constants
	const int SIZE(50000);
	// Variables
	int counter(0), left, right, middle;
	string needle;
	// Array
	string haystack[SIZE] = {};
    
	/*  Open file for reading, check for validity  */
    ifstream inFile( "SORTED.DAT" );
    if( !inFile ) {
        cout << "Error opening file." << endl;
        system("PAUSE");
        exit(1);
    }	
	
	/*  Header and prompt the user for a chosen word  */
    cout << "-- Binary Search --" << endl << endl;
	cout << "What word would you like to find?" << endl;
	cin >> needle;
    cout << endl << endl;

	/*  Store data into haystack  */
	for(int i(0); i < 50000; i++) {
		inFile >> haystack[i];
		if (haystack[i] == "") break;
		counter++;
	}
	
	/*  Close read File  */
    inFile.close();
	
	/*  Find left and right values  */
	left = 0;
	right = counter - 1;
	
	/*  Search  */
	while( left <= right) { // The program keeps going until the left index <=  the right index
		middle = (left + right) / 2; // Find the middle using an average, because it is an int type, it will truncate
		if(needle < haystack[middle]) {
			right = middle - 1; // Shrink the search to just the left half
		} else if(needle == haystack[middle]) {
			left = middle; // Make left and right equal the found value, so the the loop will break
			right = middle;
			break;
		} else {
			left = middle + 1; // Shrink the search to just the right half
		}
	}
	
	/*  Which side is valid?  */
	if(left < counter && right > -1) {
		if(left == right) { // When the left equals the right, the word is found.
			cout << "The word, " << haystack[left] << ", is at index " << left << " in the data set." << endl;
		} else { // If the left and right sides have crossed, the word is between those two
			cout << "The word is between " << haystack[right] << " (" << right << ") and " << haystack[left] << " (" << right << ") in the data set." << endl;
		}
	} else {
		if(!(left < counter)) { // If the left bound has gone beyond the data set's upper bound, the word is too large
			cout << "The word is beyond the upper bound of the data set (too large)." << endl;
		} else { // If the right bound has gone below the data set's lower bound, the word is too small
			cout << "The word is below the lower bound of the data set (too small)." << endl;
		}
	}
	
	/*  Footer  */
    cout << endl << endl;    

	system("PAUSE");
    //  Exit Program
    return 0;
}

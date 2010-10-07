//
//  Program to rearrange someone's full name
//
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    /*  Declare/Identify Variables  */
    string name = "", first = "", middle = "", last = "", numeral = "";
	int spacecounter(0), lettercounter(0), cursor(0);

	/*  Header and ask for name  */
    cout << "-- Name Printer --" << endl << endl;
    cout << "What is your name:" << endl;
    getline(cin,name,'\n');
    cout << endl;

	/*  Analyze Name  */
	//  First Name
	for(int i=0; i < int(name.length()); i++) {
		if(name[i] == ' ' && lettercounter == 0) {
			spacecounter++;
		} else if(name[i] != ' ') {
			first += name[i];
			lettercounter++;
		} else if(name[i] == ' '&& lettercounter > 0) {
			cursor = lettercounter + spacecounter;
			spacecounter = 0;
			lettercounter = 0;
			break;
		}
	}
	//  Middle Name
	for(int i=cursor; i < int(name.length()); i++) {
		if(name[i] == ' ' && lettercounter == 0) {
			spacecounter++;
		} else if(name[i] != ' ' && name[i] != '.') {
			middle += name[i];
			lettercounter++;
		} else if(name[i] == '.') {
			lettercounter++;
		} else if((name[i] == ' ') && lettercounter > 0) {
			cursor += lettercounter + spacecounter;
			spacecounter = 0;
			lettercounter = 0;
			break;
		}
	}
	//  Last Name
	for(int i=cursor; i < int(name.length()); i++) {
		if(name[i] == ' ' && lettercounter == 0) {
			spacecounter++;
		} else if(name[i] != ' ' && name[i] != '.') {
			last += name[i];
			lettercounter++;
		} else if(name[i] == '.') {
			lettercounter++;
		} else if((name[i] == ' ') && lettercounter > 0) {
			cursor += lettercounter + spacecounter;
			spacecounter = 0;
			lettercounter = 0;
			break;
		}
	}
	//  Numeral
	for(int i=cursor; i < int(name.length()); i++) {
		if(name[i] != ' ' && (name[i] == 'I' || name[i] == 'V' || name[i] == 'X' || name[i] == 'C' || name[i] == 'L')) {
			numeral += name[i];
			lettercounter++;
		}
	}
	//  Check that middle != last
	if(last == "") {
		last = middle;
		middle = "";
	}
	
	
	/*  Concluding Text  */
    cout << endl << endl;
	cout << last << ", " << first << " ";
	// Print only if middle exists
	if(middle != "") {
		cout << middle[0] << ". ";
	}
	// Print only if numeral truly exists
	if(numeral != last) {
		cout << numeral;
	}
    cout << endl << endl << endl << endl;    

	system("PAUSE");
    //  Exit Program
    return 0;
}

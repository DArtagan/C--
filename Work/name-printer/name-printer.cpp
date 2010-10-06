//
//  Program to
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
	for(int i=cursor; i < int(name.length()); i++) {
		if(name[i] != ' ' && (name[i] == 'I' || name[i] == 'V' || name[i] == 'X' || name[i] == 'C' || name[i] == 'L')) {
			numeral += name[i];
			lettercounter++;
		}
	}
	if(last == numeral) {
		numeral = "";
	}
	if(last == middle) {
		middle = "";
	}
	
	
	/*  Concluding Text  */
    cout << endl << endl;
	cout << last << ", " << first << " ";
	if(middle != "") {
		cout << middle[0] << ". ";
	}
	cout << numeral;
    cout << endl << endl << endl << endl;    

	system("PAUSE");
    //  Exit Program
    return 0;
}

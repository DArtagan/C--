#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

#include "RowNColumn.h"
#include "ThreeByThree.h"
#include "checker.h"


using namespace std;

int main()
{
    /* Initialize variables  */
    const int puzzlesize(9);
    int solvedpuzzle[puzzlesize][puzzlesize]={};
    string coordinates[puzzlesize][puzzlesize];
    int prompt;
    string temp("");
    bool dobreak = false;
    char ask;
   
    /*  Set up the coordinates array  */   
    for(int i =0;i<puzzlesize;i++) {
       for(int j=0; j<puzzlesize;j++) {
           temp+=(char('a'+j));
           temp+=char('1'+i);
           coordinates[i][j] += temp;
           temp.clear();
       }
    }
    
    /*  Ask if the user has a file to import  */
    importHeader();
	table(solvedpuzzle);
	cout << endl << "Would you like to import a file?";
	cout<< "    Y = yes     N = no      "<<endl;
    cin >> ask;
	if((ask=='y') || (ask=='Y')) {
        /*  Import puzzle from file  */
        // User specifies file
        ifstream inFile;
        string filename;
        cout << "Enter savefile name: " << flush;
        cin >> filename;
    
        // Open file and check that it opens
        inFile.open( filename.c_str() );
        if (!inFile) {
            cout << "Error opening file."<< endl;
            system ("PAUSE");
            exit (1); 
        }
    
        // Read from file
        for(int i(0); i < RowNColumn::LIMIT; i++) {
            for(int j(0); j < RowNColumn::LIMIT; j++) {
                inFile >> solvedpuzzle[i][j];
            }
        }
    
        // Close file
        inFile.close();
		
		// Display puzzle
		importHeader();
		table(solvedpuzzle);
        system("PAUSE");
    } else {
		/*  Prompt User for their solved puzzle  */
		dobreak = false;
		for(int i=0; i<puzzlesize && !dobreak; i++) {
			for(int j=0; j<puzzlesize; j++) {
				solvedHeader();
				table(solvedpuzzle);
				cout<<"Please enter "<<coordinates[i][j]<<": "<<flush;
				//  Proofreading the input
				cin>>prompt;
				while(((prompt<1) || (prompt>11)))
				{
				   cout<<"Please enter "<<coordinates[i][j]<<": "<<flush;
				   cin>>prompt;
				}
				if( prompt == 10 ) {
					readSeed();
					for( int k(0); k < puzzlesize; k++ ) {
						for( int l(0); l < puzzlesize; l++ ) {
							solvedpuzzle[k][l] = rand() % puzzlesize + 1;
						}
					}
					solvedHeader();
					table(solvedpuzzle);
					dobreak = true;
					break;
				} else if( prompt == 11 ) {
					int counter(0);
					for( int k(0); k < puzzlesize; k++ ) {
						counter += 3;
						for( int l(0); l < puzzlesize; l++ ) {
							if( counter % 39 == 0 ) counter = 2;
							if( counter % 38 == 0 ) counter = 1;
							counter++;
							solvedpuzzle[k][l] = counter % 9 + 1;
						}
					}
					solvedHeader();
					table(solvedpuzzle);
					dobreak = true;
					break;
				} else {
					solvedpuzzle[i][j]=prompt;
				}
				system("PAUSE");
				system("CLS");
		   }       
		}
		cout << endl;
		
		 /*  Store the puzzle to a file  */
		// User specifies file
		ofstream outFile;
		string filename;
		cout << "Enter savefile name: " << flush;
		cin >> filename;
		cout << endl;
		
		// Open file and check that it opens
		outFile.open( filename.c_str() );
		if (!outFile) {
			cout << "Error opening file."<< endl;
			system ("PAUSE");
			exit (1); 
		}
			
		// Write to file
        for(int i(0); i < RowNColumn::LIMIT; i++) {
            for(int j(0); j < RowNColumn::LIMIT; j++) {
                outFile << solvedpuzzle[i][j] << " ";
            }
        }
        
        // Close file
        outFile.close();
    }

/*  Transfer the entered values into proper classes to analyze  */
	/*  Initialize classes  */
	RowNColumn r1, r2, r3, r4, r5, r6, r7, r8, r9;
	RowNColumn c1, c2, c3, c4, c5, c6, c7, c8, c9;
	ThreeByThree t1, t2, t3, t4, t5, t6, t7, t8, t9;

	/*  Populate the row class  */
	populate(r1, solvedpuzzle, 0, 10);
	populate(r2, solvedpuzzle, 1, 10);
	populate(r3, solvedpuzzle, 2, 10);
	populate(r4, solvedpuzzle, 3, 10);
	populate(r5, solvedpuzzle, 4, 10);
	populate(r6, solvedpuzzle, 5, 10);
	populate(r7, solvedpuzzle, 6, 10);
	populate(r8, solvedpuzzle, 7, 10);
	populate(r9, solvedpuzzle, 8, 10);

	/*  Populate the Column classes  */
	populate(c1, solvedpuzzle, 0, 0);
	populate(c2, solvedpuzzle, 0, 1);
	populate(c3, solvedpuzzle, 0, 2);
	populate(c4, solvedpuzzle, 0, 3);
	populate(c5, solvedpuzzle, 0, 4);
	populate(c6, solvedpuzzle, 0, 5);
	populate(c7, solvedpuzzle, 0, 6);
	populate(c8, solvedpuzzle, 0, 7);
	populate(c9, solvedpuzzle, 0, 8);

	/*  Populate the 3x3 classes  */
	populate(t1, solvedpuzzle, 0, 0);
	populate(t2, solvedpuzzle, 3, 0);
	populate(t3, solvedpuzzle, 6, 0);
	populate(t4, solvedpuzzle, 0, 3);
	populate(t5, solvedpuzzle, 2, 3);
	populate(t6, solvedpuzzle, 6, 3);
	populate(t7, solvedpuzzle, 0, 6);
	populate(t8, solvedpuzzle, 3, 6);
	populate(t9, solvedpuzzle, 6, 6);

	/*  Test variables  */
	bool rowstest;
	bool columnstest;
	bool squarestest;

	/*  Test if Sudoku entered is correct  */
	if(r1.test() && r2.test() && r3.test() && r4.test() && r5.test() && r6.test() && r7.test() && r8.test() && r9.test()) {
		cout << " Rows GOOD!!" << endl;
		rowstest = true;
	} else {
        cout<<"Repeats in row(s)." << endl;
		rowstest = false;
	}
	if(c1.test() && c2.test() && c3.test() && c4.test() && c5.test() && c6.test() && c7.test() && c8.test() && c9.test()) {
		cout << " Columns GOOD!!" << endl;
        columnstest = true;
	} else {
        cout<<"Repeats in column(s)." << endl;
		columnstest = false;
	}
	if(t1.test() && t2.test() && t3.test() && t4.test() && t5.test() && t6.test() && t7.test() && t8.test() && t9.test()) {
        cout << " 3x3s GOOD!!" << endl;
		squarestest = true;
	} else {
        cout<<"Repeats in 3x3 grid(s)." << endl;
		squarestest = false;
	}
    cout << endl;
    
	/*  Final Result  */
	if(rowstest && columnstest && squarestest) {
		cout << "Congratulations! You have solved the puzzle!" << endl;
		//  Maybe retrieve their solution from file here
	} else {
		cout<<"You DEFINETLY have an error in your solution!"<<endl;
		//  Maybe this is where you could use my intermediate variables to narrow it down to where it is
	}
	
	//  For Grader beyond this point
	//  Read final.txt
	string read;
	
	/*  Ask if they would like to read the final document  */
	cout<<"Would you like to read final.txt?"<<endl;
	cout<<"    Y = yes     N = no      "<<endl<<endl;
	cin>>ask;
	
	if((ask=='y') || (ask=='Y')) {
    
    /*  Final Document Pager  */
    ifstream finalFile ( "final.txt");
    if (!finalFile) {
        cout << "Error opening final.txt file."<< endl;
        system ("PAUSE");
        exit (1); 
    }

    // clear console
	const int MAXLINES=12;
    system( "cls" );
	int lines = 0;
	string read;
	cout << "*** This document (final.txt) is best read outside of the console ***" << endl << endl;
	while( getline( finalFile, read, /*char('*')*/ '\n' ) ) {
		// show pages
		cout.width(5);
		++lines;
		cout << read << endl;
		
		if( lines % MAXLINES == 0 ) {
			cout << endl << endl << "c = continue, q = quit... " << flush;
			char cmd;
			cin >> cmd;
			if( cmd == 'q' ) break;  // exit
			// clear console
			system( "cls" );
		}
	}

	// close file
	finalFile.close();
        
    } else {
        exit(1);
    }
    cout << endl << endl;
    
    
	system("PAUSE");
	return 0;
}


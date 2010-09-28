//
//  Program to return the percents for different error situations in suture packaging
//
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    /*  Declare/Identify Variables  */
    int batch;
    double temperature;
    double pressure;
    double dwell_time;
    int tempcounter (0);
    int pressurecounter (0);
    int dwellcounter (0);
    double counter (0);
    double good (0);
    const int precision (3);
    const int width (30);
    
	/*  Open file for reading, check for validity  */
    ifstream inFile( "suture.dat" );
    if( !inFile ) {
        cout << "Error opening file." << endl;
        system("PAUSE");
        exit(1);
    }	
	
	/*  Ask for final value  */
    cout << "-- Suture Packaging Error Breakdown --" << endl << endl;
    cout << endl;
    
    /*  Count error data for each catergory and as a total  */
    while(inFile >> batch >> temperature >> pressure >> dwell_time) {
        if(150 > temperature || 170 < temperature) {
            tempcounter++;
        }
        if(pressure < 60 || pressure > 70) {
            pressurecounter++;
        }
        if(dwell_time < 2 || dwell_time > 2.5) {
            dwellcounter++;
        }
        if ((150 <= temperature && 170 >= temperature) && (pressure >= 60 && pressure <= 70) && (dwell_time >= 2 && dwell_time <= 2.5)) {
            good++;
        }
        counter++;
    }
    
    counter = counter - good;
    
    /*  Calculate Percents  */
    temperature = (tempcounter / counter * 100);
    pressure = (pressurecounter / counter * 100);
    dwell_time = (dwellcounter / counter * 100);

	/*  Concluding Text  */
    cout.width(width);
    cout.setf( ios::fixed ); 
    cout.setf( ios::right );
    cout.precision(precision);
    cout << endl << endl;
    cout << "Temperature rejection rate: " << temperature << "%" << endl;
    cout.width(width);
    cout.setf( ios::fixed ); 
    cout.setf( ios::right );
    cout.precision(precision);
    cout << "Pressure rejection rate: " << pressure << "%" << endl;
    cout.width(width);
    cout.setf( ios::fixed ); 
    cout.setf( ios::right );
    cout.precision(precision);
    cout << "Dwell time rejection rate: " << dwell_time << "%" << endl;
    cout << endl << endl << endl << endl;
    
	/*  Close Write File  */
    inFile.close();

    system("PAUSE");
    //  Exit Program
    return 0;
}

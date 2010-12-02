//
//  Main routine for program that simulates the spread of flu on campus
//
#include <cstdlib>
#include <iostream>

#include "Student.h"

using namespace std;

void readSeed();
double simulator();

int main() {
    /*  Constants  */
    const int N(200);
    const int totalCost(10000);
    const int closeSchoolCost(4500);
    const int vaccineCost(75);
    const int filterCost(5500);

    /*  Variables  */
    double average_infected(0);
    int filterBuilding(Student::BUILDINGS + Student::COMMONS);
    int money(0);
    int locationOffset(0);
    
    /*  Header  */
    cout << endl << endl << " -- Flu on Campus Simulator --" << endl;
    
    /*  Simulator  */
    readSeed();  // Sets the seed for rand()
    // air purifier
    for( ; locationOffset < Student::BUILDINGS + Student::COMMONS - 1; l++ ) {
    // We need to start with each location, but then we need to try each of the locations with that location and then so on
        //if( locationOffset == 6 ) locationOffset++;
        money(0);
        for( int f(0); f < Student::BUILDINGS + Student::COMMONS - 1; f++ ) {
            money += filterCost * f;
            for( int s(0); money + vaccineCost <= totalCost; s++ );
                if( Student[s].vaccinate( ) ) money += vaccineCost;
            }
            for( int i(0); i < N; i++) {
                cout << "Running simulation " << i << "...\n";
                average_infected += simulator( locationOffset );
            }
        }
    }
    
    /*  Results  */
    average_infected = average_infected / N;
    cout << endl << endl << "There was an average infection rate of the campus of " << average_infected << "%" << endl << endl << endl;
    system("PAUSE");
    return 0;
}

double simulator( const int& locationOffset )
{
    /*  Constants  */
    const int STUDENTS(3000); // Students on campus
    const int WEEKS_IN_SEMESTER(16 );  // Weeks in a semester
    const int DAYS_IN_WEEK(7);  // Days in a week
    const int HOURS_IN_DAYS(24);
    const int WEEKEND(5);
    const int INITIALLY_VACCINATED(300);
    
    /*  Variables  */
    Student students[STUDENTS];  //Array size, one Student for each STUDENT
    int UncleanPeople(0);  // Counter of people infected
    
    /*  Body  */
    students[0].setStatus( Student::INFECTIOUS );  // The simulation must start with one infected student for the flu to spread
    for(int i(1); i <= INITIALLY_VACCINATED; i++) {
        students[i].setStatus( Student::VACCINATED );
    }
    
	for( int d(0); d < WEEKS_IN_SEMESTER * DAYS_IN_WEEK; d++ ) {  // Loop for each day in a semester
		for( int h(0); h < HOURS_IN_DAYS; h++ ) {  // Loop for each hour in a day
    		//cout << h << endl;
			if( h>=Student::HOURS || d%DAYS_IN_WEEK >= WEEKEND ) {
                // after campus day or on the weekend
                for( int i=0; i<STUDENTS; i++ ) {
                    students[i].nextHour();
                }
			} else {
				// forward one hour
				for( int i(0); i < STUDENTS; i++ ) {	// Loop for each student during that hour
					students[i].updateLocation( d%Student::DAYS, h );
					students[i].nextHour();  // Move things forward one hour
				}
				// count locations
				int locationCounts[Student::BUILDINGS + Student::COMMONS] = {};  // Initiate an array of locations to zero
				for( int i(0); i < STUDENTS; i++ ) {  // Loop for each student
					if( students[i].isInfectious() ) {  // Loop for each student during that hour
						locationCounts[students[i].getLocation()]++;  // Add one to each location when a student in that location is infectious
					}
				}
				// catchFlu logic
				for( int i(0); i < STUDENTS; i++ ) {  // Loop for each student
					if( students[i].catchFlu( locationCounts, locationOffset ) ) {  // Run catch flu, has the location counts as a parameter
						//students[i].output( cout );  // If someone caught the flu, cout
						UncleanPeople++;  // Add one to the counter of people infected
						//cout << UncleanPeople;
					}
				}
        	}
		}
	}
    
    // Cout the percentage of people infected (People Infected / ( the Number of Students, Minus one because we started with one infected student)
    cout << UncleanPeople << " Percentage of Campus Infected: " << UncleanPeople / ( STUDENTS - 1.0 ) * 100.00 << "%" << endl;
    
    return UncleanPeople / ( STUDENTS - 1.0 ) * 100.00;
}

void readSeed() {
    /*  Variables  */
    int n;

    /*  Seed Prompt  */
    cout << "What would you like the seed for rand() to be? (If 0, use wall clock)" << endl;
    cin >> n;
    cout << endl << endl;
    if( n == 0 ) {
        n = unsigned(time(0));  // Wallclock
    }
    srand(n);
}

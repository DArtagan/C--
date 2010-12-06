//
//  Main routine for program that simulates the spread of flu on campus
//
#include <cstdlib>
#include <iostream>

#include "Student.h"

using namespace std;

void readSeed();
double simulator( int sickDays, int filterLocation, double infectionThreshold );

int main() {
    /*  Constants  */
    const int N(200);
    
    /*  Variables  */
    double average_infected(0);
    int counter(0);
    double minThreshold;
    double maxThreshold;
    double increment;
    
    /*  Header  */
    cout << " -- Flu on Campus Simulator --" << endl;
    
    /*  User Prompts  */
    readSeed();  // Sets the seed for rand()
    cout << "What would you like the minimum tested threshold for the sick day to be: " << flush;
    cin >> minThreshold;
    cout << endl << "What would you like the maximum tested threshold for the sick day to be: " << flush;
    cin >> maxThreshold;
    cout << endl << "How many increments should be tested for the sick day thresholds: " << flush;
    cin >> increment;
    cout << endl << endl;
    
    int SIZE( 2 * (Student::BUILDINGS + Student::COMMONS) * int(increment) + int(increment) ); // The ways this could go, depends on what threshold is chosen
    double* const simulationResults = new(nothrow) double[SIZE];
    if( simulationResults == NULL ) {
        cout << "Error when commandeering memory." << endl;
        exit(1);
    }
    
    /*  Simulator  */
    for( int d(0); d <= 2; d++ ){
        double t;
        double tempMaxThreshold;
        if( d == 0 ) {
            t = 101;
            tempMaxThreshold = 101;
        } else {
            t = minThreshold;
            tempMaxThreshold = maxThreshold;
            increment = (maxThreshold - minThreshold) / (increment - 1 );
        }
        for( ; t <= tempMaxThreshold; t + increment) {
            for( int f(0); f < Student::BUILDINGS + Student::COMMONS; f++ ) {
                if( d == 2 ) { // We can't have any air filters if we have payed for 2 sick days
                    f = 6; // Location 6 (Kafadar) is the one place we can't install a filter, thus it is the representation of no filters
                }
                for( int i(0); i < N; i++) {
                    cout << d << ", " << f << ", " << counter << ": Running simulation " << i << "...\n";
                    average_infected += simulator( d, f, t );
                }
                average_infected = average_infected / N;
                cout << endl << d << ", " << f << ", " << counter << ": There was an average infection rate of the campus of " << average_infected << "%" << endl << endl << endl;
                simulationResults[counter] = average_infected;
                counter++;
                if( d == 2 ) { // We can't have any air filters if we have payed for 2 sick days
                    f = Student::BUILDINGS + Student::COMMONS;
                }
            }
        }
    }
    // Needs to skip if both sick days are used
    // Filter location needs to have a location for no filters
    // Later put in a threshold for the sick days as well
    
    /*  Results  */
    cout << endl << endl;
    for( int i(0); i < SIZE; i++ ) {
        cout << simulationResults[i] << endl;
    }
    cout << endl << endl;
    system("PAUSE");
    delete[] simulationResults;
    return 0;
}

double simulator( int sickDays, int filterLocation, double infectionThreshold )
{
    /*  Constants  */
    const int STUDENTS(3000); // Students on campus
    const int WEEKS_IN_SEMESTER(16 );  // Weeks in a semester
    const int DAYS_IN_WEEK(7);  // Days in a week
    const int HOURS_IN_DAYS(24);
    const int WEEKEND(5);
    const int INITIALLY_VACCINATED(300);
    
    const int MONEY(10000);
    const int vaccineCost(75);
    const int filterCost(5500);
    const int sickDayCost(4500);
    //const double infectionThreshold(.1);
    
    /*  Variables  */
    Student students[STUDENTS];  //Array size, one Student for each STUDENT
    int UncleanPeople(0);  // Counter of people infected
    int spent(0);
    int vaccinated(0);
    int closedDays(0);
    
    /*  Initial conditions for the student body  */
    students[0].setStatus( Student::INFECTIOUS );  // The simulation must start with one infected student for the flu to spread
    for(int i(1); i <= INITIALLY_VACCINATED; i++) {  // Some students come to the school already vaccinated
        students[i].setStatus( Student::VACCINATED );
    }
    
    spent += sickDays * sickDayCost;
    if( filterLocation != 6 ) { // No air filters on Kafadar
        spent += filterCost; // As long as filterLocation != -1, there is a filter being installed
    }
    // Fix this one so that it has an option for a location with no filters
    
    /*  Vaccinate with the remaining money  */
    while( spent + vaccineCost <= MONEY ) {
        if( students[ rand() % STUDENTS ].vaccinate() ) {
            spent += vaccineCost;
            vaccinated++;
        }
    }
    
    /*  Simulation loop  */
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
				if( UncleanPeople / ( STUDENTS - 1.0 ) * 100 >= infectionThreshold && closedDays < sickDays ) {
                    closedDays++;
                } else {
				    // count locations
				    int locationCounts[Student::BUILDINGS + Student::COMMONS] = {};  // Initiate an array of locations to zero
				    for( int i(0); i < STUDENTS; i++ ) {  // Loop for each student
				    	if( students[i].isInfectious() ) {  // Loop for each student during that hour
						  locationCounts[students[i].getLocation()]++;  // Add one to each location when a student in that location is infectious
					   }
				    }
				    // catchFlu logic
				    for( int i(0); i < STUDENTS; i++ ) {  // Loop for each student
					   if( students[i].catchFlu( locationCounts, filterLocation ) ) {  // Run catch flu, has the location counts as a parameter
						  //students[i].output( cout );  // If someone caught the flu, cout
						  UncleanPeople++;  // Add one to the counter of people infected
						  //cout << UncleanPeople;
					   }
				    }
                }
        	}
		}
	}
    
    // Cout the percentage of people infected (People Infected / ( the Number of Students, Minus one because we started with one infected student)
    cout << /*UncleanPeople <<*/ " Percentage of Campus Infected: " << UncleanPeople / ( STUDENTS - 1.0 ) * 100.00 << "%" << endl;
    
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

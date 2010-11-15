#include <cstdlib>
#include <iostream>

#include "Student.h"

using namespace std;

int main()
{
    const int STUDENTS(4);
    Student students[STUDENTS];
    const int WEEKS_IN_SEMESTER(16);
    const int DAYS_IN_WEEK(5);
    
    for( int d(0); d < WEEKS_IN_SEMESTER * DAYS_IN_WEEK; d++ ) {
        for( int s = 0; s < STUDENTS; s++ ) {
            students[s].output(cout);
        }
    }
    
    system("PAUSE");
    return 0;
}

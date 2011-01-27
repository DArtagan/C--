//
// An example of providing an array as a function 
// parameter.
//
#include <cstdlib>
#include <iostream>
using namespace std;

/***
 * Returns the average value of data.
 */
double average( const double data[], const int size );
/***
 * Returns the number of elements in data that are
 * greater than threshold.
 */
int gt_threshold( const double data[], const int size,
		double threshold );

int main()
{
	const int SIZE(32);
	double userData[SIZE];
	int count(0);
	// read data from user
	cout << "Enter double values, 'end' to stop." << endl;
	while( count<SIZE && cin >> userData[count] ) {
		count++;
	}
	// find average
	double mean = average( userData, count ); 
	// find number of elements > 0.72*mean
	const double FACTOR(0.72);
	int gtFactor = 
			gt_threshold( userData, count, FACTOR*mean ); 
	// print results
	cout << "Average: " << mean << endl;
	cout << "Number of elements > " << 
			FACTOR << "*average: " << gtFactor << endl;
    //  Exit program.
    return 0;
}

double average( const double data[], const int size )
{
	double s(0);
	for( int i(0); i<size; i++ ) s += data[i];
	return s/size;
}

int gt_threshold( const double data[], const int size,
		double threshold )
{
	int c(0);
	for( int i(0); i<size; i++ ) c += data[i] > threshold;
	return c;
}




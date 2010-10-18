//
//  Program to find the roots of a quadratic function
//
#include "quadratic-roots.h"

int main()
{
    /*  Declare variables */
    double a;
    double b;
	double c;
	double first;
	double second;

	/*  Header and User Inputs  */
	cout << "--Quadratic Root Finder --" << endl << endl;
	cout << "What are the coefficients (a*x^2 + b*x + c = 0):" << endl;
	cout << "a: " << flush;
	cin >> a;
	cout << "b: " << flush;
	cin >> b;
	cout << "c: " << flush;
	cin >> c;
    cout << endl << endl;

	/*  Concluding Text, Print the Volume  */
    cout << "The roots of your quadratic equation ";
	cout << a << "*x^2" << " + " << b << "*x" << " + " << c << " = 0" << endl;
	if(QuadraticRootFinder(a, b, c, first, second)) {
		cout << "1st root: " << first << endl;
		cout << "2nd root: " << second;
	} else {
		cout << "Unreal roots";
    }
    cout << endl << endl << endl << endl;    
	
    system("PAUSE");
    //  Exit program.
    return 0;
}

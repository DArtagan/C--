//
//  Computes the roots of a quadratic function
//
#include "quadratic-roots.h"

double QuadraticRootFinder(double a, double b, double c, double& first, double& second)
{	
	/*  Variables  */
	double D;
	
	/*  Calculations  */
	D = pow(b,2) - 4 * a * c;
	if (D < 0) {
		return false;
	} else {
		first = (-(b) + sqrt(pow(b,2) - 4 * a * c))/(2 * a);
		second = (-(b) - sqrt(pow(b,2) - 4 * a * c))/(2 * a);
		return true;
	}
}

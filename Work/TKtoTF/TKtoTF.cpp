//
//  Program to convert Kelvin to Fahrenheit
//
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    /*  Declare/Identify Variables  */
    double kelvin;
    double fahrenheit;
    double rankin;
    const double nine_fifths = 9/5.0;  // For the conversion between Kelvin and Rankin
    const double fahrenheit_conversion = 459.67;  // For the conversion between Rankin and Fahrenheit
    
    /*  Prompt for Kelvin  */
    cout << "Convert Kelvin to Fahrenheit" << endl << endl;
    cout << "Enter temperature in Kelvin (K), to be converted:" << endl;
    cin >> kelvin;
    
    /*  Conversion  */
    //  Multiply the given temperature Kelvin by the conversion factor (9/5 to find the equivalent temperature in Rankin.
    rankin = nine_fifths * kelvin;
    //  Subtract 459.67 from the Rankin temperature to get degrees Fahrenheit.
    fahrenheit = rankin - fahrenheit_conversion;
        
    /*  Output result with guiding text  */
    cout << endl << endl << kelvin << " Kelvin ==> ";
    cout << fahrenheit << " degrees Fahrenheit";
    cout << endl << endl << endl;
    
    system("PAUSE");
    //  Exit Program
    return 0;
}

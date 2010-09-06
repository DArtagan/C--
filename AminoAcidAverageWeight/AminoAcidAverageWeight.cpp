//
//  Program to calculate the average weight of the atoms in an amino acid.
//
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    /*  Declare/Identify Variables  */
    int oxygen;
    int carbon;
    int nitrogen;
    int sulfur;
    int hydrogen;
    int total_atoms;
    double molecular_weight;
    double average_weight;
    const double weight_oxygen = 15.9994;
    const double weight_carbon = 12.011;
    const double weight_nitrogen = 14.00674;
    const double weight_sulfur = 32.066;
    const double weight_hydrogen = 1.00794;
    
    /*  Prompt for Kelvin  */
    cout << "Average weight of the atoms in an amino acid" << endl << endl;
    cout << "Enter how many of each of the prompted element atoms are present in an amino acid." << endl;
    cout << "Oxygen: " << flush;
    cin >> oxygen;
    cout << "Carbon: " << flush;
    cin >> carbon;
    cout << "Nitrogen: " << flush;
    cin >> nitrogen;
    cout << "Sulfur: " << flush;
    cin >> sulfur;
    cout << "Hydrogen: " << flush;
    cin >> hydrogen;
    
    /*  Calculations  */
    total_atoms = oxygen + carbon + nitrogen + sulfur + hydrogen;
    molecular_weight = oxygen * weight_oxygen + carbon * weight_carbon + nitrogen * weight_nitrogen + sulfur * weight_sulfur + hydrogen * weight_hydrogen;
    average_weight = molecular_weight / total_atoms;
        
    /*  Output result with guiding text  */
    cout << endl << endl << total_atoms << endl;
    cout << molecular_weight << endl;
    cout << average_weight << endl << endl;
    
    system("PAUSE");
    //  Exit Program
    return 0;
}

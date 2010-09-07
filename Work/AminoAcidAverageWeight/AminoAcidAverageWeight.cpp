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
    
    /*  Prompt for Atom Amounts  */
    cout << "-- Average Weight of the Atoms in an Amino Acid --" << endl << endl;
    cout << "When prompted, enter the number of atoms for each element of the amino acid." << endl << endl;
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
    total_atoms = oxygen + carbon + nitrogen + sulfur + hydrogen; // The number of atoms in the molecule
    molecular_weight = oxygen * weight_oxygen + carbon * weight_carbon + nitrogen * weight_nitrogen + sulfur * weight_sulfur + hydrogen * weight_hydrogen;  // The molecular weight of the molecule, found be multiplying all the atoms by their elemental weights.  
    average_weight = molecular_weight / total_atoms;  // The average atomic mass, found by dividing the molecular weight by the total nubmer of atoms.
        
    /*  Output average atomic weight with guiding text  */
    cout << endl;
    cout << "The average atomic weight of your amino acid is: " << average_weight;
    cout << endl << endl << endl;
    
    system("PAUSE");
    //  Exit Program
    return 0;
}

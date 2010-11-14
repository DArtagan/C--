//
//  Header file for the Month class
//
#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Month {
public:
/*  Constructor Declarations  */
    //  Default ctor, defaults to January
    Month( );
    //  ctor, initiallizes Month to a give month abbreviation
    Month( const string& Mon );
    //  ctor, initiallizes Month to a given month number
    Month( const int num );

/*  Constants  */
    static const int MONTHS = 12;

/*  Functions  */
    //  Allows assigning a Month object a given month by month abbreviation
    istream& input( istream& is );
    //  Outputs the month abbreviation of an object in a given method
    ostream& output( ostream& os ) const;
    //  Outputs the month number of an object in a given method
    ostream& outputMonthNumber( ostream& os ) const;
    //  Gets the month number for a given object
    int getMonthNumber( ) const;
    //  Outputs the next month as a new Month object
    Month next( ) const;
    //  Outputs a new Month object a given number of months after the original month
    Month next( const int count ) const;
    //  Outputs the previous month as a new Month object
    Month previous( ) const;
private:
/*  Helper Function(s)  */
    //  Searches the MonName stringe for a given abbreviation, 
    //  allows conversion between month name and number
    int search( const string needle ) const;
/*  Data Members  */
    int MonthIndex;
};

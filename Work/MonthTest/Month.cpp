//
//  Implementation file for the Month class
//
#include <iostream>
#include <cstdlib>

#include "Month.h"

//  String array for the month name abbreviations
static string MonName [12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

/*  Constructor Implementations  */
//  Default ctor, defaults to January
Month::Month( )
{
    MonthIndex = 1;
}

//  ctor, initiallizes Month to a give month abbreviation
Month::Month( const string& Mon )
{
    int x = search( Mon );
    if( x == -1 ) {  //  If the search function failed, it returned -1
        cout << "Fail, bad input" << endl;  //  Notify the user
    } else {
        MonthIndex = x + 1;  //  Add one to convert from the search function's index number to a month number
    }
}

//  ctor, initiallizes Month to a given month number
Month::Month( const int num )
{
    int x = num % MONTHS;
    if( x == 0 ) x = MONTHS;
    MonthIndex = x;
}


/*  Functions  */
//  Allows assigning a Month object a given month by month abbreviation
istream& Month::input( istream& is )
{
    string Mon;
    is >> Mon;
    int x = search( Mon );
    if( x == -1 ) {  //  If the search function failed it returned -1
        cout << "Fail, bad input" << endl;  //  Notify the user
        is.setstate( ios::failbit );
    } else {
        MonthIndex = x + 1;  //  Add one to convert from the search function's index number to a month number
    }
    return is;
}

//  Outputs the month abbreviation of an object in a given method
ostream& Month::output( ostream& os ) const
{
    os << MonName[MonthIndex - 1];
    return os;
}

//  Outputs the month number of an object in a given method
ostream& Month::outputMonthNumber( ostream& os ) const
{
    os << MonthIndex;
    return os;
}

//  Gets the month number for a given object
int Month::getMonthNumber( ) const
{
    return MonthIndex;
}

//  Outputs the next month as a new Month object
Month Month::next( ) const
{
    //  Add one to the current month's number to get the next month's number
    int nextMonth = MonthIndex + 1;
    //  In case adding one puts it outside the scope of this year
    //  Assign it to January
    if( nextMonth == 13) nextMonth = 1;
    return Month( nextMonth );
}

//  Outputs a new Month object a given number of months after the original month
Month Month::next( const int count ) const
{
    //  Add the current month's number and the requested count giving the future month number
    int nextMonth = MonthIndex + count;
    //  If the number for the future month is more than a year away, mod by MONTHS to make it representable in a single year
    nextMonth = nextMonth % MONTHS;
    if( nextMonth == 0 ) nextMonth = MONTHS;
    return Month( nextMonth );
}

//  Outputs the previous month as a new Month object
Month Month::previous( ) const
{
    //  Subtract one from the current month's number to get the previous month's number
    int previousMonth = MonthIndex - 1;
    //  In case subtracting one puts it before the scope of this year
    //  Assign it to December
    if( previousMonth == 0) previousMonth = MONTHS;
    return Month( previousMonth );
}


/*  Helper Function(s)  */
//  Searches the MonName stringe for a given abbreviation, 
//  allows conversion between month name and number
int Month::search( const string needle ) const
{
	int x(-1);  //  Fail value for this function
    //  Check to see if the string requested matches any of the strings in the MonName array
    //  If so, store which x with index number of the element that matches
    //  If not, x retains its fail value
    for(int i(0); i < MONTHS ; i++) {
		if(needle == MonName[i]) x = i;
	}
	return x;
}

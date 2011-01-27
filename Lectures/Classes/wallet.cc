/**
 * A Wallet class
 */

#include <iostream>     // system headers first
#include <string>
#include "wallet.h"    // developer headers second

using namespace std;

/**
 * Wallet implmplementation
 */

// default ctor makes a anonymous, empty wallet
Wallet::Wallet( )
{
	name = "???"; // anonymous marker
	dollars = 0;
	pennies = 0;
}

// specifies name only
Wallet::Wallet( const string& theName )
{
	name = theName;
	dollars = 0;
	pennies = 0;
}

Wallet::Wallet( const string& theName, 
		int theDollars, int thePennies ) 
{
	name = theName;
	if( money_logic( theDollars, thePennies ) ) {
		dollars = theDollars;
		pennies = thePennies;
	} else {
		cout << "Invalid amount $" << 
			theDollars << "." << thePennies << endl;
		dollars = 0;
		pennies = 0;
	}
}

// retrieve the wallet identification
string Wallet::id( ) const
{
	return name;
}

// retrieve the monetary value 
double Wallet::value( ) const 
{
	return dollars + double(pennies)/100;
}

// track expense by a real number
void Wallet::expense( double costAmount ) 
{
	// temporary vars
	double a = costAmount;
	if( money_logic( a ) ) {
		// input is valid, can we afford this?
		double newAmount = value() - a;
		if( money_logic( newAmount ) ) {
			// all is aok
			amount_to_dollars_pennies( newAmount, 
					dollars, pennies );
		}
	}
	// other wise money_logic has displayed an error message
	// to cout
}

// track expenses
void Wallet::expense( int costDollars, int costPennies )
{
	// temporary vars
	double amount;
	// convert to a double
	dollars_pennies_to_amount( costDollars, costPennies, amount );
	// chain to the amount implementation
	expense( amount );
}

// track income by amount
void Wallet::income( double earnAmount )
{
	if( money_logic( earnAmount ) ) {
		// positive amount -- aok
		amount_to_dollars_pennies( value() + earnAmount, 
				dollars, pennies );
	}
}

// track income via dollars and pennies
void Wallet::income( int earnDollars, int earnPennies )
{
	double amount;
	dollars_pennies_to_amount( earnDollars, earnPennies, amount );
	// chain to the amount implementation
	income( amount );
}

// print myself to the output stream
// returns a reference to the ostream argument provided
ostream& Wallet::output( ostream& os ) const
{
	os << name << " wallet contains $" 
			<< dollars << "." << pennies;
	return os;
}
// read value from the input stream --
// returns a reference to the istream argument provided
istream& Wallet::input( istream& is )
{
	// read into local vars first
	string n;
	int d, p;
	string wallet, contains;
	char dsign, period;
	if( is >> n >> wallet >> contains >> 
				dsign >> d >> period >> p ) {
		// make sure money amount is ok
		if( money_logic( d, p )) {
			// aok --- store data in object
			name = n;
			dollars = d;
			pennies = p;
		} else {
			// error! put the input stream into an error state
			is.setstate( ios::failbit );
		}
	}
	// return the input stream parameter
	return is;
}


// makes sure monetary amounts are always positive,
// displays a message to cout if amount is negative
bool Wallet::money_logic( int& theDollars, int& thePennies ) const
{
	if( theDollars >= 0 && thePennies >= 0 ) {
		// account for more than 100 pennies
		if( thePennies >= 100 ) {
			theDollars += thePennies/100;
			thePennies %= 100;
		}
		return true;
	}
	cout << "Invalid amount $" << theDollars << "." <<
			thePennies << endl;
	return false;
}

// breaks down double amount to dollars and pennies
bool Wallet::money_logic( const double& theAmount ) const 
{
	if( theAmount < 0 ) {
		cout << "Invalid amount $" << theAmount << endl;
		return false;
	}
	return true;
}

// converts a double to dollars and pennies integers
void Wallet::amount_to_dollars_pennies( double amount, 
		int& newDollars, int& newPennies ) const
{
	newDollars = int(amount); // chops off decimal
	newPennies = int(amount*100)%100; // finds pennies
}

// converts dollars and pennies to a decimal dollar amount
void Wallet::dollars_pennies_to_amount( int theDollars, 
			int thePennies, double& theAmount ) const 
{
	theAmount = theDollars + double(thePennies)/100;
}


/**
 * A wallet class
 */
#pragma once   

#include <iostream>
#include <string>
using namespace std;

/**
 * Wallet interface
 */
class Wallet {
public:
	// default ctor makes an empty, anonymous wallet
	Wallet( );   
	Wallet( const string& theName ); 
	Wallet( const string& name, 
			int theDollars, int thePennies ); 
	// retrieve the wallet identification
	string id( ) const;
	// retrieve the monetary value 
	double value( ) const;
	// track expenses
	void expense( int costDollars, int costPennies );
	void expense( double costAmount );
	// track income
	void income( int earnDollars, int earnPennies );
	void income( double earnAmount );
	// read value from the input stream --
	// returns a reference to the istream argument provided
	istream& input( istream& is );
	// print myself to the output stream
	// returns a reference to the ostream argument provided
	ostream& output( ostream& os ) const;
private:
	// makes sure monetary amounts are always positive,
	// carries >= 100 pennies to dollars
	// displays a message to cout if amount is negative
	bool money_logic( int& theDollars, int& thePennies ) const;
	// makes sure monetary amounts are positive
	// displays a message to cout if amount is negative
	bool money_logic( const double& theAmount ) const;
	// breaks down double input to dollars and pennies
	void amount_to_dollars_pennies( double theAmount, 
			int& theDollars, int& thePennies ) const ;
	// converts dollars and pennies to a decimal dollar amount
	void dollars_pennies_to_amount( int theDollars, 
			int thePennies, double& theAmount ) const ;
	
	// data members
	string name; // owner name
	int dollars;
	int pennies; // must be between 0 and 99
};

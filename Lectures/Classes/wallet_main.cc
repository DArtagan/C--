/***
 * An application using the wallet class application
 */

#include <iostream>
#include <fstream>
#include <string>

#include "wallet.h"

using namespace std;

// send wallet data to out1 and out2, followed by newlines 
void dualOutput( const Wallet& w, ostream& out1, ostream& out2 )
{
	w.output( out1 ) << endl;  
	w.output( out2 ) << endl;
}

int main()
{
	ofstream outfile( "wallet.log" );
	// an empty anonymous wallet
	Wallet anonymous;
	// two wallets for two different people
	Wallet Bob( "Bob" ); // no cash
	Wallet Alice( "Alice", 50, 32 ); // $50.32

	// print out and log
	dualOutput( anonymous, cout, outfile  );
	dualOutput( Bob, cout, outfile  );
	dualOutput( Alice, cout, outfile );

	// more readable output
	cout << endl; outfile << endl;

	cout << "Bob tries to spend 10 dollars..." << endl;
	// can't be done, Bob is broke
	Bob.expense( 10, 0 );  // generates error messgage, Bob is broke 
	Alice.expense( 10.0 ); // this is OK, Alice has cash 
	outfile << "Alice spends 10 dollars, her new value is: " <<
			Alice.value() << endl;
	dualOutput( Bob, cout, outfile  );
	dualOutput( Alice, cout, outfile );

	// more readable output
	cout << endl; outfile << endl;

	// Bob earns money with doubles
	while( true ) {
		cout << "Enter a double value for Bob's income," << endl;
		cout << "Enter a zero amount to stop: " << flush;
		double amount;
		if( !( cin >> amount ) || !amount ) {
			break;
		}
		outfile << "Bob income " << amount << endl;
		Bob.income( amount );
		dualOutput( Bob, cout, outfile );
	}

	// more readable output
	cout << endl; outfile << endl;

	// Alice earns money with integer dollars and pennies
	while( true ) {
		cout << "Enter integer dollars and cents for Alice's expense," << endl;
		cout << "Enter a zero amount (for both) to stop: " << flush;
		int dollars, pennies;
		if( !( cin >> dollars >> pennies ) || ( !dollars && !pennies ) ) {
			break;
		}
		outfile << "Alice expense " << dollars << " " << pennies << endl;
		Alice.expense( dollars, pennies);
		dualOutput( Alice, cout, outfile );
	}

	cout << endl << "End of program." << endl;
	return 0;
}

int main ()
{
	int counter(0);
	double value;
	
	ifstream inFile( "power1.dat" );
    if( !inFile ) {
        cout << "Error opening file." << endl;
        system("PAUSE");
        exit(1);
    }	
	
	while(inFile >> value) {
        counter++;
    }
	
	cout << counter;
	
	system("PAUSE");
    //  Exit Program
    return 0;
}

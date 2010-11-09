#include <cstdlib>
#include <iostream>

using namespace std;

int readSeed();

int main()
{
    readSeed() {
        /*  Variables  */
        int n;
    
        /*  Seed Prompt  */
        cout << "What would you like the seed for rand() to be? (If 0, use wall clock)" << endl;
        cin >> n;
        if( n == 0 ) {
            n = unsigned(time(0));
        }
    
        return n;
    }

    rand( readSeed() );

    /*  Variables  */
    int countdown( 1 + rand() % 20 );
    Student fluStudent( countdown );
    Student wellStudent( countdown );
    int sickHours(0);
    
    
    
    system("PAUSE");
    return 0;
}



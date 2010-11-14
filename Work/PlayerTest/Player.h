//
//  Header file for the Player class
//
#pragma once

#include <cstdlib>
#include <iostream>

using namespace std;

class Player {
public:
/*  Class Type Declaration  */
    Player(  );
/*  Getters  */
    // return firstName
    string getFirstName( ) const;
    // return lastName
    string getLastName( ) const;
    // return age
    int getAge( ) const;
    // return hometown
    string getHometown( ) const;
/*  Setters  */
    // set firstName
    void setFirstName( string name );
    // set lastName
    void setLastName( string name );
    // set age
    void setAge( int theAge );
    // set hometown
    void setHometown( string town );
private:
/*  Data Members  */
    string firstName;
    string lastName;
    int age;
    string hometown;
};

//
//  Implementation file for the Player class
//
#include "Player.h"

/*  Player ctor implementation  */
    Player::Player(  ) 
    {
        firstName = "Jane";
        lastName = "Doe";
        age = 0;
        hometown = "Goblintown, Virginia";
    }

/*  Getters  */
    // returns firstName
    string Player::getFirstName( ) const
    {
        return firstName;
    }
    // returns lastName
    string Player::getLastName( ) const
    {
        return lastName;
    }
    // returns age
    int Player::getAge( ) const
    {
        return age;
    }
    // returns hometown
    string Player::getHometown( ) const
    {
        return hometown;
    }

/*  Setters  */
    // Sets firstName
    void Player::setFirstName( string name )
    {
        firstName = name;
    }
    // sets lastName
    void Player::setLastName( string name )
    {
        lastName = name;
    }
    // sets age
    void Player::setAge( int theAge )
    {
        age = theAge;
    }
    // sets hometown
    void Player::setHometown( string town )
    {
        hometown = town;
    }

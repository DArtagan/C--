//
//  Program for playing the game Rock-Paper-Scissors
//
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    /*  Declare/Identify Variables  */
    char Player1;
    char Player2;
    
    const char ROCK = 'R';
    const char PAPER = 'P';
    const char SCISSORS = 'S';
    
    const string Player1_WINS ( "Player 1 wins! with " );
    const string Player2_WINS ( "Player 2 wins! with " );
    const string Player_TIE ( "Both players entered the same thing, it's a " );
    
    const string ROCK_WINS ( "Rock breaking the Scissors." );
    const string PAPER_WINS ( "Paper covering Rock." );
    const string SCISSORS_WINS ( "Scissors cutting Paper." );
    const string TIE ( "Tie." );
    
    string WINNER;
    string OUTCOME;
    int LOOP;
    
    /*  Ask for Players choice's  */
    cout << "-- Rock, Paper, Scissors --" << endl << endl;
    cout << "The classic game.  Enter either R for Rock, P for Paper, or Scissors." << endl;
    cout << "Player 1: " << flush;
    cin >> Player1;
    cout << string(50, '\n');
    cout << "-- Rock, Paper, Scissors --" << endl << endl;
    cout << "The classic game.  Enter either R for Rock, P for Paper, or Scissors." << endl;
    cout << "Player 2: " << flush;
    cin >> Player2;
    cout << endl;
    
    /*  Make char variables homogenous  */
    if (Player1 == 'r') {
        Player1 = 'R';
    } else if (Player1 == 'p') {
        Player1 = 'P';
    } else {
        Player1 = 'S';
    }
    if (Player2 == 'r') {
        Player2 = 'R';
    } else if (Player2 == 'p') {
        Player2 = 'P';
    } else {
        Player2 = 'S';
    }
    
    /*  Game Calculations  */
    if (Player1 == 'R' && Player2 == 'S') {
        WINNER = Player1_WINS;
        OUTCOME = ROCK_WINS;
    } else if (Player1 == 'P' && Player2 == 'R') {
        WINNER = Player1_WINS;
        OUTCOME = PAPER_WINS;
    } else if (Player1 == 'S' && Player2 == 'P') {
        WINNER = Player1_WINS;
        OUTCOME = SCISSORS_WINS;
    } else if (Player2 == 'R' && Player1 == 'S') {
        WINNER = Player2_WINS;
        OUTCOME = ROCK_WINS;
    } else if (Player2 == 'P' && Player1 == 'R') {
        WINNER = Player2_WINS;
        OUTCOME = PAPER_WINS;
    } else if (Player2 == 'S' && Player1 == 'P') {
        WINNER = Player2_WINS;
        OUTCOME = SCISSORS_WINS;
    } else {
        WINNER = Player_TIE;
        OUTCOME = TIE;
        LOOP = 1;
    }
        
    
    /*  Game Outcome  */
    cout << endl;
    cout << WINNER << OUTCOME;
    cout << endl << endl << endl << endl;
    
    system("PAUSE");
    //  Exit Program
    return 0;
}

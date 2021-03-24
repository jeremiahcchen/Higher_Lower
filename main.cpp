#include <iostream>
#include <ctime>
#include "Player.h"

using namespace std;

/* logic:
    1. Create a deck [cards: 1-13]
    2. Allow two players to take turn guessing higher, lower, or same
    3. If a player guesses wrong they get a strike
    4. Whatever card was pulled, can't be pulled again
    5. If a player gets 3 strikes they are eliminated
    6. If a player guesses same and they get it right they 
       immediately win
    7. If the entire deck was played the game ends in a draw


    Extra: Another game mode
      - Group version with group strikes and try to 
        get to the end of the deck

*/

const int SIZE = 52;

void shuffle(int Deck[])
{
    srand(time(0));

    for(int i = 0; i < SIZE; i++)
    {
        int r = i + (rand() % (52 - i));
        swap(Deck[i], Deck[r]);
    }
}


int main()
{
    int card_count = 1;
    int cardIndex = 0;
    int tStrikes = 0;
    int Deck[SIZE];
    bool gameOver;      //When true game is over
    bool logic;         //logic for player decisions
    char guess;
    char mode;
    Player player1 = Player();
    Player player2 = Player();

    //Creating the deck
    for(int i = 0; i < SIZE; i++)
    {
        Deck[i] = card_count++;
        if(card_count == 14)
        {
            card_count = 1;
        }
    }

    shuffle(Deck);

    cout << "Welcome to Higher or Lower" << endl;

    //Game Mode
    while(!logic)
    {
        logic = true;
        cout << "Which Game mode do you want to play (Verses or Team)? (v or t): ";
        cin >> mode;
        switch(mode)
        {
            case 'v':
                cout << "\nGame Mode: VS" << endl;
                break;
            case 't':
                cout << "\nGame Mode: Team" << endl;
                cout << "\nHow many total strikes do you want?: ";
                cin >> tStrikes;
                break;
            default:
                logic = false;
                cout << "\nPlease Select the Given Choices\n\n";
        }
    }


    //VERSES
    while(!gameOver && mode == 'v')
    {
        logic = false;
        cout << "\nCard: " << Deck[cardIndex] << endl << endl;
        cardIndex++;
        //Player 1
        while(!logic){
            logic = true;
            cout << "Player 1 has " << player1.strike << " strikes." << endl;
            cout << "Player one guess (h,l,s): ";
            cin >> guess;
            switch(guess)
            {
                case 'h':
                    if(Deck[cardIndex - 1] > Deck[cardIndex] || Deck[cardIndex - 1] == Deck[cardIndex])
                    {
                        player1.strike++;
                    }
                    break;
                case 'l':
                    if(Deck[cardIndex - 1] < Deck[cardIndex] || Deck[cardIndex - 1] == Deck[cardIndex])
                    {
                        player1.strike++;
                    }
                    break;
                case 's':
                    if(Deck[cardIndex - 1] == Deck[cardIndex])
                    {
                        cout << "\nPlayer 1 wins" << endl;
                        gameOver = true;
                        return 0;
                    }
                    else
                    {
                        player1.strike++;
                    }
                    break;
                default:
                    logic = false;
                    cout << "\nPlease Select the Given Choices\n\n";
                    cout << "Card: " << Deck[cardIndex] << endl << endl;
            }
            if(player1.strike == 3)
            {
                cout << "\nCard: " << Deck[cardIndex] << endl << endl;
                cout << "Player 1 has " << player1.strike << " strikes." << endl;
                cout << "\nPlayer 1 Loses" << endl;
                return 0;
            }
        }
        cout << "\nCard: " << Deck[cardIndex] << endl << endl;
        cardIndex++;
        logic = false;
        //Player 2
        while(!logic){
            logic = true;
            cout << "Player 2 has " << player2.strike << " strikes." << endl;
            cout << "Player 2 guess (h,l,s): ";
            cin >> guess;
            switch(guess)
            {
                case 'h':
                    if(Deck[cardIndex - 1] > Deck[cardIndex] || Deck[cardIndex - 1] == Deck[cardIndex])
                    {
                        player2.strike++;
                    }
                    break;
                case 'l':
                    if(Deck[cardIndex - 1] < Deck[cardIndex] || Deck[cardIndex - 1] == Deck[cardIndex])
                    {
                        player2.strike++;
                    }
                    break;
                case 's':
                    if(Deck[cardIndex - 1] == Deck[cardIndex])
                    {
                        cout << "\nPlayer 2 wins" << endl;
                        gameOver = true;
                    }
                    else
                    {
                        player2.strike++;
                    }
                    break;
                default:
                    logic = false;
                    cout << "\nPlease Select the Given Choices\n\n";
                    cout << "Card: " << Deck[cardIndex] << endl << endl;
            }
            if(player2.strike == 3)
            {
                cout << "\nCard: " << Deck[cardIndex] << endl << endl;
                cout << "Player 2 has " << player2.strike << " strikes." << endl;
                cout << "\nPlayer 2 Loses" << endl;
                return 0;
            }
        }
        if(cardIndex > 51)
        {
            cout << "Tie, Good Game" << endl;
            gameOver = true;
        }
    }

//---------------------------------TEAM------------------------------------

    while(!gameOver && mode == 't')
    {
        logic = false;
        cout << "\nCard: " << Deck[cardIndex] << endl << endl;
        cardIndex++;
        //Player 1
        while(!logic){
            logic = true;
            cout << "Players has " << player1.strike << " strikes." << endl;
            cout << "Guess (h,l,s): ";
            cin >> guess;
            switch(guess)
            {
                case 'h':
                    if(Deck[cardIndex - 1] > Deck[cardIndex] || Deck[cardIndex - 1] == Deck[cardIndex])
                    {
                        player1.strike++;
                    }
                    break;
                case 'l':
                    if(Deck[cardIndex - 1] < Deck[cardIndex] || Deck[cardIndex - 1] == Deck[cardIndex])
                    {
                        player1.strike++;
                    }
                    break;
                case 's':
                    if(Deck[cardIndex - 1] == Deck[cardIndex])
                    {
                        cout << "\nYOU WON!!!" << endl;
                        gameOver = true;
                        return 0;
                    }
                    else
                    {
                        player1.strike++;
                    }
                    break;
                default:
                    logic = false;
                    cout << "\nPlease Select the Given Choices\n\n";
                    cout << "Card: " << Deck[cardIndex] << endl << endl;
            }
            if(player1.strike == tStrikes)
            {
                cout << "\nCard: " << Deck[cardIndex] << endl << endl;
                cout << "Team has " << player1.strike << " strikes." << endl;
                cout << "\nTeam Loses" << endl;
                return 0;
            }
        }

        if(cardIndex > 51)
        {
            cout << "You Win!!!" << endl;
            gameOver = true;
        }
    }

    return 0;
}

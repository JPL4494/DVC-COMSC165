/*
Joshua Long
Comcs 165
Tic-Tac-Toe game
9-15-13
COMPLETE
Module 3 Part 2
*/

#include<iostream>
#include <cstdlib>

using namespace std;

int player1(char board[3][3], int winner);
int player2(char board[3][3], int winner);

int main()
{
    int turn = 0, r, c, winner = 0, s1, s2;
    char board[3][3] = {{'*', '*', '*'},
                        {'*', '*', '*'},
                        {'*', '*', '*'}};

    while (turn < 9)
    {
        for(int r = 0; r < 3; r++)
    {
        for(int c = 0; c < 3; c++)
        {
            cout << " " << board[r][c];
            if (c < 2)
            {
                cout << " |";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;

        if (r < 2)
        {
            cout << "-----------";
        }

        cout << endl;
    }
    goback1:
    cout << "Player 1, X, choose a row <1-3>: ";
    cin >> s1;
    cout << "Now a column <1-3>: ";
    cin >> s2;
    if (s1 > 3)
    {
        goto goback1;
    }
    if (s2 > 3)
    {
        goto goback1;
    }
    s1 = s1-1;
    s2 = s2-1;


    if (board[s1][s2] == 'O' || board[s1][s2] == 'X')
    {
        cout << "Oops! Picked an already picked number, try again" << endl;
        goto goback1;
    }

    board[s1][s2] = 'X';

    system("CLS");
    turn++;

    winner = player1(board,winner);

        for(int r = 0; r < 3; r++)
    {
        for(int c = 0; c < 3; c++)
        {
            cout << " " << board[r][c];
            if (c < 2)
            {
                cout << " |";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;

        if (r < 2)
        {
            cout << "-----------";
        }

        cout << endl;
    }
    if (turn == 9)
    {
        break;
    }
    if (winner > 0)
    {
        break;
    }

    goback2:
    cout << "Player 2, O, choose a row <1-3>: ";
    cin >> s1;
    cout << "Now a column <1-3>: ";
    cin >> s2;
    if (s1 > 3)
    {
        goto goback2;
    }
    if (s2 > 3)
    {
        goto goback2;
    }
    s1 = s1-1;
    s2 = s2-1;
    if (board[s1][s2] == 'O' || board[s1][s2] == 'X')
    {
        cout << "Oops! Picked an already picked number, try again" << endl;
        goto goback2;
    }
    board[s1][s2] = 'O';

    system("CLS");
    turn++;

    winner = player2(board,winner);

    if (winner > 0)
    {
        break;
    }

    }

    system("CLS");
    for(int r = 0; r < 3; r++)
    {
        for(int c = 0; c < 3; c++)
        {
            cout << " " << board[r][c];
            if (c < 2)
            {
                cout << " |";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;

        if (r < 2)
        {
            cout << "-----------";
        }

        cout << endl;
    }

    if (winner > 0)
    {
        cout << endl << endl << "Congrulations Player " << winner << ", you have won!" << endl << endl;
    }

    if (winner == 0)
    {
        cout << endl << endl << "Oops! It looks like no one won, try again then" << endl << endl;
    }
}

int player1(char board[3][3], int winner)
{
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] == 'X')
    {
        winner = 1;
    }

    if (board[1][0] == board[1][1] && board[0][1] == board[1][2] && board[1][0] == 'X')
    {
        winner = 1;
    }

    if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] == 'X')
    {
        winner = 1;
    }

    if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] == 'X')
    {
        winner = 1;
    }

    if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] == 'X')
    {
        winner = 1;
    }

    if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] == 'X')
    {
        winner = 1;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == 'X')
    {
        winner = 1;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == 'X')
    {
        winner = 1;
    }

    return winner;
}

int player2(char board[3][3], int winner)
{
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[2][0] == 'O')
    {
        winner = 2;
    }

    if (board[1][0] == board[1][1] && board[0][1] == board[1][2] && board[1][0] == 'O')
    {
        winner = 2;
    }

    if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] == 'O')
    {
        winner = 2;
    }

    if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] == 'O')
    {
        winner = 2;
    }

    if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] == 'O')
    {
        winner = 2;
    }

    if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] == 'O')
    {
        winner = 2;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == 'O')
    {
        winner = 2;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == 'O')
    {
        winner = 2;
    }

    return winner;
}




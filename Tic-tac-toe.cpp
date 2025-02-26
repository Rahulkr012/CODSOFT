#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentMarker;
int currentPlayer;

void drawBoard()
{
    cout << "\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool placeMarker(int slot)
{
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = currentMarker;
        return true;
    }
    return false;
}

int checkWinner()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return currentPlayer;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return currentPlayer;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return currentPlayer;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return currentPlayer;
    return 0;
}

void swapPlayerAndMarker()
{
    if (currentMarker == 'X')
        currentMarker = 'O';
    else
        currentMarker = 'X';

    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

void game()
{
    currentMarker = 'X';
    currentPlayer = 1;
    int slot, winner = 0, moves = 0;

    while (winner == 0 && moves < 9)
    {
        drawBoard();
        cout << "Player " << currentPlayer << "'s turn. Enter slot: ";
        cin >> slot;

        if (slot < 1 || slot > 9 || !placeMarker(slot))
        {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        winner = checkWinner();
        if (winner == 0)
            swapPlayerAndMarker();
        moves++;
    }

    drawBoard();
    if (winner != 0)
        cout << "Player " << winner << " wins!\n";
    else
        cout << "It's a draw!\n";
}

int main()
{
    char playAgain;
    do
    {
        board[0][0] = '1';
        board[0][1] = '2';
        board[0][2] = '3';
        board[1][0] = '4';
        board[1][1] = '5';
        board[1][2] = '6';
        board[2][0] = '7';
        board[2][1] = '8';
        board[2][2] = '9';

        game();
        cout << "Play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}

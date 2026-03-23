#include <iostream>
using namespace std;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void showBoard()
{
    cout << "\n";
    for (int i = 0; i < 3; i++)
    {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2];
        if (i != 2) cout << "\n---|---|---\n";
    }
    cout << "\n";
}

bool checkWin(char p)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == p && board[i][1] == p && board[i][2] == p)
            return true;

        if (board[0][i] == p && board[1][i] == p && board[2][i] == p)
            return true;
    }

    if (board[0][0] == p && board[1][1] == p && board[2][2] == p)
        return true;

    if (board[0][2] == p && board[1][1] == p && board[2][0] == p)
        return true;

    return false;
}

bool draw()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;

    return true;
}

void resetBoard()
{
    char val = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = val++;
}

int main()
{
    char again;

    do
    {
        resetBoard();
        char player = 'X';
        int move;

        while (true)
        {
            showBoard();

            cout << "\nPlayer " << player << ", enter position (1-9): ";
            cin >> move;

            int row = (move - 1) / 3;
            int col = (move - 1) % 3;

            if (move < 1 || move > 9 || board[row][col] == 'X' || board[row][col] == 'O')
            {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            board[row][col] = player;

            if (checkWin(player))
            {
                showBoard();
                cout << "\nPlayer " << player << " wins!\n";
                break;
            }

            if (draw())
            {
                showBoard();
                cout << "\nGame is a draw.\n";
                break;
            }

            if (player == 'X')
                player = 'O';
            else
                player = 'X';
        }

        cout << "\nPlay again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    cout << "\nGame ended.\n";
    return 0;
}

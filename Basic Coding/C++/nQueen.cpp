#include <iostream>
using namespace std;
int sha = 1;



bool canPlace(int **board, int n, int x, int y)
{
   //column check
    for (int k = 0; k < x; k++)
    {
        if (board[k][y] == 1)
        {
            return false;
        }
    }
  //diagonal check
    int i = x;
    int j = y;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j--;
    }

//diagonal check
    i = x;
    j = y;
    while (i >= 0 && j < n)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j++;
    }
    return true;
}

void printBoard(int n, int **board)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int solveNQueen(int n, int **board, int i)
{
    if (i == n)
    {
        printBoard(n, board);
        return 1;
    }

    int ways = 0;

    for (int j = 0; j < n; j++)
    {
        if (canPlace(board, n, i, j))
        {
            board[i][j] = 1;
            ways += solveNQueen(n, board, i + 1);
            board[i][j] = 0;
        }
    }

    /* cout << endl;
    cout << "shanto: " << sha++ << endl;
    printBoard(n, board);
    cout << endl; */

    return ways;
}

int main()
{
    int n = 7;
    int **arr = new int *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    cout << solveNQueen(n, arr, 0);
}

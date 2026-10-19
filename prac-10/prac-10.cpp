#include <iostream>
#include <vector>
using namespace std;

int solutionCount = 0;

// Function to check whether a queen can be placed
bool isSafe(vector<vector<int>> &board, int row, int col, int n)
{
    // Check column
    for(int i = 0; i < row; i++)
        if(board[i][col])
            return false;

    // Check left diagonal
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if(board[i][j])
            return false;

    // Check right diagonal
    for(int i = row, j = col; i >= 0 && j < n; i--, j++)
        if(board[i][j])
            return false;

    return true;
}

// Print solution
void printBoard(vector<vector<int>> &board, int n)
{
    cout << "\nSolution " << ++solutionCount << endl;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j])
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

// Backtracking function
void solveNQueens(vector<vector<int>> &board, int row, int n)
{
    if(row == n)
    {
        printBoard(board, n);
        return;
    }

    for(int col = 0; col < n; col++)
    {
        if(isSafe(board, row, col, n))
        {
            board[row][col] = 1;

            solveNQueens(board, row + 1, n);

            // Backtrack
            board[row][col] = 0;
        }
    }
}

int main()
{
    int n;

    cout << "Enter value of N: ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    solveNQueens(board, 0, n);

    if(solutionCount == 0)
        cout << "\nNo solution exists." << endl;
    else
        cout << "\nTotal Solutions = " << solutionCount << endl;

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>> &grid, int row, int col, int m, int n)
{
    if(row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == '0')
        return;

    grid[row][col] = '0';

    dfs(grid, row - 1, col, m, n);
    dfs(grid, row + 1, col, m, n);
    dfs(grid, row, col - 1, m, n);
    dfs(grid, row, col + 1, m, n);
}

int numIslands(vector<vector<char>> &grid, int m, int n)
{
    int count = 0;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(grid[i][j] == '1')
            {
                count++;
                dfs(grid, i, j, m, n);
            }
        }
    }

    return count;
}

int main()
{
    int m, n;

    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n));

    cout << "Enter grid elements (1 for land, 0 for water):\n";
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    int islands = numIslands(grid, m, n);

    cout << "Number of islands: " << islands << endl;

    return 0;
}

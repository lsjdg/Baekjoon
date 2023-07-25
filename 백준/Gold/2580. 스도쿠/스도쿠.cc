#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> sudoku(9, vector<int>(9));
int zeroCount{ 0 };
bool foundSolution{ false };

bool isAble(int r, int c, int x)
{
    for (int i{ 0 }; i < 9; i++)
    {
        if (sudoku[r][i] == x)
            return false;
    }
    for (int i{ 0 }; i < 9; i++)
    {
        if (sudoku[i][c] == x)
            return false;
    }
    for (int i{ 3 * (r / 3) }; i < 3 * (r / 3) + 3; i++)
    {
        for (int j{ 3 * (c / 3) }; j < 3 * (c / 3) + 3; j++)
        {
            if (sudoku[i][j] == x)
                return false;
        }
    }
    return true;
}

void printSudoku()
{
    for (int i{ 0 }; i < 9; i++)
    {
        for (int j{ 0 }; j < 9; j++)
        {
            cout << sudoku[i][j] << ' ';
        }
        cout << '\n';
    }
}

void fill(int r, int c, int level)
{
    if (foundSolution)
        return;

    if (level == zeroCount)
    {
        printSudoku();
        foundSolution = true;
        return;
    }

    int nextR = r, nextC = c + 1;
    if (nextC == 9)
    {
        nextR++;
        nextC = 0;
    }

    if (sudoku[r][c] != 0)
    {
        fill(nextR, nextC, level);
    }
    else
    {
        for (int num{ 1 }; num <= 9; num++)
        {
            if (isAble(r, c, num))
            {
                sudoku[r][c] = num;
                fill(nextR, nextC, level + 1);
                sudoku[r][c] = 0;
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for (int i{ 0 }; i < 9; i++)
    {
        for (int j{ 0 }; j < 9; j++)
        {
            cin >> sudoku[i][j];
            if (sudoku[i][j] == 0)
                zeroCount++;
        }
    }

    fill(0, 0, 0);
}

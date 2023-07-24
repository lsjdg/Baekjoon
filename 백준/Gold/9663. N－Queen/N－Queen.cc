#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, c{ 0 };

bool isAble(vector<int>& column, int col, int row)
{
	for (int i{ 0 }; i < row; i++)
	{
		if (column[i] == col || abs(column[i] - col) == abs(i - row))
			return false;
	}
	return true;
}
void putQueen(vector<int>& column, int row)
{
	if (row == n)
	{
		c++;
		return;
	}
	for (int i{ 0 }; i < n; i++)
	{
		if (isAble(column, i, row))
		{
			column[row] = i;
			putQueen(column, row + 1);
		}
	}
}
int main()
{
	cin >> n;
	vector<int> v(n, 0);
	putQueen(v, 0);
	cout << c;
}
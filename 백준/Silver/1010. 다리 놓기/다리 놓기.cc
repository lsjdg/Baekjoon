#include <iostream>
using namespace std;

int main()
{
	int test, n, m;
	cin >> test;
	int comb[30][30];

	for (int i{ 0 }; i < 30; i++)
	{
		for (int j{ 0 }; j < 30; j++)
		{
			comb[i][j] = 1;
		}
	}

	for (int i{ 1 }; i < 29; i++)
	{
		for (int j{ 0 }; j < i; j++)
		{
			comb[i + 1][j + 1] = comb[i][j] + comb[i][j + 1];
		}
	}
	
	for (int i{ 0 }; i < test; i++)
	{
		cin >> n >> m;
		cout << comb[m][n] << '\n';
	}
	
}

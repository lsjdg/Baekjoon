#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int whiteCount(int, int, string[], vector<string>);
int blackCount(int, int, string[], vector<string>);

int main()
{
	int m, n;
	cin >> m >> n;
	
	string white[8]
	{
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW" 
	};
	string black[8]
	{
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB"
	};

	vector <string> chess(m);
	for (int i{ 0 }; i < m; i++)
	{
		string row;
		cin >> row;
		chess[i] = row;
	}
	
	int min{64};

	for (int i{ 0 }; i <= m - 8; i++)
	{
		for (int j{ 0 }; j <= n - 8; j++)
		{
			if (blackCount(i, j, black, chess) < min)
			{
				min = blackCount(i, j, black, chess);
			}	
		}
	}
	
	for (int i{0}; i <= m - 8; i++)
	{
		for (int j{ 0 }; j <= n - 8; j++)
		{
			if (whiteCount(i, j, white, chess) < min)
				min = whiteCount(i, j, white, chess);
		}
	}

	cout << min;
	return 0;
}

int whiteCount(int x, int y, string white[8], vector <string> chess)
{
	int count{ 0 };

	for (int i{ 0 }; i < 8; i++)
	{
		for (int j{ 0 }; j < 8; j++)
		{
			if (chess[x + i][y + j] != white[i][j])
				count++;
		}
	}

	return count;
}

int blackCount(int x, int y, string black[8], vector <string> chess)
{
	int count{ 0 };

	for (int i{ 0 }; i < 8; i++)
	{
		for (int j{ 0 }; j < 8; j++)
		{
			if (chess[x + i][y + j] != black[i][j])
				count++;
		}
	}

	return count;
}
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int reps;
	cin >> reps;
	for (int i{ 0 }; i < reps; i++)
	{
		int floor, room;
		cin >> floor >> room;

		vector<vector<int>>hotel(15, vector<int>(14));
		for (int i{ 0 }; i < 14; i++)
		{
			hotel[0][i] = i + 1;
		}

		for (size_t i{ 0 }; i <= 14; i++)
		{
			hotel[i][0] = 1;
		}

		for (size_t i{ 1 }; i <= 14; i++)
		{
			for (size_t j{ 1 }; j < 14; j++)
			{
				hotel[i][j] = hotel[i - 1][j] + hotel[i][j - 1];
			}
		}
		cout << hotel[floor][room-1] << endl;
	}
}
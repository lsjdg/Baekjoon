#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int sizeX, sizeY, sector;
	vector <vector <int> > v;
	cin >> sizeX >> sizeY;
	for (int i{ 0 }; i < sizeX; i++)
	{
		vector <int> row;
		for (int i{ 0 }; i < sizeY; i++)
		{
			int n;
			cin >> n;
			row.push_back(n);
		}
		v.push_back(row);
	}
	
	cin >> sector;
	for (int i{ 0 }; i < sector; i++)
	{
		int sum{ 0 };
		int startX, startY, endX, endY;
		cin >> startX >> startY >> endX >> endY;

		for (int x{ startX }; x < endX+1; x++)
		{
			for (int y{ startY }; y < endY+1; y++)
			{
				sum += v[x - 1][y - 1];
			}
		}
		cout << sum << '\n';
	}
}
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	int horizontalCount{ 0 };
	int verticalCount{ 0 };
	char room[100][100] {0};

	for (int height{ 0 }; height < m; height++)
	{
		for (int len{ 0 }; len < n; len++)
		{
			char wood;
			cin >> wood;
			room[len][height] = wood;
		}
	}

	for (int height{ 0 }; height < m; height++)
	{
		for (int len{ 0 }; len < n; len++)	
		{
			if (room[len][height] == '-')
			{
				while (room[len][height] == '-')
				{
					len++;
				}
				horizontalCount++;
			}
		}
	}

	for (int len{ 0 }; len < n; len++)
	{
		for (int height{ 0 }; height < m; height++)
		{
			if (room[len][height] == '|')
			{
				while (room[len][height] == '|')
				{
					height++;
				}
				verticalCount++;
			}
		}
	}

	cout << horizontalCount + verticalCount;

	return 0;
}
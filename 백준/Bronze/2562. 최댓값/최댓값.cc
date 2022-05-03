#include<iostream>
using namespace std;

int N, maxValue, maxLocation;
int list[9];

int main()
{
	cin >> list[0];
	maxValue = list[0];
	maxLocation = 1;

	for (int i = 1; i < 9; i++)
	{
		cin >> list[i];
		if (list[i] > maxValue)
		{
			maxValue = list[i];
			maxLocation = i + 1;
		}
	}

	cout << maxValue << endl;
	cout << maxLocation;
}

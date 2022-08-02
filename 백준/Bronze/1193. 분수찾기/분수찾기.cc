#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int line{ 0 };
	while (1)
	{
		int lineSum = line * (line + 1) / 2;
		if (lineSum >= n)
			break;
		line++;
	}

	int index = n - line * (line - 1) / 2;
	int denom, numer;

	if (line % 2 == 0)
	{
		numer = index;
		denom = line + 1 - index;
	}

	else
	{
		denom = index;
		numer = line + 1 - index;
	}

	cout << numer << "/" << denom;
}
#include <iostream>
#include <array>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

int isHan(int);

int main()
{
	int n;
	cin >> n;
	int count{ 0 };
	for (int i{ 1 }; i <= n; i++)
	{
		if (isHan(i) == 1)
			count++;
	}
	cout << count;
}

int isHan(int n)
{
	if (0 < n && n < 100)
		return 1;

	int det{ 0 };
	int i{ 0 };
	vector <int> diff(10000);
	while (true)
	{
		int digitOne = n % 10;
		n /= 10;
		if (n <= 0)
			break;
		int digitTwo = n % 10;
		int sub = digitOne - digitTwo;
		diff[i] = sub;
		if (i >= 1)
		{
			if (diff[i] != diff[i - 1])
				det += 1;
		}
		i++;
	}
	if (det == 0)
		return 1;
	else
		return 0;
}
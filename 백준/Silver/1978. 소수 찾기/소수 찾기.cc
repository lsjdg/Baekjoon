#include <iostream>
#include <cmath>
using namespace std;

bool isPrime (int);
int main()
{
	int n;
	unsigned count{ 0 };
	cin >> n;
	for (int i{ 0 }; i < n; i++)
	{
		int num;
		cin >> num;

		if (isPrime(num) == 1)
			count++;
	}

	cout << count;
	return 0;
}

bool isPrime(int n)
{
	if (n < 2)
		return 0;
	if (n == 2 || n == 3)
		return 1;
	else
	{
		for (int i{ 2 }; i <= sqrt(n); i++)
		{
			if (n % i == 0)
				return 0;
		}
	}

	return 1;
}

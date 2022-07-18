#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int count{ 0 }, c{0};
	array <int, 10> leftovers;
	while (c < 10)
	{
		cin >> n;
		leftovers[c] = n % 42;
		c++;
	}

	array <int, 42> frequency;
	for (int i{ 0 }; i < 42; i++)
	{
		frequency[i] = 0;
	}
	

	for (int i{ 0 }; i < 10; i++)
	{
		frequency[leftovers[i]]++;
	}

	for (int num : frequency)
	{
		if (num != 0)
			count++;
	}
	cout << count;
	
}
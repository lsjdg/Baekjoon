#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int main()
{
	array <int, 8> sorted{ 1,2,3,4,5,6,7,8 };
	array <int, 8> reversed{ 8,7,6,5,4,3,2,1 };
	array <int, 8> input;
	
	for (size_t i{ 0 }; i < 8; i++)
	{
		int n;
		cin >> n;
		input[i] = n;
	}

	if (equal(input.begin(), input.end(), sorted.begin(), sorted.end()) == 1)
		cout << "ascending";
	else if (equal(input.begin(), input.end(), reversed.begin(), reversed.end()))
		cout << "descending";
	else
		cout << "mixed";

	return 0;
}
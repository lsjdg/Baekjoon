#include <iostream>
using namespace std;

int main()
{
	unsigned base, produce, sell;
	cin >> base >> produce >> sell;
	
	if (sell > produce)
	{
		cout << base / (sell - produce) + 1;
	}

	else
		cout << -1;
}
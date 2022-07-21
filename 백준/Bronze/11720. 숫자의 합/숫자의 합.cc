#include <iostream>

using namespace std;


int main()
{
	int n, sum{0};
	cin >> n;
	char c;
	for (int i{ 0 }; i < n; i++)
	{
		cin >> c;
		sum += int(c) - 48;
	}
	cout << sum;
	
}

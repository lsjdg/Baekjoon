#include <iostream>
using namespace std;

int main()
{
	int n, comp{0};
	cin >> n;

	for (int i{ 0 }; i < n; i++)
	{
		int holes;
		cin >> holes;
		comp += holes;
	}
	
	cout << comp - (n - 1);
}

#include <iostream>

using namespace std;

int main()
{
	int count{ 0 };
	for (int i{ 0 }; i < 5; i++)
	{
		int n;
		cin >> n;
		count += n*n;
	}
	cout << count % 10;
	return 0;
}
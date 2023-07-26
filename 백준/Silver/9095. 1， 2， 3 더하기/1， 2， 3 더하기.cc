#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> sumCount (12);
	sumCount[0] = 0;
	sumCount[1] = 1;
	sumCount[2] = 2;
	sumCount[3] = 4;
	for (int i{ 4 }; i <= 11; i++)
	{
		sumCount[i] = sumCount[i - 1] + sumCount[i - 2] + sumCount[i-3];
	}
	int test;
	cin >> test;
	while (test--)
	{
		int n;
		cin >> n;
		cout << sumCount[n] << '\n';
	}
}
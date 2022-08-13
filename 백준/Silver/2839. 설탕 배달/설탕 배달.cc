#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int weight;
	cin >> weight;
	vector <int> ways(1, 5000);

	int max = weight / 3 + (weight % 3) / 5;
	for (int i{ 0 }; i <= max; i++)
	{
		if ((weight - 3*i) % 5 == 0)
		{
				ways.push_back(i + ((weight - 3 * i) / 5));
		}
	}

	sort(ways.begin(), ways.end());

	if (ways[0] == 5000)
		cout << -1;
	else
		cout << ways[0];
}
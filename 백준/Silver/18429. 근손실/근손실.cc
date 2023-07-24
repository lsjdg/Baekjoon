#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int days, loss, count{ 0 };
	cin >> days >> loss;
	vector<int> kits;
	for (int i{ 0 }; i < days; i++)
	{
		int x;
		cin >> x;
		kits.push_back(x);
	}
	vector<int> permu(days);
	for (int i{ 0 }; i < days; i++)
	{
		permu[i] = i;
	}
	do
	{
		bool isAble{ true };
		int m{ 500 };
		for (int i{ 0 }; i < days; i++)
		{
			m += kits[permu[i]];
			m -= loss;
			if (m < 500)
			{
				isAble = false;
				break;
			}
		}
		if (isAble) count++;
	} while (next_permutation(permu.begin(), permu.end()));

	cout << count;
}
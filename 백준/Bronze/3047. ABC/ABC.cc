#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int x;
	string s;
	vector<int> v;
	for (int i{ 0 }; i < 3; i++)
	{
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	cin >> s;
	for (int i{ 0 }; i < 3; i++)
	{
		char c = s[i];
		switch (c)
		{
		case 'A':
			cout << v[0] << ' ';
			break;
		case 'B':
			cout << v[1] << ' ';
			break;
		case 'C':
			cout << v[2] << ' ';
			break;
		}
	}
}
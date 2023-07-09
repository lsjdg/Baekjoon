#include <iostream>
#include <map>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int heard, seen, count{0};
	map <string, bool> list;
	cin >> heard >> seen;

	while (heard--)
	{
		string s;
		cin >> s;
		list.insert({ s, false });
	}

	while (seen--)
	{
		string s;
		cin >> s;
		if (list.find(s) != list.end() && !list.find(s)->second)
		{
			count++;
			list.find(s)->second = true;
		}
	}
	
	cout << count << '\n';
	for (auto pair : list)
	{
		if (pair.second)
			cout << pair.first << '\n';
	}
}
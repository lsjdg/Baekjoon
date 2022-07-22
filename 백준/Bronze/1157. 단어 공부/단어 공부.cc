#include <iostream>
#include <array>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string s;
	getline(cin, s);
	for (size_t i{ 0 }; i < s.size(); i++)
	{
		if (97 <= int(s[i]) && int(s[i]) <= 122)
		{
			s[i] -= 32;
		}
	}

	array <int, 26> frequency;
	for (int i{ 0 }; i < 26; i++)
	{
		frequency[i] = 0;
	}

	for (char c : s)
	{
		frequency[int(c) - 65]++;
	}

	array <int, 26> origin;
	for (int i{ 0 }; i < 26; i++)
	{
		origin[i] = frequency[i];
	}

	sort(frequency.begin(), frequency.end());
	int max = frequency[25];

	if (frequency[24] == frequency[25])
	{
		cout << '?';
	}
	else
	{
		for (int i{ 0 }; i < 26; i++)
		{
			if (origin[i] == max)
			{
				cout << char(i+65);
			}
		}
	}
}
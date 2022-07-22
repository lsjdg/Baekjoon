#include <iostream>
#include <string>

using namespace std;

int main()
{
	int count{ 0 }, space{0}, word{0};
	string s;
	getline(cin, s);
	
	for (char c : s)
	{
		if (c == ' ')
		{
			space++;
		}

		else if (c != ' ')
		{
			word++;
		}
	}

	
	if (word == 1)
	{
	cout << 1;
	}

	else if (space != 0 && word != 0)
	{
		for (size_t i{ 1 }; i < s.size() - 1; i++)
		{
			if (s[i] == ' ' && s[i - 1] != ' ' && s[i + 1] != ' ')
			{
				count++;
			}
		}
		if (count != 0)
		{
			cout << count + 1;
		}
		else
		{
			cout << 0;
		}
	}

	

	else if (space == 0 && word != 0)
	{
		cout << 1;
	}

	else if (space != 0 && word == 0)
	{
		cout << 0;
	}

	else if (space == 0 && word == 0)
	{
		cout << 0;
	}
}
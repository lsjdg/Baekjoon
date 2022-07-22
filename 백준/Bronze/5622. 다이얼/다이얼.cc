#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string s;
	getline(cin, s);
	vector <int> dial(s.size());
	for (size_t i{ 0 }; i < s.size(); i++)
	{
		char c = s[i];
		switch (c)
		{
		case 'A':
		case 'B':
		case 'C':
			dial[i] = 2;
			break;
		case 'D':
		case 'E':
		case 'F':
			dial[i] = 3;
			break;
		case 'G':
		case 'H':
		case 'I':
			dial[i] = 4;
			break;
		case 'J':
		case 'K':
		case 'L':
			dial[i] = 5;
			break;
		case 'M':
		case 'N':
		case 'O':
			dial[i] = 6;
			break;
		case 'P':
		case 'Q':
		case 'R':
		case 'S':
			dial[i] = 7;
			break;
		case 'T':
		case 'U':
		case 'V':
			dial[i] = 8;
			break;
		case 'W':
		case 'X':
		case 'Y':
		case 'Z':
			dial[i] = 9;
			break;
		}
	}

	int time{ 0 };
	for (int n : dial)
	{
		time += n + 1;
	}

	cout << time;
}
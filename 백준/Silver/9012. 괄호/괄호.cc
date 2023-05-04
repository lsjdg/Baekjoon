#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int test;
	cin >> test;
	while (test--)
	{
		stack<char> s;
		string str;
		cin >> str;
		bool isVps = 1;
		for (size_t i{ 0 }; i < str.size(); i++)
		{
			char c = str[i];
			if (c == '(')
				s.push(c);
			else
			{
				if (s.size() != 0 && s.top() == '(')
					s.pop();
				else
				{
					isVps = 0;
					break;
				}
			}
		}
		if (s.size() != 0)
			isVps = 0;
		if (isVps == 1)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
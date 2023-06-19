#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int count{ 0 }, stick{ 0 };
	stack<char> s;
	string str;
	cin >> str;

	for (size_t i{ 0 }; i < str.size(); i++)
	{
		char c = str[i];
		if (c == '(')
		{
			s.push(c);
			stick++;
		}
		else if (c == ')')
		{
			if (s.top() == '(')
			{
				count += --stick;
			}
			else
			{
				count++;
				stick--;
			}
			s.push(c);
		}
	}
	cout << count;
}
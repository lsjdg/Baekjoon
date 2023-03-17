#include <iostream>
using namespace std;

class Stack
{
private:
	char arr[10001]{};
	int size;
public:
	Stack()
	{
		this->size = 0;
	}
	bool empty()
	{
		return this->size == 0;
	}
	void push(char c)
	{
		arr[size] = c;
		size++;
	}
	void pop()
	{
		this->size--;
	}
	char top()
	{
		return arr[size - 1];
	}
};

bool isOper(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	else
		return false;
}
bool isNum(char c)
{
	if (c >= 65 && c <= 90)
		return true;
	else
		return false;
}
int main()
{
	Stack st;
	string s;
	cin >> s;
	for (int i{ 0 }; i < s.size(); i++)
	{
		char c = s[i];
		if (isNum(c))
		{
			cout << c;
		}
		else if (c == '(')
		{
			st.push(c);
		}
		else if (c == ')')
		{
			while (st.top() != '(')
			{
				cout << st.top();
				st.pop();
			}
			st.pop();
		}
		else if (isOper(c))
		{
			if (c == '+' || c == '-')
			{
				while (true)
				{
					if (st.empty())
						break;
					if (st.top() == '+' || st.top() == '-' ||
						st.top() == '*' || st.top() == '/')
					{
						cout << st.top();
						st.pop();
					}
					else
						break;

				}
				st.push(c);
			}
			if (c == '*' || c == '/')
			{
				while (true)
				{
					if (st.empty())
						break;
					if (st.top() == '*' || st.top() == '/')
					{
						cout << st.top();
						st.pop();
					}
					else
						break;
				}
				st.push(c);
			}
		}
	}
	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}
}
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	int size, x;
	bool isAble{ true };
	stack<int> s;
	queue<int> q;
	queue<char> result;

	cin >> size;
	for (int i{ 1 }; i <= size; i++)
	{
		q.push(i);
	}
	for (int i{ 0 }; i < size; i++)
	{
		cin >> x;
		if (s.size() != 0 && s.top() > x || x > size)
		{
			isAble = false;
		}
		else if (q.front() == x)
		{
			result.push('+');
			result.push('-');
			q.pop();
		}
		else if (!s.empty() && s.top() == x)
		{
			s.pop();
			result.push('-');
		}
		else if (q.front() < x)
		{
			while (!q.empty() && q.front() <= x)
			{
				s.push(q.front());
				result.push('+');
				q.pop();
			}
			s.pop();
			result.push('-');
		}
	}

	if (isAble)
	{
		while (!result.empty())
		{
			cout << result.front() << '\n';
			result.pop();
		}
	}
	else
		cout << "NO";
}
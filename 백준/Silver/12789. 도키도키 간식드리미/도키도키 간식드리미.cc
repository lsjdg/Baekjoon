#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	stack<int> s;
	queue<int> q;
	int ppl, x, count{1};
	cin >> ppl;
	for (int i{0}; i < ppl; i++)
	{
		cin >> x;
		q.push(x);
	}
	while (!q.empty())
	{
		if (q.front() == count)
		{
			count++;
			q.pop();
		}
		else if (q.front() > count)
		{
			if (s.size() != 0 && s.top() == count)
			{
				count++;
				s.pop();
			}
			else
			{
				s.push(q.front());
				q.pop();
			}
		}
	}
	bool isAble{ true };
	while (isAble && s.size() != 0)
	{
		if (s.top() == count)
		{
			count++;
			s.pop();
		}
		else
			isAble = false;
	}

	if (isAble)
		cout << "Nice\n";
	else
		cout << "Sad\n";
}
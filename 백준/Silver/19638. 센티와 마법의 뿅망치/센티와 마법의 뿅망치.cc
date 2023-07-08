#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int popu, centi, hammer, x;
	bool isAble {false};
	priority_queue<int> h;
	cin >> popu >> centi >> hammer;
	while (popu--)
	{
		cin >> x;
		h.push(x);
	}
	int count{ 0 };
	while (true)
	{
		if (h.top() == 1)
		{
			isAble = (centi == 1 ? false : true);
			break;
		}
		else if (h.top() < centi)
		{
			isAble = true;
			break;
		}
		if (count == hammer)
			break;
		int tallest = h.top();
		h.pop();
		int half = tallest / 2;
		count++;
		h.push(half);
	}
	if (isAble)
		cout << "YES\n" << count;
	else
		cout << "NO\n" << h.top();
}

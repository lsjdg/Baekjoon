#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	queue <int> circle;
	queue <int> answer;
	for (int i{ 1 }; i <= n; i++)
	{
		circle.push(i);
	}
	while (circle.size() > 0)
	{

		for (int i = 0; i < k - 1; i++) {

			circle.push(circle.front());
			circle.pop();
		}
		answer.push(circle.front());
		circle.pop();
	}

	cout << '<';
	for (int i{ 0 }; i < n - 1; i++)
	{
		cout << answer.front() << ", ";
		answer.pop();
	}
	cout << answer.front() << '>';
}
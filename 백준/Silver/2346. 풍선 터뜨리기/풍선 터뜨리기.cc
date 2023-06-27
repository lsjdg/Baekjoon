#include <iostream>
#include <vector>
using namespace std;
int s;

int move(int idx, int value)
{
	return (idx + value + s) % s;
}
int main()
{
	int arr[1000]{ 0 };
	bool visited[1000]{ false };
	int count{ 0 }, idx{ 0 };
	cin >> s;
	for (int i{ 0 }; i < s; i++)
	{
		int x;
		cin >> x;
		arr[i] = x;
	}
	while (true)
	{
		cout << idx + 1 << ' ';
		count++;
		if (count == s) break;
		visited[idx] = true;
		bool isPos = (arr[idx] > 0 ? true : false);
		int jump = abs(arr[idx]);
		int moveCount{ 0 };
		while (moveCount < jump)
		{
			idx = (isPos ? move(idx, 1) : move(idx, -1));
			if (!visited[idx])
				moveCount++;
		}
	}
}

#include <iostream>
using namespace std;

int main()
{
	long start{1}, end{1}, rounds{1};
	long target;
	cin >> target;
	while (1)
	{
		if (target <= end)
		{
			break;
		}
		start = end + 1;
		end += rounds * 6;
		rounds++;
	}

	cout << rounds;

}
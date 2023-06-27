#include <iostream>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, f, count{0};
	stack<int> guitar[7];
	cin >> n >> f;

	while (n--)
	{
		int note, fret;
		cin >> note >> fret;
		if (guitar[note].empty() || guitar[note].top() < fret)
		{
			guitar[note].push(fret);
			count++;
		}
		else if (guitar[note].top() > fret)
		{
			while (!guitar[note].empty() && guitar[note].top() > fret)
			{
				guitar[note].pop();
				count++;
			}
			if (!guitar[note].empty() && guitar[note].top() == fret)
				continue;
			guitar[note].push(fret);
			count++;
		}
	}
	cout << count;
}

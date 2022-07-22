#include <iostream>
#include <string>

using namespace std;

int main()
{
	int lines;
	cin >> lines;
	for (int i{ 0 }; i < lines; i++)
	{
		int reps;
		string s;
		cin >> reps >> s;

		for (char c : s)
		{
			for (int i{ 0 }; i < reps; i++)
			{
				cout << c;
			}
		}
		cout << endl;
	}
}

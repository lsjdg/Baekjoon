#include <iostream>
#include <array>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
	int lines;
	cin >> lines;
	cin.ignore(100, '\n');
	for (int i{ 0 }; i < lines; i++)
	{
		string answer;
		getline(cin, answer);

		int score{0};
		int streak{ 1 };
		for (size_t i{ 0 }; i < answer.size(); i++)
		{
			if (answer[i] == 'O')
			{
				score += streak;
				streak++;
			}
			if (answer[i] == 'X')
			{
				streak = 1;
			}
		}

		cout << score << endl;
	}
}
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
	for (int i{ 0 }; i < lines; i++)
	{
		int students, score;
		int sum{0};
		cin >> students;
		vector<int>scores(students);
		for (int i{ 0 }; i < students; i++)
		{
			cin >> score;
			sum += score;
			scores.push_back(score);
		}
		double average = static_cast<double>(sum) / students;
		
		int count{ 0 };
		for (int score : scores)
		{
			if (score > average)
			{
				count++;
			}
		}

		double ratio = static_cast<double>(count) / students * 100;
		cout << fixed << setprecision(3) << ratio << "%" << endl;
	}
}
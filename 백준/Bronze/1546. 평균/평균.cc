#include <iostream>
#include <array>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
	unsigned subjects;
	cin >> subjects;
	//cout << fixed << setprecision(2);

	vector <double> scores(subjects);
	for (int i{ 0 }; i < subjects; i++)
	{
		double score;
		cin >> score;
		scores[i] = score;
	}

	sort(scores.begin(), scores.end());
	double max{ scores[subjects - 1] };

	for (int i{ 0 }; i < subjects; i++)
	{
		double newScore = scores[i] / max * 100;
		scores[i] = newScore;
	}

	double sum{ 0 };
	for (double score : scores)
	{
		sum += score;
	}

	double average = sum / subjects;

	cout << average;
}
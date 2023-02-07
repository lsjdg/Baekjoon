#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double distance(int, int, int, int);
bool inCircle(int, int, int, int, int);
void printVector(vector<int>);
int main()
{
	int T, n, cX, cY, r;
	int startX, startY, endX, endY;
	vector <int> v;
	cin >> T;
	
	for (int i{ 0 }; i < T; i++)
	{
		n = 0;
		cin >> startX >> startY >> endX >> endY;
		int planets;
		cin >> planets;

		for (int j{ 0 }; j < planets; j++)
		{
			cin >> cX >> cY >> r;
			if (inCircle(startX, startY, cX, cY, r) 
				+ inCircle(endX, endY, cX, cY, r) == 1)
				n++;
		}
		v.push_back(n);
	}

	printVector(v);
}

double distance(int a, int b, int p, int q)
{
	double d;
	d = sqrt((a - p) * (a - p) + (b - q) * (b - q));
	return d;
}

bool inCircle(int a, int b, int p, int q, int r)
{
	if (distance(a, b, p, q) < r)
		return true;
	else
		return false;
}
void printVector(vector <int> v)
{
	for (int i{ 0 }; i < v.size(); i++)
	{
		cout << v[i] << '\n';
	}
}
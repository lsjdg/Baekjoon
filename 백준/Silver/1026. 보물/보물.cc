#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
	int n, sum{0};
	cin >> n;
	vector <int> A;
	vector <int> B;
	vector <int> reverseB;

	for (int i{ 0 }; i < n; i++)
	{
		int num;
		cin >> num;
		A.push_back(num);
	}
	for (int i{ 0 }; i < n; i++)
	{
		int num;
		cin >> num;
		B.push_back(num);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	for (int i{ 0 }; i < n; i++)
	{
		reverseB.push_back (B[n-i-1]);
	}

	for (int i{ 0 }; i < n; i++)
	{
		sum += A[i] * reverseB[i];
	}

	cout << sum;
}
#include <iostream>
using namespace std;

int main()
{
	int n, v, count=0;
	int arr[100];
	cin >> n;
	for (int i{0}; i<n; i++)
	{
		int x;
		cin >> x;
		arr[i] = x;
	}
	cin >> v;
	for (int i{ 0 }; i < n; i++)
	{
		if (arr[i] == v)
			count++;
	}
	cout << count;
}
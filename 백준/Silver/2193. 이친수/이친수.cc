#include <iostream>
using namespace std;

int main() 
{
	int N;
	long long pinaryNum[91];

	cin >> N;

	pinaryNum[0] = 0;
	pinaryNum[1] = 1;
	pinaryNum[2] = 1;

	for (int i { 3 }; i <= N; i++)
	{
		pinaryNum[i] = pinaryNum[i - 1] + pinaryNum[i - 2];
	}

	cout << pinaryNum[N];
}
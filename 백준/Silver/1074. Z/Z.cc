#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int r, c, order{0};

void divide(int n)
{
	if (n == 1)
		return;
	if (r < pow(2, n - 1) && c < pow(2, n - 1))
		divide(n - 1);
	else if (r < pow(2, n - 1) && c >= pow(2, n - 1))
	{
		c -= pow(2, n - 1);
		order += pow(pow(2, n - 1), 2);
		divide(n - 1);
	}
	else if (r >= pow(2, n - 1) && c < pow(2, n - 1))
	{
		r -= pow(2, n - 1);
		order += pow(pow(2, n - 1), 2) * 2;
		divide(n - 1);
	}
	else
	{
		c -= pow(2, n - 1);
		r -= pow(2, n - 1);
		order += pow(pow(2, n - 1), 2) * 3;
		divide(n - 1);
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n >> r >> c;
	divide(n);

	if (r == 0 && c == 0)
		order += 0;
	else if (r == 0 && c == 1)
		order += 1;
	else if (r == 1 && c == 0)
		order += 2;
	else if (r == 1 && c == 1)
		order += 3;

	cout << order;

}

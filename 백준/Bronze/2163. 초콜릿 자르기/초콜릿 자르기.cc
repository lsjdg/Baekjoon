#include <iostream>
using namespace std;

int cut(int, int);

int main()
{
	int n, m;
	cin >> n >> m;

	if (n >= m)
		cout << cut(n, m);
	else
		cout << cut(m, n);
}

int cut(int n, int m)
{
	if (n == 1 && m == 1)
		return 0;
	else if (n == 1 && m != 1)
		return m-1;
	else if (n != 1 && m == 1)
		return n-1;
	else
		return (n - 1) + (m-1) * n;
}
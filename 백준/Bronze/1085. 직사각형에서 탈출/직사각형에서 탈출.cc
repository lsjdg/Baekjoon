#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	
	int wx{ w - x };
	int hy{ h - y };
	
	array<int, 4> a {x, y, wx, hy};

	sort(a.begin(), a.end());
	cout << a[0];

}
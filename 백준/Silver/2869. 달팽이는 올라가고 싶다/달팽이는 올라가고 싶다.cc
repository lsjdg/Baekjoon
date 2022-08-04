#include <iostream>

using namespace std;

int main()
{
	unsigned up, down, height;
	cin >> up >> down >> height;

	unsigned daily = up - down;
	unsigned slip = height - up;

	if (slip <= 0)
		cout << 1;
	else if (slip <= daily)
		cout << 2;
	else
		if (slip % daily == 0)
			cout << slip / daily + 1;
		else
			cout << slip / daily + 2;
	
}
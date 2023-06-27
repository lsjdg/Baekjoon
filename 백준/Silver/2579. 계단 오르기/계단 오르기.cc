#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int h;
	cin >> h;
	int stairs[301]{0};
	int climbMax[301]{ 0 };
	int climbJump[301]{ 0 };

	for(int i{ 1 }; i <= h; i++)
	{
		int x;
		cin >> x;
		stairs[i] = x;
	}
	climbMax[1] = stairs[1];
	climbJump[1] = stairs[1];
	climbMax[2] = stairs[1] + stairs[2];
	climbJump[2] = stairs[2];
	
	for (int i{ 3 }; i <= 300; i++)
	{
		climbJump[i] = climbMax[i - 2] + stairs[i];
		climbMax[i] = max(climbJump[i - 1], climbMax[i - 2]) + stairs[i];
	}

	cout << climbMax[h];
}

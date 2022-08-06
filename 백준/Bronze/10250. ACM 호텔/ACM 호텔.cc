#include <iostream>

using namespace std;

int main()
{
	int reps;
	int floors, rooms, n;
	cin >> reps;
	
	for (int i{ 0 }; i < reps; i++)
	{
		cin >> floors >> rooms >> n;
		int floor = n % floors;
		int room = n / floors + 1;
		if (floor == 0)
		{
			floor += floors;
			room -= 1;
		}
			
		cout << floor * 100 + room << '\n';
	}
	
}
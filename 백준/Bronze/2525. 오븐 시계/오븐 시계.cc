#include <iostream>
using namespace std;

int main()
{
	int startHour, startMin, time, endHour, endMin;
	cin >> startHour >> startMin;
	cin >> time;

	endHour = startHour + (time + startMin) / 60;
	endMin = (time + startMin) % 60;

	if (endHour >= 24)
	{
		endHour -= 24;
	}

	cout << endHour << " " << endMin;
}
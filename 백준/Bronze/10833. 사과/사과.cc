#include <iostream>
using namespace std;

int main()
{
	int schools, sum{0};
	cin >> schools;

	for (int i{ 0 }; i < schools; i++)
	{
		int student, apple;
		cin >> student >> apple;
		sum += apple % student;
	}

	cout << sum;
}
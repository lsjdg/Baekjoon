#include <iostream>

using namespace std;

int main()
{
	int numOne, numTwo;
	cin >> numOne >> numTwo;
	int newOne, newTwo;
	newOne = 100 * (numOne % 10) + 10 * (numOne / 10 % 10) + numOne / 100;
	newTwo = 100 * (numTwo % 10) + 10 * (numTwo / 10 % 10) + numTwo / 100;

	if (newOne > newTwo)
		cout << newOne;
	else
		cout << newTwo;
}
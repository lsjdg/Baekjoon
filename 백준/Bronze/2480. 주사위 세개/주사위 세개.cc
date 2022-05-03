#include <iostream>
using namespace std;

int main()
{
	int num1, num2, num3;

	cin >> num1 >> num2 >> num3;

	if (num1 == num2 && num2 == num3)
	{
		cout << 10000 + 1000 * num1;
	}

	else if(num1 == num2)
	{
		cout << 1000 + 100 * num1;
	}

	else if (num2 == num3)
	{
		cout << 1000 + 100 * num2;
	}

	else if (num1 == num3)
	{
		cout << 1000 + 100 * num3;
	}

	else
	{
		if (num1 > num2 && num1 > num3)
		{
			cout << 100 * num1;
		}

		if (num2 > num1 && num2 > num3)
		{
			cout << 100 * num2;
		}

		if (num3 > num2 && num3 > num1)
		{
			cout << 100 * num3;
		}
	}
}
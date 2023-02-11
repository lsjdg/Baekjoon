#include <iostream>
#include <cmath>
using namespace std;


class Computer
{
private:
	int base;
	int power;

public:
	void setPower(int power)
	{
		this->power = power;
	}
	void setBase(int base)
	{
		this->base = base;
	}
	int getBase()
	{
		return this->base;
	}
	int getPower()
	{
		return this->power;
	}
	int getDigit(int base, int power)
	{
		if (power == 1 && base % 10 != 0)
			return base % 10;
		else if (power == 1 && base % 10 == 0)
			return 10;
		else
		{
		int digit = (getDigit(base, power - 1) * (base % 10)) % 10;
		if (digit != 0)
			return digit;
		if (digit == 0)
		return 10;
		}
	}
};


int main()
{
	int test;
	cin >> test;

	Computer* computer = new Computer[test];
	for (int i{ 0 }; i < test; i++)
	{
		int base, power;
		cin >> base >> power;
		computer[i].setBase(base % 10);
		computer[i].setPower(power);
	}

	for (int i{ 0 }; i < test; i++)
	{
		cout << computer[i].getDigit
		(computer[i].getBase(), computer[i].getPower()) << '\n';
	}
}
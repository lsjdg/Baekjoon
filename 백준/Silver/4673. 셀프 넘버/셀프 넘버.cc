#include <iostream>
#include <array>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

int kaprekar(int n);
int digitSum(int n);

int main()
{
	vector <int> numbers(10035);
	vector <int> nonSelfNumbers{0};
	for (int i{0}; i < 10035; i++)
	{
		numbers[i] = i + 1;
	}

	for (int i{ 1 }; i < 10000; i++)
	{
		bool inNumbers = binary_search(numbers.begin(), numbers.end(), kaprekar(i));
		if (inNumbers == true)
		{
			nonSelfNumbers.push_back(kaprekar(i));
		}
	}

	sort(nonSelfNumbers.begin(), nonSelfNumbers.end());

	for (int i{ 1 }; i <= 10000; i++)
	{
		bool inNonSelfNumbers = binary_search(nonSelfNumbers.begin(), nonSelfNumbers.end(), i);
		if (inNonSelfNumbers == false)
			cout << i << '\n';
	}
	
}

int digitSum(int n)
{
	int sum{ 0 };

	while (n != 0)
	{
		sum += n % 10;
		n /= 10;
	}

	return sum;
}

int kaprekar(int n)
{
	return n + digitSum(n);
}
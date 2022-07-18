#include <iostream>
#include <array>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int A, B, C;
	//cout << "input three integers: ";
	cin >> A >> B >> C;

	int product{ A * B * C };
	string s{ to_string(product) };
	array<unsigned, 10> frequency {0,0,0,0,0,0,0,0,0,0};
	size_t digit{ s.size() };
	vector<unsigned> num(digit);
	
	for (size_t i{ 0 }; i < digit; i++)
	{
		frequency[s[i] - 48]++;
	}

	for (int n : frequency)
	{
		cout << n << '\n';
	}
	

	
}
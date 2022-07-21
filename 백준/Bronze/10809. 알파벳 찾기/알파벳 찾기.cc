#include <iostream>
#include <array>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string s;
	getline(cin, s);
	
	array <int, 26> alphabets;
	for (int i{ 0 }; i < 26; i++)
	{
		alphabets[i] = -1;
	}

	for (size_t i{ 0 }; i < s.size(); i++)
	{
		if (alphabets[int(s[i]) - 97] == -1)
		{
			alphabets[int(s[i]) - 97] = i;
		}
	}

	for (int num : alphabets)
	{
		cout << num << " ";
	}
}

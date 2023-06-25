#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	int record;
	cin >> record;
	map <string, string> log;

	while (record--)
	{
		string name, entry;
		cin >> name >> entry;
		if (entry == "enter")
			log.insert({ name, name });
		else if (entry == "leave")
			log.erase(name);
	}

	for (auto iter = log.rbegin(); iter != log.rend(); iter++)
	{
		cout << iter->first << '\n';
	}
}
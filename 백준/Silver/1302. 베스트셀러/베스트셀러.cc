#include <iostream>
#include <map>
using namespace std;

int main()
{
	int book;
	cin >> book;
	map <string, int> log;

	while (book--)
	{
		string name;
		cin >> name;
		if (log.find(name) == log.end())
			log.insert({ name, 1 });
		else
			log.find(name)->second++;
	}

	int max{ 0 };
	auto iter = log.begin();
	auto maxIter = log.begin();
	for (iter; iter != log.end(); iter++)
	{
		if (iter->second > max)
		{
			max = iter->second;
			maxIter = iter;
		}
	}
	cout << maxIter->first;
}
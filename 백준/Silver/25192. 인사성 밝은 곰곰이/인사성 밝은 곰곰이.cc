#include <iostream>
#include <map>
using namespace std;

int main()
{
	int chat, count{0};
	map <string, int> log;
	cin >> chat;
	while (chat--)
	{
		string s;
		cin >> s;
		if (s == "ENTER")
		{
			log.clear();
		}
		else if (log.size() == 0 || log.find(s) == log.end())
		{
			log.insert({ s, 0 });
			count++;
		}
		else
		{
			log.find(s)->second = 1;
		}
	}
	cout << count;
}
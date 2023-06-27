#include <iostream>
#include <map>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int site, test;
	string address, pw, target;
	cin >> site >> test;
	map <string, string> log;

	while (site--)
	{
		cin >> address >> pw;
		log.insert({ address, pw });
	}
	while (test--)
	{
		cin >> target;
		cout << log.find(target)->second << '\n';
	}
}

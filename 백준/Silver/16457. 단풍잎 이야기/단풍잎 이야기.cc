#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int key, quest, skill, x;
	cin >> key >> quest >> skill;
	vector<vector<int>> questList;
	vector<int> skillList;
	for (int i{ 1 }; i <= 2 * key; i++)
	{
		skillList.push_back(i);
	}
	for (int i{ 0 }; i < quest; i++)
	{
		vector<int> v;
		for (int j{ 0 }; j < skill; j++)
		{
			cin >> x;
			v.push_back(x);
		}
		questList.push_back(v);
	}

	vector<bool> comb(2 * key, false);
	int maxQuest{ 0 };
	for (int i { 0 }; i < key; i++)
	{
		comb[i] = true;
	}
	do
	{
		int count{ 0 };
		vector<int> possible;
		for (int i { 0 }; i < 2 * key; i++)
		{
			if (comb[i])
				possible.push_back(skillList[i]);
		}
		for (auto vec : questList)
		{
			bool questCompleted {true};
			for (auto skillNum : vec)
			{
				if (find(possible.begin(), possible.end(), skillNum) == possible.end())
				{
					questCompleted = false;
					break;
				}
			}
			if (questCompleted)
				count++;
		}
		maxQuest = max(maxQuest, count);
	} while (prev_permutation(comb.begin(), comb.end()));

	cout << maxQuest;
}

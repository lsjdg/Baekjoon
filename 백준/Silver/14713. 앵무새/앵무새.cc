#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int parrots, count{ 0 };
    bool isAble{ true };
    cin >> parrots;
    vector<queue<string>> v(parrots);
    cin.ignore();

    for (int i{ 0 }; i < parrots; i++)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string word;
        while (ss >> word)
        {
            v[i].push(word);
            count++;
        }
    }

    int wordCount{ 0 };
    vector<string> result;
    string sent;
    getline(cin, sent);
    stringstream ss(sent);
    string word;
    while (ss >> word)
    {
        result.push_back(word);
        wordCount++;
    }

    for (auto& word : result)
    {
        bool found{ false };
        for (auto& q : v)
        {
            if (!q.empty() && word == q.front())
            {
                q.pop();
                found = true;
                break;
            }
        }
        if (!found)
            isAble = false;
    }

    if (!isAble || count != wordCount)
        cout << "Impossible";
    else
        cout << "Possible";
}

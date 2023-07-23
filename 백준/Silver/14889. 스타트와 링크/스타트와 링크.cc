#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n, minDiff{ 40000 };
vector<vector<int>> v;

int calc(vector<int>& vec)
{
    int result{ 0 };
    for (int i{ 0 }; i < vec.size(); i++)
    {
        for (int j = i + 1; j < vec.size(); j++)
        {
            result += (v[vec[i]][vec[j]] + v[vec[j]][vec[i]]);
        }
    }
    return result;
}

int main()
{
    cin >> n;
    v.resize(n, vector<int>(n));

    for (int i{ 0 }; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    vector<int> players(n);
    for (int i{ 0 }; i < n; i++)
    {
        players[i] = i;
    }

    vector<bool> comb(n, false);
    for (int i{ n / 2 }; i < n; i++)
    {
        comb[i] = true;
    }

    do
    {
        vector<int> start, link;
        for (int i{ 0 }; i < n; i++)
        {
            if (comb[i])
            {
                start.push_back(i);
            }
            else
            {
                link.push_back(i);
            }
        }
        int diff = abs(calc(start) - calc(link));
        minDiff = min(minDiff, diff);
    } while (next_permutation(comb.begin(), comb.end()));

    cout << minDiff;
}

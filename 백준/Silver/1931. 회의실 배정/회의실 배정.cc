#include <iostream>
#include <set>
using namespace std;

struct Compare
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const
    {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    }
};

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int meetings, start, end, count{ 0 };
    cin >> meetings;
    multiset<pair<int, int>, Compare> timeTable;

    for (int i{ 0 }; i < meetings; i++)
    {
        cin >> start >> end;
        timeTable.insert(make_pair(start, end));
    }

    int endTime{ 0 };
    for (auto meeting : timeTable)
    {
        if (meeting.first >= endTime)
        {
            count++;
            endTime = meeting.second;
        }
    }

    cout << count;

    return 0;
}

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int time, score{ 0 };
    stack<pair<int, int>> task;
    cin >> time;
    while (time--)
    {
        int n, s, t;
        cin >> n;
        if (n != 0)
        {
            cin >> s >> t;
            task.push({ s, t });
        }
        if (!task.empty())
        {
            task.top().second--;
            if (task.top().second == 0)
            {
                score += task.top().first;
                task.pop();
            }
        }
    }
    cout << score;
    return 0;
}

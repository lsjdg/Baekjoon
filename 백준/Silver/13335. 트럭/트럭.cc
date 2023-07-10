#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int truck, len, max, count{ 0 }, time{ 0 };
    int weight{ 0 }, crossing{ 0 };
    queue<int> wait;
    queue<pair<int, int>> bridge;
    cin >> truck >> len >> max;

    for (int i{ 0 }; i < truck; i++)
    {
        int x;
        cin >> x;
        wait.push(x);
    }

    while (count < truck)
    {
        if (!bridge.empty() && time - bridge.front().second == len)
        {
            weight -= bridge.front().first;
            bridge.pop();
            crossing--;
            count++;
        }

        if (!wait.empty() && weight + wait.front() <= max && crossing < len)
        {
            bridge.push({ wait.front(), time } );
            weight += wait.front();
            wait.pop();
            crossing++;
        }

        time++;
    }

    cout << time;
}

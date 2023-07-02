#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int target, d;
int stone[10001];
vector<int> graph[10001];
bool visited[10001];
bool arrive{ false };

void bfs(int v)
{
    queue<pair<int, int>> q;
    q.push({ v, 0 });
    visited[v] = true;

    while (!q.empty())
    {
        int top = q.front().first;
        int depth = q.front().second;
        q.pop();

        if (top == target)
        {
            arrive = true;
            d = depth;
            return;
        }

        for (auto i : graph[top])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push({ i, depth + 1 });
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, x, start;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        stone[i] = x;
    }
    cin >> start >> target;

    if (start == target)
    {
        cout << 0;
    }
    else if ((start - target) % stone[start] == 0)
    {
        cout << 1;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i != j && (j - i) % stone[i] == 0)
                {
                    graph[i].push_back(j);
                }
            }
        }

        bfs(start);

        if (arrive)
        {
            cout << d;
        }
        else
        {
            cout << -1;
        }
    }
}

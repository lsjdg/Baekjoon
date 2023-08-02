#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int target;
int dp[1000001];

void bfs(int x)
{
    queue<int> q;
    q.push(x);
    dp[x] = 0;

    while (!q.empty())
    {
        int top = q.front();
        q.pop();

        if (top == 1)
            return;

        if (top % 3 == 0 && dp[top / 3] == 0)
        {
            q.push(top / 3);
            dp[top / 3] = dp[top] + 1;
        }
        if (top % 2 == 0 && dp[top / 2] == 0)
        {
            q.push(top / 2);
            dp[top / 2] = dp[top] + 1;
        }
        if (dp[top - 1] == 0)
        {
            q.push(top - 1);
            dp[top - 1] = dp[top] + 1;
        }
    }
}

int main()
{
    cin >> target;
    bfs(target);
    cout << dp[1];
}

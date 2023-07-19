#include <iostream>
using namespace std;

int city, start, minCost{ 10000001 };
int w[10][10]{ 0 };
bool visited[10]{ false };

void dfs(int x, int count, int sum)
{
    if (count == city && x == start)
    {
        if (minCost > sum)
            minCost = sum;
        return;
    }
    for (int i{ 0 }; i < city; i++)
    {
        if (w[x][i] == 0)
            continue;
        else if (!visited[i])
        {
            visited[i] = true;
            sum += w[x][i];

            if (sum <= minCost)
                dfs(i, count + 1, sum);

            visited[i] = false;
            sum -= w[x][i];
        }
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int cost, x;
    cin >> city;
    for (int i{ 0 }; i < city; i++)
    {
        for (int j{ 0 }; j < city; j++)
        {
            cin >> x;
            w[i][j] = x;
        }
    }

    start = 0;
    dfs(0, 0, 0);
    cout << minCost;
}

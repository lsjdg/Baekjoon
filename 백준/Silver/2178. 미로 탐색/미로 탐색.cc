#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector <vector<int>> graph(n, vector<int>(m, 0));
    vector <vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        string tae;
        cin >> tae;
        for (int j = 0; j < m; j++) {
            graph[i][j] = tae[j] - '0';
        }
    }

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visited[0][0] = true;

    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, 1, 0, -1 };

    while (!q.empty()) {
        pair<int, int> top = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = top.first + dx[i];
            int nextY = top.second + dy[i];

            if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n)
                continue;
            if (graph[nextY][nextX] == 1 && !visited[nextY][nextX]) {
                graph[nextY][nextX] = graph[top.second][top.first] + 1;
                visited[nextY][nextX] = true;
                q.push(make_pair(nextX, nextY));
            }
        }
    }

    cout << graph[n - 1][m - 1];
}

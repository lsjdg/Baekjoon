#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<int> graph[1001];
bool visited[1001];

void dfs(int x) {
    cout << x << ' ';
    visited[x] = true;
    for (auto p : graph[x]) {
        if (!visited[p])
            dfs(p);
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        cout << top << ' ';
        for (auto p : graph[top]) {
            if (!visited[p]) {
                q.push(p);
                visited[p] = true;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int m, start, x, y;
    cin >> n >> m >> start;

    while (m--) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i = 1; i <= n; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(start);
    cout << '\n';

    fill(visited, visited + 1001, false);

    bfs(start);
    cout << '\n';

}

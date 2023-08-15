#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> graph[101];
bool visited[101];

bool bfs(int start, int target) {
    queue<int> q;
    int levels[101] { 0 };
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        for (auto p : graph[top]) {
            if (p == target)
                return true;
            if (!visited[p]) {
                q.push(p);
                visited[p] = true;
            }
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;
    vector<vector<bool>> v(n, vector<bool>(n));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            bool b;
            cin >> b;
            if (b)
                graph[i].push_back(j);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            v[i - 1][j - 1] = bfs(i, j);
            for (int k = 0; k < 101; k++) {
                visited[k] = false;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
}

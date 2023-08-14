#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[101];
bool visited[101];
int bacon[101];

void bfs(int start) {
    queue<pair<int, int>> q;
    int levels[101] { 0 };
    q.push(make_pair(start, 0));
    visited[start] = true;
    while (!q.empty()) {
        int top = q.front().first;
        int depth = q.front().second;
        levels[depth]++;
        q.pop();
        for (auto p : graph[top]) {
            if (!visited[p]) {
                q.push(make_pair(p, depth + 1));
                visited[p] = true;
            }
        }
    }

    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        sum += i * levels[i];
    }
    bacon[start] = sum;
}

int main() {
    int n, m;
    cin >> n >> m;

    while (m--) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            visited[j] = false;
        }
        bfs(i);
    }

    int minBacon = bacon[1];
    int minIdx = 1;
    for (int i = 2; i <= n; i++) {
        if (bacon[i] < minBacon) {
            minBacon = bacon[i];
            minIdx = i;
        }
    }

    cout << minIdx;
}

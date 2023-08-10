#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[1001];
bool visited[1001];

void dfs(int x) {
    visited[x] = true;
    for (auto p : graph[x]) {
        if (!visited[p]) {
            dfs(p);
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, x, y;
    cin >> n >> m;

    while (m--) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int count{ 0 };
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }

    cout << count;
}

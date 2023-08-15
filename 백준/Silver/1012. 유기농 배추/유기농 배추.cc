#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<bool>> field;
vector<vector<bool>> visited;

void dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || !field[x][y] || visited[x][y])
        return;
    visited[x][y] = true;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

int main() {
    int test, worm;
    cin >> test;
    while (test--) {
        cin >> n >> m >> worm;
        field.assign(n, vector<bool>(m, false));
        visited.assign(n, vector<bool>(m, false));

        while (worm--) {
            int x, y;
            cin >> x >> y;
            field[x][y] = true;
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && field[i][j]) {
                    dfs(i, j);
                    count++;
                }
            }
        }

        cout << count << '\n';
    }
}

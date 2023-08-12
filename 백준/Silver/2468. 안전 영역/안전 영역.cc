#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& temp, vector<vector<bool>>& visited, int x, int y, int n) {
	if (x < 0 || x >= n || y < 0 || y >= n || visited[x][y] || temp[x][y] == 0)
		return;
	visited[x][y] = true;
	dfs(temp, visited, x + 1, y, n);
	dfs(temp, visited, x - 1, y, n);
	dfs(temp, visited, x, y + 1, n);
	dfs(temp, visited, x, y - 1, n);
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n));

	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			if (x > max)
				max = x;
			v[i][j] = x;
		}
	}

	int maxCount = 0;
	for (int h = 0; h <= max; h++) {
		vector<vector<int>> temp = v;
		vector<vector<bool>> visited(n, vector<bool>(n, false));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (temp[i][j] <= h)
					temp[i][j] = 0;
			}
		}

		int count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j] && temp[i][j] != 0) {
					dfs(temp, visited, i, j, n);
					count++;
				}
			}
		}

		if (count > maxCount)
			maxCount = count;
	}

	cout << maxCount;
}

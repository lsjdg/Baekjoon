#include <iostream>
#include <vector>

using namespace std;
int answer[10];
int cnt = 0;

bool check(string s) {
    int n = 0;
    for (int i = 0; i < 10; i++) {
        if ((s[i] - '0') == answer[i])
            n++;
    }
    return n >= 5;
}

void solve(int idx, string s) {
    if (idx == 10) {
        if (check(s))
            cnt++;
        return;
    }

    for (int i = 1; i <= 5; i++) {
        if (s.size() >= 2 && s[s.size() - 1] == i + '0' && s[s.size() - 2] == i + '0') {
            continue;
        }
        s.push_back(i + '0');
        solve(idx + 1, s);
        s.pop_back();
    }
}


int main() {
    for (int i = 0; i < 10; i++) {
        cin >> answer[i];
    }
    solve(0, "");
    cout << cnt;
}


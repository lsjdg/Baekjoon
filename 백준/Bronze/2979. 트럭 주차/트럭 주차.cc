#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    b *= 2;
    c *= 3;
    vector<int> cnt(101, 0);
    int cost = 0;

    for (int i = 0; i < 3; i++) {
        int in, out;
        cin >> in >> out;
        for (int j = in; j < out; j++) {
            cnt[j]++;
        }
    }

    for (int i = 1; i <= 100; i++) {
        switch (cnt[i]) {
            case 1:
                cost += a;
                break;
            case 2:
                cost += b;
                break;
            case 3:
                cost += c;
                break;
        }
    }

    cout << cost;
}

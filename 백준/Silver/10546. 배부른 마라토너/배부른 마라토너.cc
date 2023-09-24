#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> runLog;

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        runLog[name]++;
    }

    for (int i = 0; i < n - 1; i++) {
        string name;
        cin >> name;
        runLog[name]--;
    }

    for (const auto& entry : runLog) {
        if (entry.second > 0) {
            cout << entry.first << endl;
            break;
        }
    }
}

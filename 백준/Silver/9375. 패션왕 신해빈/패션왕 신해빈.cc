#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int test;
    cin >> test;

    while (test--) {
        int n;
        cin >> n;
        map<string, int> clothes;
        for (int i = 0; i < n; i++) {
            string name, type;
            cin >> name >> type;
            clothes[type]++;
        }

        int result = 1;
        for (auto it = clothes.begin(); it != clothes.end(); it++) {
            result *= (it->second + 1);
        }
        result -= 1;

        cout << result << '\n';
    }
}

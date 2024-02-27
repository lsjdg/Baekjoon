#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    int size, question;
    cin >> size >> question;
    unordered_map<string, int> byName;
    unordered_map<int, string> byId;

    for (int i = 1; i <= size; i++) {
        string s;
        cin >> s;
        byName[s] = i;
        byId[i] = s;
    }

    while (question--){
        string s;
        cin >> s;
        stringstream ss(s);
        int n;
        if (ss >> n){
            cout << byId[n] << '\n';
        }else{
            cout << byName[s] << '\n';
        }
    }
}

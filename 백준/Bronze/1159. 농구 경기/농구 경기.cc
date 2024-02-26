#include <iostream>

using namespace std;

int main(){
    int players;
    int charCnt[26] = {0};
    cin >> players;

    while(players--){
        string s;
        cin >> s;
        charCnt[s[0] - 'a']++;
    }

    int cnt = 0;
    for (int i = 0; i<26; i++){
        if (charCnt[i] >= 5){
            cnt++;
            cout << (char)('a' + i);
        }
    }
    if (cnt == 0)
        cout << "PREDAJA";
}
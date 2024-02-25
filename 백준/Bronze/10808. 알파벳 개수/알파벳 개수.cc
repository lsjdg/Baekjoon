#include <iostream>
#include <string>

using namespace std;

int main(){
    int cnt[26] = {0};
    string s;
    cin >> s;
    for (size_t i = 0; i<s.size(); i++){
        cnt[s[i] - 'a']++;
    }
    for (auto n : cnt){
        cout << n << ' ';
    }
}
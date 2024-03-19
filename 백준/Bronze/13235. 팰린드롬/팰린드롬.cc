#include <iostream>

using namespace std;

string s;

bool isPalindrome(int i, int j){
    if (i >= j)
        return true;
    if (s[i] == s[j]){
        return isPalindrome(i+1, j-1);
    }else{
        return false;
    }
}

int main(){
    cin >> s;
    cout << (isPalindrome(0, s.size() - 1) ? "true" : "false");
}
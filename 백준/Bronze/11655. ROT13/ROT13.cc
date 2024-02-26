#include <iostream>
#include <string>

using namespace std;

char rot(char c) {
    int start;
    if (c >= 'A' && c <= 'Z') {
        start = 'A';
    } else if (c >= 'a' && c <= 'z') {
        start = 'a';
    } else {
        return c;
    }

    int n = (int) c;
    n -= start;
    n += 13;
    n %= 26;
    n += start;

    return (char) n;
}

int main() {
    string s;
    getline(cin, s);
    for (size_t i = 0; i < s.size(); i++) {
        cout << rot(s[i]);
    }
}
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

char rot(char c) {
    if (isalpha(c)) {
        char start = isupper(c) ? 'A' : 'a';
        return (c - start + 13) % 26 + start;
    }
    return c;
}

int main() {
    string s;
    getline(cin, s);
    for (char c : s) {
        cout << rot(c);
    }
}

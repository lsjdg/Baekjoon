#include <iostream>
#include <vector>

using namespace std;

int n, m, cnt[9];
vector<int> seq;

void fun(){
    if (seq.size() == m){
        for (int i : seq)
            cout << i << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i<= n; i++){
        seq.push_back(i);
        cnt[i]++;
        if (cnt[i] == 1)
            fun();
        seq.pop_back();
        cnt[i]--;
    }
}

int main(){
    cin >> n >> m;
    fun();
}
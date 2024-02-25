#include <iostream>
#include <vector>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    b *= 2;
    c *= 3;
    int cnt = 0, time = 1, cost = 0;
    vector<pair<int, int>> trucks;
    for (int i = 0; i<3; i++){
        int in, out;
        cin >> in >> out;
        trucks.push_back(make_pair(in, out));
    }
    while (time <= 100){
        for (int i = 0; i<3; i++){
            if (time == trucks[i].first)
                cnt++;
            if (time == trucks[i].second)
                cnt--;
        }
        switch (cnt) {
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
        time++;
    }

    cout << cost;
}
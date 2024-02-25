#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, sum = 0;
    vector<int> nums;
    vector<int> answer;
    for (int i = 0; i<9; i++){
        cin >> n;
        sum += n;
        nums.push_back(n);
    }
    int diff = sum - 100;
    int delIdxOne, delIdxTwo;
    bool found = false;

    for (delIdxOne = 0; delIdxOne<9; delIdxOne++){
        for (delIdxTwo = delIdxOne + 1; delIdxTwo<9; delIdxTwo++){
            if (nums[delIdxOne] + nums[delIdxTwo] == diff){
                found = true;
                break;
            }
        }
        if (found)
            break;
    }

    for (int i = 0; i<9; i++){
        if (i != delIdxOne && i != delIdxTwo){
            answer.push_back(nums[i]);
        }
    }

    sort(answer.begin(), answer.end());
    for (auto n : answer){
        cout << n << '\n';
    }
}

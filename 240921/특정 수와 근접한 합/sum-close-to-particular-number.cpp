#include <iostream>
#include <vector>
using namespace std;

int N;
int S;
int sum = 0;
int ans = 0;
vector<int> arr(1000, 0);

void sol(vector<int>& combination, int start) {
    if(combination.size() == 2) {
        int num1 = combination[0];
        int num2 = combination[1];
        int curSum = sum - num1 - num2;
        if(abs(S - ans) > abs(S - curSum)) {
            ans = curSum;
        }
        return;
    }

    for(int i = start; i < N; i++) {
        combination.push_back(arr[i]);
        sol(combination, i + 1);
        combination.pop_back();
    }
}

int main() {
    cin >> N >> S;
    vector<int> combination;

    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        arr[i] = num;
        sum += num;
    }

    sol(combination, 0);

    cout << abs(S - ans);

    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> arr;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
        sort(arr.begin(), arr.end());

        if(i % 2 == 0 || i == 0) {
            cout << arr[(arr.size() - 1) / 2] << " ";
        }
    }
    return 0;
}
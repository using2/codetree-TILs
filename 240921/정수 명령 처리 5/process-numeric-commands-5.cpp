#include <iostream>
#include <vector>
using namespace std;

class DynamicArray {
public:
    vector<int> arr;

    DynamicArray() {}

    void push(int num) {
        arr.push_back(num);
    }

    void pop() {
        arr.pop_back();
    }

    int size() {
        return arr.size();
    }

    int get(int k) {
        return arr[k - 1];
    }
};

int main() {
    int N; 
    cin >> N;
    DynamicArray arr;
    while(N--) {
        string arg;
        int arg2;
        cin >> arg;

        if(arg == "push_back") {
            cin >> arg2;
            arr.push(arg2);
        }

        if(arg == "pop_back") {
            arr.pop();
        }

        if(arg == "size") {
            cout << arr.size() << "\n";
        }

        if(arg == "get") {
            cin >> arg2;
            cout << arr.get(arg2) << "\n";
        }
    }
    return 0;
}
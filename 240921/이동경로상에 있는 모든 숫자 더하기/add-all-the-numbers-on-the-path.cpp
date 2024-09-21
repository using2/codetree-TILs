#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, argCnt;
    string args;
    int result = 0;

    cin >> n >> argCnt;
    cin >> args;

    vector<vector<int>> arr(n, vector<int>(n, 0));	

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int x = (n - 1) / 2;
    int y = x;

    int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int directIdx = 0;

    result += arr[x][y];

    for (int i = 0; i < args.length(); i++) {
        switch (args[i]) {
            case 'R':
                directIdx = (directIdx + 1) % 4;
                break;
            case 'L':
                directIdx = (directIdx + 3) % 4;
                break;
            case 'F': 
                int newX = x + direction[directIdx][0];
                int newY = y + direction[directIdx][1];
                
                if (newX >= 0 && newX < n && newY >= 0 && newY < n) {
                    x = newX;
                    y = newY;
                    result += arr[x][y];
                }
                break;
        }
    }

    cout << result << endl;

    return 0;
}
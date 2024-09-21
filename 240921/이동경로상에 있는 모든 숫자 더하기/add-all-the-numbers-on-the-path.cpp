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

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int score;
            cin >> score;
            arr[i][j] = score;
        }
    }

    int x = (n - 1)/2;
    int y = x;
    int direction[4][2] = {{0, -1}, {1, 0}, {-1, 0}, {-1, 0}};
    int directIdx = 0;

    result += arr[x][y];

    int curDx = 0, curDy = 0;

    for(int i = 0; i < args.length(); i++) {
        switch(args[i]) {
            case 'R':
                directIdx = (++directIdx) % 4;
                break;
            case 'F':
                curDx = direction[directIdx][0];
                curDy = direction[directIdx][1];
                if((x + curDx > -1) && (x + curDx < n) && (y + curDy > -1) && (y + curDy < n)) {
                    x += curDx;
                    y += curDy;
                    result += arr[y][x];
                }
                break;
            case 'L': 
                directIdx = (directIdx + 3) % 4;
                break;
        }
    }

    cout << result;

    return 0;
}
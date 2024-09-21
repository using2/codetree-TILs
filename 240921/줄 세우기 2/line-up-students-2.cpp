#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    int height;
    int weight;
    int index;
};

bool comp(const Student& a, const Student& b) {
    if (a.height == b.height) {
        return a.weight > b.weight; 
    }
    return a.height < b.height;
}

int main() {
    int N;
    cin >> N;

    vector<Student> students(N);

    for (int i = 0; i < N; i++) {
        cin >> students[i].height >> students[i].weight;
        students[i].index = i + 1; 
    }

    sort(students.begin(), students.end(), comp);

    for (const auto& student : students) {
        cout << student.height << " " << student.weight << " " << student.index << "\n";
    }

    return 0;
}
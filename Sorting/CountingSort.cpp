#include <iostream>
#include <vector>
using namespace std;

vector <int> countingSort (vector <int> arr) {
    vector <int> count ;
    for (int i = 0; i<100; i++) {
        count.push_back((0));
    }
    for (int x:arr) {
        count[x] ++;
    }
    vector <int> result;
    for (int i = 0; i < 100; i++) {
        if (count[i] == 0) continue;
        for (int j = 0; j < count[i]; j++) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    vector <int> arr = {63,25,73,1,98,73,56,84,86,57,16,83,8,25,81,56,9,53,98,67,99,12,83,89,80,91};
    vector <int> sorted = countingSort(arr);
    for (int x: sorted) {
        cout << x << " ";
    }

    return 225;
}
#include <iostream>
#include <vector>
using namespace std;

vector <int> quicksort(vector <int> arr ) {
    int p = arr[0];
    vector <int> left, right;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < p) {
            left.push_back(arr[i]);
        } else if (arr[i] > p) {
            right.push_back(arr[i]);
        }
    }
    left.push_back(p);
    for (int x: right) {
        left.push_back(x);
    }
    return left;
}

int main() {
    vector <int> arr = {4,5,3,7,2};
    vector <int> sorted = quicksort(arr);
    for (int x: sorted) {
        cout << x << " ";
    }
    return 0;
}
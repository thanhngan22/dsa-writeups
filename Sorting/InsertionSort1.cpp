#include <bits/stdc++.h>
using namespace std;

void InsertionSort1(int N, vector <int> arr) {
    int v = arr[N-1];
    int i = N-2;
    while (i >=0 && arr[i] > v){
        arr[i+1] = arr[i];
        i--;
        for (int j = 0; j < arr.size(); j++) {
            cout << arr[j] << " ";
        }
        cout << endl;
    }
    arr[i+1] = v;
    for (int j = 0; j < arr.size(); j++) {
        cout << arr[j] << " ";
    }
}

int main() {
    int N = 5;
    vector <int> arr = {2, 4, 6, 8, 3};
    InsertionSort1(N, arr);
    return 225;

}
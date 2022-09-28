// calculate the number of shifts it will take to sort the array

#include <iostream>
using namespace std;

int runningTime(int arr[], int n) {
    int count = 0;
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1]) {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << runningTime(arr, n) << endl;
    return 0;
}
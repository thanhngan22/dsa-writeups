// write heapify function and heap sort function 

#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void heapify(int a[], int n, int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && r <n) {
        if (a[l] > a[r]) {
            if (a[l] > a[i]) {
                swap(a[l], a[i]);
            }
        } else {
            if (a[r] > a[i]) {
                swap(a[r], a[i]);
            }
        }
    } else {
        if (l < n) {
            if (a[l] > a[i]) {
                swap(a[l], a[i]);
            }
        }
    }
}

void heapSort(int a[], int n){
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(a,n,i);
    }
    for (int i = n-1; i >= 0; i--) {
        swap(a[0], a[i]);
        heapify(a,i,0);
    }
}


int main() {
    int arr[] = {1, 12, 9, 5, 6, 10};

    heapSort(arr, 6);

    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }

    return 225;
}
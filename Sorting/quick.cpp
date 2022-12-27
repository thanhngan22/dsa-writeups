#include <bits/stdc++.h>
using namespace std;


int partition(int *a, int l, int r) {
    int pivot = a[r];   // chọn pivot là phần tử cuối
    int i = l;
    int j = r - 1;
    while (true) {
        while (i < r && a[i] <= pivot) i++;
        while (j > 0 && a[j] > pivot ) j--;
        if (i >= j) {
            break;
        }
        swap(a[i], a[j]);
        i++;
        j--;
    }
    swap(a[i], a[r]);
    return i;
}


void quickSort(int *a, int l, int r) {
    if (l < r) {
        int index = partition(a, l, r);
        quickSort(a, l, index - 1);
        quickSort(a, index + 1, r);
    }
}



int main() {
    int a[] = {25,37,22,5,2003,17,5,1972,13,4,1999,11,4,2011,1,1,1977};
    int n = sizeof(a)/sizeof(int);
    
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    quickSort(a,0, n-1);
    
    for (int i = 0; i < n ; i++) {
        cout << a[i] << " "; 
    }
    cout << endl;

    return 225;

}
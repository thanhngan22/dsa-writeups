#include <bits/stdc++.h>
using namespace std;


// build max heap 
void rebuildHeap(int *a, int n, int k) {
    int max = k;
    int l = 2*k + 1;
    int r = 2*k + 2;
    if (l < n ) {
        if (a[l] > a[k]) {
            max = l;
        }
        if (r < n) {
            if (a[r] > a[max]) {
                max = r;
            }
        }
        if (max != k) {
            swap(a[max], a[k]);
            rebuildHeap(a, n, max);
        }
    }
}


void heapSort(int *a, int n) {
    // heap construct
    for (int i = (n-1)/2; i >= 0; i--) {
        rebuildHeap(a,n,i);
    }

    // hoán đổi max về cuối và rebuildHeap 
    for (int i = n -1; i > 0; i--) {
        swap(a[0], a[i]);
        rebuildHeap(a, i , 0);
    }

}




int main() {
    int a[] = {25,37,22,5,2003,17,5,1972,13,4,1999,11,4,2011,1,1,1977};
    int n = sizeof(a)/sizeof(int);
    
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    heapSort(a,n);
    
    for (int i = 0; i < n ; i++) {
        cout << a[i] << " "; 
    }
    cout << endl;

    return 225;

}
#include <bits/stdc++.h>
using namespace std;

void selection (int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(a[i], a[min]);
        }
    }
}

int main() {
    int a[] = {25,37,22,5,2003,17,5,1972,13,4,1999,11,4,2011,1,1,1977};
    int n = sizeof(a)/sizeof(int);
    
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    selection(a,n);
    
    for (int i = 0; i < n ; i++) {
        cout << a[i] << " "; 
    }
    cout << endl;

    return 225;
}
// test qsock function
#include <bits/stdc++.h>
using namespace std;

int compare(const void *a, const void* b) {
    // nếu cần sắp xếp thì return 1
    // nếu không cần sắp xếp thì return -1
    // nếu bằng nhau thì return 0
    int x = * (int *) a;
    int y = * (int *) b;
    if (x < y) {
        return 1;
    } else if (x > y) {
        return -1;
    } else return 0;
}

void printArr (int a[] , int n) {
    cout << "array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[] = {1,3,5,12,0,5,9,31,22,10};
    qsort(a, sizeof(a)/sizeof(int), sizeof(int), compare);

    printArr(a, sizeof(a)/sizeof(int));

    return 225;

}
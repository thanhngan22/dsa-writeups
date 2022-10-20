// viết hàm sắp xếp mảng để nhận về giá trị lớn nhất
// VD: [1, 11, 10] => 11110
// [4,3,10,11,2] => 4321110

#include <bits/stdc++.h>
using namespace std;

int countDigits (int n) {
    if (n <= 9) {
        return 1;
    }
    return 1 + countDigits(n / 10);
}

int firstDigit(int n) {
    if ( n <= 9) {
        return n;
    }
    return firstDigit(n / 10);
}

int swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int deleteFirstDigit(int n) {
    return n - firstDigit(n) * pow(10, countDigits(n) - 1);
}

int compare (const void *A, const void *B) {
    int a = *(int*)A;
    int b = *(int*)B;
    if (firstDigit(a) > firstDigit(b)) return -1;
    if (firstDigit(a) < firstDigit(b)) return 1;
    if (firstDigit(a) == firstDigit(b))
    { 
        if (countDigits(a) == 1 && countDigits(b) == 1) {
            return 0;
        }
        if (countDigits(a) == 1) {
            b = deleteFirstDigit(b);
            if (firstDigit(b) > a) {
                return 1;
            }
        }
        if (countDigits(b) == 1 ) {
            a = deleteFirstDigit(a);
            if (firstDigit(a) < b) {
                return 1;
            }
        }
        a = deleteFirstDigit(a);
        b = deleteFirstDigit(b);
        return compare(&a, &b);
    }
}

void arrangeArr (int arr[], int n) {
   qsort(arr, n, sizeof(int), compare);
}

void printArr(int arr[], int n) {
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    int arr1[] = {1, 10, 11};
    int arr2[] = {2, 10, 3 ,11, 4, 23};
    int arr3[] = {12, 26, 30, 19, 11, 22 ,126, 191, 199};

    arrangeArr(arr1, 3);
    arrangeArr(arr2, 6);
    arrangeArr(arr3, 9);
    
    printArr(arr1, 3);
    printArr(arr2, 6);
    printArr(arr3, 9);


    return 225;

}
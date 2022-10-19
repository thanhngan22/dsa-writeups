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

void arrangeArr (int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (firstDigit(arr[i]) < firstDigit(arr[j])) {
                swap(arr[i], arr[j]);
                continue;
            }
            if (firstDigit(arr[i]) == firstDigit(arr[j])) {
                if (countDigits(arr[j]) == countDigits(arr[i])) {
                    if (arr[i] < arr[j]) {
                        swap(arr[i], arr[j]);
                        continue;
                    } else continue;
                }
                if (countDigits(arr[j]) == 1) {
                    int a = arr[i] - firstDigit(arr[i]) * pow(10,countDigits(arr[i])-1);
                    if (firstDigit(a) < arr[j]) {
                        swap(arr[i], arr[j]);
                        continue;
                    } else continue;
                }
                if (countDigits(arr[i]) == 1) {
                    int b = arr[j] - firstDigit(arr[j]) * pow(10,countDigits(arr[j])-1);
                    if (firstDigit(b) > arr[i]) {
                        swap(arr[i], arr[j]);
                        continue;
                    } else continue;
                }
                int a = arr[i] - firstDigit(arr[i]) * pow(10,countDigits(arr[i])-1);
                int b = arr[j] - firstDigit(arr[j]) * pow(10, countDigits(arr[j]-1));
                while ( a >= 0 && b >= 0) {
                    if (firstDigit(a) < firstDigit(b)) {
                        swap(arr[i], arr[j]);
                        break;
                    } 
                    if (countDigits(a) == 1) {
                        b = b - firstDigit(b) * pow(10, countDigits(b) - 1);
                        if (firstDigit(a) <= firstDigit(b)) {
                            swap(arr[i], arr[j]);
                            break;
                        } 
                }
                    if (countDigits(b) == 1) {
                    a = a - firstDigit(a) * pow(10,countDigits(a)- 1);
                    if (firstDigit(b) > firstDigit(a)) {
                        swap(arr[i], arr[j]);
                        break;
                    } 
                }
                    a = a - firstDigit(a) * pow(10,countDigits(a)- 1);
                    b = b - firstDigit(b) * pow(10, countDigits(b) - 1);
                }
            }
        }
    }
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
    int arr2[] = {2, 10, 3 ,11, 4};
    int arr3[] = {12, 26, 30, 19, 11, 22 ,126, 191, 199};

    arrangeArr(arr1, 3);
    arrangeArr(arr2, 5);
    arrangeArr(arr3, 9);
    
    printArr(arr1, 3);
    printArr(arr2, 5);
    printArr(arr3, 9);


    return 225;

}
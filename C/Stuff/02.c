/*
    Viết chương trình tạo 1 mảng số nguyên 1 chiều (10 phần tử) có giá trị phần tử là giá trị ngẫu nhiên từ 0-10.
    Hiển thị ra màn hình mảng đó.
    Sắp xếp lại mảng theo thứ tự tăng dần dùng Bubble Sort 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int arr[10];
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 11;
    }

    // hien thi
    printf("Mang da tao: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    // bubble sort 
    int temp;
    for (int i = 0; i < 9; i++) {
        for (int j = i+1; j < 10; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp; 
            }
        }
    }

    // hien thi mang da sap xep
    printf("\nMang da sap xep: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }





    return 0;
}
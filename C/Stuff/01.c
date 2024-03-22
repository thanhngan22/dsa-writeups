/*
Bai 02: Viết chương trình nhập vào một mảng số nguyên 2 chiều(3x3) và hiển thị mảng đó ra màn hình
a. Nhập giá trị n, tìm giá trị lớn nhất và giá trị nhỏ nhất trong hàng thứ n
b. Tính trung bình cộng các phần tử nằm trên đường chéo

*/

#include <stdio.h>


int main() {
    int arr[3][3];

    // nhap du lieu
    printf("Nhap mang so nguyen 2 chieu (3x3): \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // in ra man hinh
    printf("\nMang da nhap:  \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    //  a. nhap n. tim max, min trong hang n (1<=n<=3)
    int n;

    do {
        printf("Nhap n: ");
        scanf("%d", &n);
    } while (n <= 0 || n > 3);

    int min = arr[n-1][0];
    int max = arr[n-1][0];

    for (int j = 1; j < 3; j++) {
        if (min > arr[n-1][j]) {
            min = arr[n-1][j];
        }
        if (max < arr[n-1][j] ) {
            max = arr[n-1][j];
        }
    }

    printf("Gia tri nho nhat trong hang thu %d: %d\n", n, min);
    printf("Gia tri lon nhat trong hang thu %d: %d\n", n, max);

    // b. tinh tbc cac phan tu nam tren duong cheo (ca cheo chinh va cheo phu)
    int total = 0;
    int count = 0;
    for (int i = 0; i < 3; i++) {
        total += arr[i][i]; // phan tu tren duong cheo chinh
        total += arr[i][n-1-i]; // phan tu tren duong cheo phu
        count += 2;
    }

    // printf("Total: %d\n", total);

    printf("Trung binh cong cac phan tu nam tren duong cheo : %.2f\n", (total * 1.0)/count);






    return 0;
}
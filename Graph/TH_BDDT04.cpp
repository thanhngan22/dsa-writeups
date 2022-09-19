// ma trận kề sang danh sách cạnh

#include <iostream>
using namespace std;

int a[1001][1001];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    // Xuất danh sách cạnh
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i][j] == 1) {
                cout << i << " " << j << endl;
            }
        }
    }

    return 225;
}
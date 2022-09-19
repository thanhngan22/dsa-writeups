// ma trận kề sang danh sách kề

#include <iostream>
#include <vector>
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

    vector <int> v[1001];
    for (int i = 1; i <= n; i++ ) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 1) {
                v[i].push_back(j);
            }
        }
    }

    // Xuất danh sách kề
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int x: v[i]) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 225;

}
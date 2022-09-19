// danh sách cạnh sang ma trận kề

#include <iostream>
using namespace std;

int a[1001][1001];

// trường hợp 2: đồ thị có hướng

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u][v] += 1;
        a[v][u] += -1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 225;

}
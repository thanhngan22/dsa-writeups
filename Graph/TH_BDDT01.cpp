// danh sách cạnh sang ma trận kề

#include <iostream>
#include <vector>
using namespace std;

int a[1001][1001];


// trường hợp 1: đồ thị vô hướng



int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u][v] = a[v][u] = 1;
    }

    // Xuất ma trận kề
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 225;

}
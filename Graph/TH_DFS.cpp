// ứng dụng đếm số thành phần liên thông

#include <bits/stdc++.h>
using namespace std;

bool visited[1005];
vector <int> a[1005];

// thuat toan DFS
void DFS(int u) {
    visited[u] = true;
    for (int x : a[u]) {
        if (!visited[x]) {
            DFS(x);
        }
    }
}

int main() {

    // khoi tao gia tri cho mang visited
    memset(visited, false, sizeof(visited));

    int n, m;
    cin >> n >> m;

    // nhap danh sach canh va chuyen thanh danh sach ke
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    // duyet do thi va dem so lien thong
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == false) {
            DFS(i);
            count++;
        }
    }

    cout << count << endl;

    return 225;

    
    
}
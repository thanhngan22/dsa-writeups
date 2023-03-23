#include <bits/stdc++.h>
using namespace std;

// khởi tạo queue rỗng
queue <int> q;

// khởi tạo danh sách kề
vector <int> a[1001];
bool visited[1001];

// Thuật toán BFS
void BFS(int u ) {
    q.push(u);
    visited[u] = true;
    while (!q.empty()) {
        int value = q.front();
        q.pop();
        cout << value << " ";
        for (int x : a[value]) {
            if (!visited[x]) {
                q.push(x);
                visited[x] = true;
            }
        }
    }

}

int main() {
    int n, m;
    cin >> n >> m;

    // khởi tạo giá trị cho visited
    memset(visited, false, sizeof(visited));

    // đọc dữ liệu
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        a[u].push_back(v);
        a[v].push_back(u);
    }

    BFS(1);

    return 225;
}
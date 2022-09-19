// thuật toán tìm kiếm theoo chiều sâu: 
// input: số đỉnh, số cạnh, ma trận kề
// output: thứ tự duyệt, thứ tự hoàn thành


#include <bits/stdc++.h>
using namespace std;

// Thuật toán DFS
void DFS(int u) {
    cout << u << " ";
    visited[u] = true;

    for (int x : v[u]) {
        if (!visited[x]) {
            DFS(x);
        }
        }
    }


// khai báo mảng visited để lưu trạng thái đã duyệt hay chưa
bool visited[1001] ;
int a[1001][1001];
vector <int> v[1001];


int main() {
    int n,m;
    cin >> n >> m;

    // lấy dữ liệu
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    // khởi tạo mảng visited
    memset(visited, false, sizeof(visited));


    for (int i = 1; i <=n ; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 1) {
                v[i].push_back(j);
            }
        }
    }

    DFS(1);

    return 225;
}


// Thuật toán tìm kiếm theo chiều sâu: DFS
// Input: số đỉnh, số cạnh, danh sách cạnh
// Output: thứ tự duyệt, thứ tự hoàn thành






#include <bits/stdc++.h>
using namespace std;

// khai báo mảng visited để lưu trạng thái đã duyệt hay chưa
bool visited[1001] ;
vector<int> v[1001];


void DFS(int u) {
    
        cout << u << " ";
        visited[u] = true;

        for (int x : v[u]) {
            if (visited[x] == false) {
                DFS(x);
            }
            }
}

int main() {
    int n,m;
    cin >> n >> m;
    
    // đọc dữ liệu danh sách cạnh và chuyển thành danh sách kề
    for (int i = 1; i <=m ;i++) {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    memset(visited, false, sizeof(visited));

    DFS(1);

    return 225;

}
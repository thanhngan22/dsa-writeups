// Thuật toán duyệt đồ thị theo chiều rộng (bfs)

#include <bits/stdc++.h>
using namespace std;

void bfs (vector<vector<int>> list, int u, bool *visited) {
    queue<int> q;
    q.push(u);

    while ( ! q.empty()) {
        u = q.front();
        q.pop();
        if (visited[u] == false) {
            cout << u << " ";
            visited[u] = true;
            for (int x : list[u]) {
                if (visited[x] == false) {
                    q.push(x);
                }
            }
        }
    }

}



int main() {

    // tạo ra danh sách kề cho đồ thị
    vector <vector<int>> list;
    vector<int> v1, v2, v3, v0, v4;
    v0.push_back(3);
    v0.push_back(2);
    v1.push_back(4);
    v1.push_back(2);
    v2.push_back(0);
    v2.push_back(3);
    v2.push_back(1);
    v2.push_back(4);
    v3.push_back(0);
    v3.push_back(2);
    v3.push_back(4);
    v4.push_back(2);
    v4.push_back(1);
    v4.push_back(3);
    list.push_back(v0);
    list.push_back(v1);
    list.push_back(v2);
    list.push_back(v3);
    list.push_back(v4);

    // khởi tạo danh sách vistited với giá trị false
    int n = list.size();
    bool visited[n] = {false};

    // duyệt đồ thị bắt đầu từ đỉnh 1
    bfs(list, 1, visited);

    return 225;
}
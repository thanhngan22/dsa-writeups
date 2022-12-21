#include <bits/stdc++.h>
using namespace std;

// 1. viết hàm kiểm tra ma trận kề có đối xứng qua đường chéo chính hay không
bool isDoiXung (int **a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                return false;
            }
        }
    }
    return true;
}



// 2. viết hàm in ra bậc các đỉnh trong đồ thị
void printDegs (int **a, int n) {
    if (isDoiXung(a,n)) {
        // Đồ thị vô hướng
        for (int i = 0; i < n; i++) {
            int deg = 0;
            for (int j = 0; j < n; j++) {
                deg += a[i][j];
            }
            cout << "deg(" << i << ") =  " << deg << endl;
        }
    } else {
        // Đồ thị có hướng
        for (int i = 0; i < n; i++) {
            // Bậc của đỉnh là tổng bậc ra và bậc vào
            int deg = 0;
            for (int j = 0; j < n; j++) {
                deg += a[i][j];     // Bậc ra
                deg += a[j][i];     // Bậc vào
            }
            cout << "deg(" << i << ") = " << deg << endl;
        }
    }
}

// 3. từ ma trận trọng số, hãy viết hàm tạo ra danh sách cạnh đồ thị, mỗi cạnh gồm đỉnh đầu cuối và trọng số

// struct cạnh của đồ thị
struct Edge {
    int u, v;   // u : đỉnh đầu, v : đỉnh cuối
    int w;      // trọng số

    Edge(int a, int b, int d) {
        this->u = a;
        this->v = b;
        this->w = d;
    }
};

vector<Edge> convertAdjList (int **a, int n) {
    vector <Edge> list;
    if (isDoiXung(a, n)) {
        // đồ thị vô hướng
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (a[i][j] != 0) {
                    Edge e = Edge(i,j,a[i][j]);
                    list.push_back(e);
                }
            }
        }

    } else {
        // đồ thị có hướng
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] != 0) {
                    Edge e = Edge(i, j, a[i][j]);
                    list.push_back(e);
                }
            }
        }
    }
    return list;
}

// 4. sắp xếp mảng các cạnh theo trọng số tăng dần
void sortList (vector <Edge> &list) {
    for (int i = 0; i < list.size() - 1; i++) {
        for (int j = i + 1; j < list.size(); j++ ) {
            if (list[i].w > list[j].w) {
                swap(list[i], list[j]);
            }
        }
    }
}

// 5. thuật toán Kruskal

// 6. thuật toán Prim

// 7. thuật toán Dijkstra

// 8. tìm đường đi ngắn nhất từ đỉnh u đến đỉnh v






int main() {




    return 225;
}
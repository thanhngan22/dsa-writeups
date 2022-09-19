#include <bits/stdc++.h>
using namespace std;

void InsetionSort2(int n, vector <int> &v) {
    for (int pos = 1; pos < n; pos++) {
        for (int j = 0; j <= pos -1; j++) {
            if (v[j] > v[pos]) {
                // chèn v[pos] vào vị trí j
                int temp = v[pos];
                for (int k = pos; k > j; k--) {
                    v[k] = v[k - 1];
                }
                v[j] = temp;
                break;
            }
        }
        // in ra vector v sau mỗi lần duyệt
            for (int x : v) {
                cout << x << " ";
            }
            cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector <int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    InsetionSort2(n, v);

    return 225;
}
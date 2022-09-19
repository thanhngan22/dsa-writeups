// danh sách kề sang ma trận kề

#include <bits/stdc++.h>
using namespace std;

int a[1001][1001];


int main() {
    int n;
    cin >> n;
    string s;
    vector <string> v[1001];

    for (int i = 1; i <= n; i++) {
        fflush(stdin);
        getline(cin, s);
        v[i].push_back(s);
    }

    for (int i = 1; i <= n; i++) {
        stringstream ss(v[i][0]);
        string num;
        while (ss >> num) {
            a[i][stoi(num)] = 1;
        }
    }

     // xuất ma trận kề
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }

    return 225;
}
// Danh sách kề sang danh sách cạnh

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector <string> v[1001];
    string s;

    for (int i = 1; i <= n; i++ ) {
        fflush(stdin);
        getline(cin,s);
        v[i].push_back(s);
    }

    for (int i = 1; i <= n; i++) {
        stringstream ss(v[i][0]);
        string num;
        while (ss >> num) {
            if (stoi(num) > i) {
                cout << i << " " << num << endl;
            }
        }
    }

    return 225;

}
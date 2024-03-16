/*
Cho dãy A gồm N phần tử. Tìm 2 dãy con không giao nhau có chênh lệch lớn nhất.
VD: 
5 2
1 3 2 1 8
KQ: 5
*/

#include <iostream>
#include <vector>
using namespace std;


int main() {

    vector<int> input;
    int n, k;

    // get input
    cin >> n >> k;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        input.push_back(x);
    }

    int s1, s2, maxDiff = 0;
    for (int i = 0; i <= n - 2*k; i++) {
        s1 = 0;
        for (int p = 0; p < k; p++) {
            s1 += input[i + p];
        }

        for (int r = i + k; r <= n - k; r++) {
            s2 = 0;
            for (int m = 0; m < k; m++) {
                s2 += input[r + m];
            }
            if (abs(s2 - s1) > maxDiff) {
                maxDiff = abs(s2 - s1);
            } 
        }
    }

    cout << maxDiff;




    return 22;
}
#include <iostream>
#include <vector>

using namespace std;

int flatlandSpaceStations(int n, vector<int> c) {
    if (n == c.size()) {
        return 0;
    }
    int max = 0;
    for (int i = 0;i < n; i++ ) {
        int j;
        for (j = 0; j < c.size() ; j++) {
            if (c[j] == i) {
                break;
            }
        }
        if (j >= c.size()) {
            int d1 = n;            
            for (int x : c) {
                if (abs(x-i) < d1) {
                    d1 = abs(x-i);
                }
            }
            if (max < d1 ) {
            max = d1;
        }
        }
        
    }
    return max;

}

int main() {
    vector <int> v = {0,4};
    cout << flatlandSpaceStations(5,v);

    return 225;

}
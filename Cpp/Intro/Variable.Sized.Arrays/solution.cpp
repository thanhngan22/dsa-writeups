#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, nQueries;
    cin >> n >> nQueries;
    cin.ignore();
    
    map<int, vector<int>> dict;
    
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<int> v;
        for (int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        dict.insert(make_pair(i, v));
        cin.ignore();
    }
    
    for (int j = 0; j < nQueries; j++) {
        int idx1, idx2;
        cin >> idx1 >> idx2;
        cin.ignore();
        cout << dict.at(idx1)[idx2] << endl;
    }
       
    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n, m;
    vector<int> data;
    vector<int> queries;
    
    cin >> n;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        data.push_back(temp);
    }
    cin.ignore();
    cin >> m; 
    for (int j = 0; j < m; j++) {
        cin >> temp;
        queries.push_back(temp);
        cin.ignore();
    }
    
    map<int, int> dict ;
    for (int j = 0; j < n; j++) {
        if (dict.find(data[j]) == dict.end()) {
            dict[data[j]] =  j+1;
        }
    }
    set<int> list(data.begin(), data.end());
    vector<int> list_v(list.begin(), list.end());
    
    for (int i = 0; i < m; i++) {
        if (dict.find(queries[i]) != dict.end()) {
            cout << "Yes " << dict.at(queries[i])  << endl;
        } else {
            auto it = upper_bound(list_v.begin(), list_v.end(), queries[i]);
            if (it != list_v.end()) {
                cout << "No " << dict.at(*it) << endl;
            }
        }
    }
     
    
      
    return 0;
}

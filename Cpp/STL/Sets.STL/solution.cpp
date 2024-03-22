#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    int type, value;
    cin >> n;
    cin.ignore();
    
    set<int> data;
    for (int i = 0; i < n; i++) {
        cin >> type >> value ;
        cin.ignore();
        
        if (type == 1) {
            data.insert(value);
        } else {
            if (type == 2) {
                data.erase(value);
            } else {
                if (data.find(value) != data.end()) {
                    cout << "Yes\n";
                } else {
                    cout << "No\n";
                }
            }
        }
        
    }
    
       
    return 0;
}

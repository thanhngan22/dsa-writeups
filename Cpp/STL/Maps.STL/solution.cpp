#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    map<string, int> data;
    
    int type, score;
    string name;
    
    cin >> n;
    cin.ignore();
    
    for (int i = 0; i < n; i++) {
        cin >> type >> name ;
        if (type == 1) {
            int old_mark = 0;
            cin >> score;
            if (data.find(name) != data.end()) {
                old_mark = data[name];
            }
            data[name] = old_mark + score;
        } else {
            if (type == 2) {
                data.erase(name);
            } else {
                if (data.find(name) == data.end()) {
                    cout << 0 << endl;
                } else {
                    cout << data[name] << endl;
                }
            }
        }
        cin.ignore();
        
    }
    
    
    
    return 0;
}

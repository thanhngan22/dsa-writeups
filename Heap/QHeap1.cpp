#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> Q;
    for (int i = 0; i < n ; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string mem;
        if (ss >> mem) {
            if (mem == "1") {
                ss >> mem;
                Q.push_back(stoi(mem));
            } else if (mem == "2") {
                
            }
        }

    }
}


// chưa xong
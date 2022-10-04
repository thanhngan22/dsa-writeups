#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> Q;
    stringstream result;
    for (int i = 0; i < n ; i++) {
        string s;
        fflush(stdin);
        getline(cin, s);
        stringstream ss(s);
        string mem;
        if (ss >> mem) {
            if (mem == "1") {
                ss >> mem;
                Q.push_back(stoi(mem));
            } else if (mem == "2") {
                ss >> mem;
                for (int i = 0; i < Q.size(); i++) {
                    if (Q[i] == stoi(mem)) {
                        Q.erase(Q.begin() + i);
                        break;
                    }
                }
            } else if (mem == "3") {
                int min = Q[0];
                for (int i = 1; i < Q.size(); i++) {
                    if (Q[i] < min) {
                        min = Q[i];
                    }
                }
                for (int i = 0; i < Q.size(); i++) {
                    if (Q[i] == min) {
                        result << min << endl;
                    }
                }
            }
        }

    }

    cout << result.str();

    return 225;
}




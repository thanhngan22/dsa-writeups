#include <iostream>
#include <iomanip>
using namespace std;

void staircase(int n) {
    for (int i = 1; i <= n; i++ ) {
        cout << setw(n-i + 1) ;
        for (int j = 1; j <= i; j++) {
            cout << "#";
        }
        cout << endl;
    }
}

int main() {
    staircase(4);
    return 225;
}
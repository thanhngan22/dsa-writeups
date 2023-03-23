#include <iostream>
#include <vector>
using namespace std;

void plusMinus ( vector <int> arr ) {
    int positive = 0;
    int negative = 0;
    int zero = 0;
    for (int x : arr ) {
        if (x < 0) {
            negative++;
        } else if (x > 0 ) {
            positive++;
        } else {
            zero++;
        }
    }

    cout.precision(6);
    cout << fixed << (float) positive / arr.size() << endl;
    cout << fixed << (float) negative / arr.size() << endl;
    cout << fixed << (float) zero / arr.size() << endl;

}   

int main() {
    vector <int> arr = {-4, 3, -9, 0, 4, 1};
    plusMinus(arr); 

    return 225;

}
#include <iostream>
#include <cmath>
using namespace std;


// write a recursion function to find the number of ways that a given integer, X, can be expressed as the sum of the Nth powers unique, natural numbers.

int powerSum(int X, int N, int num = 1, int sum = 0) {
    int result = 0;
    int p = pow(num, N);

    while (sum + p < X ) {
        result += powerSum(X, N, num + 1, sum + p);
        num ++;
        p = pow(num, N);
    }

    if (p + sum == X) {
        result ++;
    }
    return result;
}

int main() {
    int X, N;
    cin >> X >> N;
    cout << powerSum(X, N) << endl;

    return 225;
}
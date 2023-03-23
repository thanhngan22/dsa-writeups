#include <bits/stdc++.h>
using namespace std;

int IntroTutorial(int V, vector <int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == V) {
            return i;
        }
    }
}

int main () {
    int V = 4;
    vector <int> arr ={1, 4, 5, 7, 9, 12};
    int result = IntroTutorial(V, arr);

    cout << result << endl;

    return 225;
}
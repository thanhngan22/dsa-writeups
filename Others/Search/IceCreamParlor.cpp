// given a list of prices for the favors of ice cream , select two flavors whose prices add up to the amount of money given to spend on them. print the indices of the two flavors, sorted ascendingly.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> icecreamParlor(int m, vector<int> arr) {
    vector <int> cpy = arr;
    vector <int> kq;
    sort(cpy.begin(), cpy.end());
   
    for (int i = 0; i < cpy.size() -1; i++) {
        for (int j = i+1; j < cpy.size(); j++) {
            if (cpy[i] + cpy[j] == m) {
                for (int k = 0; k < arr.size(); k++) {
                    if (arr[k] == cpy[i] || arr[k] == cpy[j]) {
                        kq.push_back(k + 1);
                    }
                    if (kq.size() == 2) {
                        return kq;
                    }
                }

            } else if (cpy[i] + cpy[j] > m) {
                break;
            }
        }
    }
}

int main() {
    vector <int> v = {1,4,5,3,2};
    int m = 4;

    vector <int>  kq = icecreamParlor(m, v);

    for (int i : kq) {
        cout << i << " ";
    }

    return 225;

}
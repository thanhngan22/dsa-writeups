#include <bits/stdc++.h>
using namespace std;

void swap (string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

vector <string> sortBasic (vector <string> &unsorted) {
    // sort the vector without using sort() function
    // return the sorted vector
    int n = unsorted.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (unsorted[i].length() > unsorted[j].length()) {
                swap(unsorted[i], unsorted[j]);
            } 
            else if (unsorted[i].length() == unsorted[j].length()) {
                if (unsorted[i] > unsorted[j]) {
                    swap(unsorted[i], unsorted[j]);
                }
                }
            }
        }
    return unsorted;
    }


vector <string> sortUsingSort (vector <string> &unsorted) {
    // sort the vector using sort() function
    // return the sorted vector

    sort(unsorted.begin(), unsorted.end(), [](string a, string b) {
        if (a.length() == b.length()) {
            return a < b;
        }
        return a.length() < b.length();
    });
    return unsorted;
    
    // learn more about lambda in cpp: [] () {};
    // https://cppdeveloper.com/c-nang-cao/lambda-expression-trong-c/

    // docs about sort func of algorithms library:
    // https://en.cppreference.com/w/cpp/algorithm/sort

}

int main() {
    // store the input in a vector of strings
    // the first line is a number n, the number of strings
    // the next n lines are the strings

    int n;
    cin >> n;
    vector <string> unsorted;
    for (int i = 0; i < n; i++) {
        string s;
        fflush(stdin);
        getline(cin, s);
        unsorted.push_back(s);
    }

    // sort the vector of strings
    // unsorted = sortBasic(unsorted);
    unsorted = sortUsingSort(unsorted);

    // print the sorted vector
    for (int i = 0; i < n; i++) {
        cout << unsorted[i] << endl;
    }

    return 225;     // done
}
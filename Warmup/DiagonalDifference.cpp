//  calculate the absolute difference between the sums of the matrix's two diagonals.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // create a matrix
    vector <vector <int>> matrix;
    for (int i = 0; i < 3; i++) {
        vector <int> row;
        for (int j = 0; j < 3; j++) {
            row.push_back(i + j);
        }
        matrix.push_back(row);
    }

    // print the matrix
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // calculate the absolute difference between the sums of the matrix's two diagonals.
    int sumLeft = 0;
    int sumRight = 0;

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (i == j) {
                sumLeft += matrix[i][j];
            }
            if (i + j == matrix.size() - 1) {
                sumRight += matrix[i][j];
            }
        }
    }

    cout << "absolute difference : " <<abs(sumLeft - sumRight) << endl;

    return 225;
}
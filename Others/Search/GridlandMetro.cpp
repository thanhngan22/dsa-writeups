// given a map of gridland and its train tracks, find and print the number of cells where the mayor can place lampposts

#include <iostream>
#include <vector>
using namespace std;

int gridlandMetro(int m, int n,int k, vector <vector <int>> track) {
    vector <vector <int>> check ;
    for (int i = 0; i < n ; i ++) {
        vector <int> temp;
        for (int j = 0; j < m; j++) {
            temp.push_back(0);
        }
        check.push_back(temp);
    }
    for (int i = 0; i < k; i++) {
        int r = track[i][0] - 1;
        int c1 = track[i][1] - 1;
        int c2 = track[i][2] - 1;
        for (int j = c1; j <= c2; j++){
            check[r][j] = 1;
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int x : check[i]) {
            if (x == 0) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int n;
    int m;
    int k;
    cin >> n >> m >> k;
    vector< vector<int> > track(k,vector<int>(3));
    for(int track_i = 0;track_i < k;track_i++){
       for(int track_j = 0;track_j < 3;track_j++){
          cin >> track[track_i][track_j];
       }
    }
    int result = gridlandMetro(m, n, k, track);
    cout << result << endl;
    return 0;
}
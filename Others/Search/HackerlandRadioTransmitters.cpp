// given a map of hackerland and the tranmission range, determine the minimun number of transmitters 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int hackerlandRadioTransmitters(vector <int> x, int k) {
    // Complete this function

    // sort the vector
    sort(x.begin(), x.end());

    int n = x.size();
    int count = 0;
    int i = 0;
    while(i < n){
        count++;
        int loc = x[i] + k;  
        while(i < n && x[i] <= loc) i++; 
        loc = x[--i] + k; 
        while(i < n && x[i] <= loc) i++;    
    }
    return count;
}

int main() {
    vector <int> v = {7,2,4,6,5,9,12,11};
    int k = 2;
    int result = hackerlandRadioTransmitters(v, k);
    cout << result <<  endl;

    return 225;

}
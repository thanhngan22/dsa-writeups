#include <iostream>
#include <deque> 
#include <vector>

using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    
    // using deque to store index of max value in sub array size k
    deque<int> dq;
    vector<int> result;

    // index valid of sub array size k from [i, k+i-1]
    for (int i = 0; i < n; i++) {
        // if deque is not empty and the first item is out of bound, then remove it 
        while (! dq.empty() && dq[0] < i - k + 1) {
            dq.pop_front();
        }
        
        // remove item with arr value at that index < current value
        while ( ! dq.empty() && arr[i] > arr[dq[dq.size()-1]]) {
            dq.pop_back();
        }
        dq.push_back(i);
        
        // if we iterate through k element of sub array size k, then it is the max value
        if (i >= k-1) {
            result.push_back(arr[dq[0]]);
        }
    }
    for (int j = 0; j < result.size(); j++) {
        cout << result[j] << " ";
    }
    cout << endl;
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}

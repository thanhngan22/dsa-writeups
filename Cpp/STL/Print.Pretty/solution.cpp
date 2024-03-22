#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    double a,b,c;
    int n;
    
    cin >> n;
    cin.ignore();
    
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        cin.ignore();
        
        // handle
        // the first num:  strip its decimal and representation in hexa
        cout << hex << left << std::showbase << nouppercase << std::noshowpos  << (long long) a << endl;
        
        // the second num: print it to a scale of 2 decimal places 
        
        cout << dec << right << std::setw(15) << std::setfill('_') << std::showpos << std::noshowbase << std::fixed << std::setprecision(2) << b << endl;
        
        // the third num: print in a scale of exactly nine decimal places
        cout << std::scientific << std::uppercase << std::noshowpos << std::noshowbase << std::setprecision(9) << c << endl; 


  
        
    }
    
    
    
    return 0;
}

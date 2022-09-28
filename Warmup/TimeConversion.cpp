#include <iostream>
#include <string>
using namespace std;

string timeConversion(string s) {
    string hh = s.substr(0,2);
    string mm = s.substr(3,2);
    string ss = s.substr(6,2);
    string ampm = s.substr(8,2);
    
    if (ampm == "AM") {
        if (hh == "12") {
            hh = "00";
        }
    } else {
        if (hh != "12")
        hh = to_string(12 + stoi(hh));
    }
    return hh + ":" + mm + ":" + ss ;
}

int main() {
    cout << timeConversion("12:09:59AM") << endl;
    cout << timeConversion("12:09:59PM") << endl;

    return 225;
}
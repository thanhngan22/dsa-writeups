#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N,Q;
    
    cin >> N >> Q;
    vector<string> hrmls;
    vector<string> queries;
    string temp;
    getline(cin, temp);
    
    for (int i = 0; i < N; i++) {
        getline(cin, temp);
        hrmls.push_back(temp);
    }
    
    for (int j = 0; j < Q; j++) {
        getline(cin, temp);
        queries.push_back(temp);
    }
        
    map<string, map<string, string>> dic;
    // handle
    string parrent = "";
    string curr = "";
    
    
    for (int i = 0; i < N; i++) {
        // if is a closing tag
        if (hrmls[i].find("</tag") != string::npos) {
            // remove last parrent
            if (parrent.find_last_of(".") != string::npos) {
                parrent.erase(parrent.find_last_of("."));
            } else {
                parrent.erase(0);
            }
            // cout << "\nclosed tag" << endl;
        } else {
            // current tag name
            curr = hrmls[i].substr(1, hrmls[i].find_first_of(" ") - 1);
            // cout << "curr: -" << curr << "-" << endl;
            
            if ( ! parrent.empty()) {
                parrent.append(".");
            } 
            parrent.append(curr);
            // get all attributes
            map<string, string> list_attr;
            while (hrmls[i].find("=") != string::npos) {
                int start = hrmls[i].find_first_of("=");
                int end = hrmls[i].find_first_of("\"", start+3);
                string value = hrmls[i].substr(start+3, end - start - 3);
                string key = hrmls[i].substr(hrmls[i].find_first_of(" ") +1, hrmls[i].find_first_of("=") - hrmls[i].find_first_of(" ") - 2);
                hrmls[i].erase(hrmls[i].find_first_of(" "), end - hrmls[i].find_first_of(" ")+1);
                
                list_attr.insert(make_pair(key, value));
                // cout << "key: -" << key << "-" << endl;
                // cout << "value: -" << value << "-" << endl;
                // cout << "string: -" << hrmls[i] << "-" << endl;
                
            }
            
            dic.insert(make_pair(parrent, list_attr));
            
        }
    }
    
    // get res;
    vector<string> res;
    for (int i = 0; i < Q; i++ ) {
        string tag = queries[i].substr(0, queries[i].find("~"));
        string att_name = queries[i].substr(queries[i].find("~" )+ 1);
        
        // cout << "tag: -" << tag << "-" << endl;
        // cout << "att_name: -" << att_name << "-" << endl;
        
        
        if (dic.find(tag) != dic.end()) {
            if (dic.at(tag).find(att_name) != dic.at(tag).end()) {
                string value = dic.at(tag).at(att_name);
                res.push_back(value);
                
            } else {
                res.push_back("Not Found!");
                
            }
        } else {
            res.push_back("Not Found!");
        }
    }
    

    
    for (int i = 0 ; i < Q; i++) {
        cout << res[i] << endl;
    }
    
    
    
    
    
    return 0;
}

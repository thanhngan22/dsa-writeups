#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'happyLadybugs' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING b as parameter.
 */

string happyLadybugs(string b) {
    // get distinct char of string
    set<char> uniqueChar(b.begin(), b.end());
    
    if (uniqueChar.size() == 1 && *uniqueChar.begin() == '_') {
        return "YES";
    }
    
    // statistic
    unordered_map<char, int> occurrences;
    for (char ch : b) {
        occurrences[ch] ++;
    } 
    
    // if have a single alphabetic -> NO
    for (const auto &pair : occurrences) {
        if (pair.first != '_' && pair.second == 1) {
            return "NO";
        }
    }
    
     if (occurrences.count('_') == 0) {
                
        for (int i = 0; i < b.length() - 1; i++) {
            int count = occurrences[b[i]];
            
            for (int j = 1; j < count; j++) {
                if (b[i] != b[i + j]) {
                    return "NO";
                }
            }
            
            i += count -1;
            
        }
    }
    
        
    return "YES";
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_temp;
    getline(cin, g_temp);

    int g = stoi(ltrim(rtrim(g_temp)));

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

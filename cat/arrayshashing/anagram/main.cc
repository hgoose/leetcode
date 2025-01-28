#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using std::cout;
using std::vector;
using std::endl;
using std::string;
using std::sort;

class Solution {
public:
    // bool isAnagram(string s, string t) {
    //     sort(s.begin(), s.end()); sort(t.begin(), t.end());
    //     return (s == t ? true : false);
    // }

    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> freq(26, 0);

        for (int i=0; i<(int)s.size(); ++i) {
            ++freq[s[i] - 'a'];
            --freq[t[i] - 'a'];
        }

        for (const auto& item : freq) {
            if (item != 0 ) return false;
        }
        return true;
    }

};

int main(int argc, char** argv) {

    return 0;
}

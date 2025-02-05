#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using std::cout;
using std::string;
using std::vector;
using std::endl;


class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.size() != s2.size()) return false;

        vector<int> farr(26,0);

        for (int i=0; i<(int)s1.size(); ++i) {
            ++farr[(int)s1[i] - 'a'];
            --farr[(int)s2[i] - 'a'];
        }

        for (int i=0; i<26; ++i) {
            if (farr[i] != 0) return false;
        }

        int diffCount{};
        for (int i=0; i<(int)s1.size(); ++i) {
            if (s1[i] != s2[i]) ++diffCount;
            if (diffCount > 2) return false;
        }
        return true;
    }
};

int main(int argc, char** argv) {

    return 0;
}

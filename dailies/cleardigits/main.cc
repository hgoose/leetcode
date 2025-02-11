#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
using std::cout;
using std::string;
using std::vector;
using std::unordered_map;
using std::endl;
using std::ostringstream;

typedef long long dword;

class Solution {
public:
    string clearDigits(string s) {

        vector<int> chars;
        for (int i=0; i<(int)s.size(); ++i) {
            if (isdigit(s[i])) {
                s.erase(i,1);
                int last = chars.back();
                chars.pop_back();
                s.erase(last, 1);
                i-=3;

                if (i < 0) i = -1;
            } else {
                chars.push_back(i);
            }
        }
        return s;
    }
};

int main(int argc, char** argv) {

    return 0;
}

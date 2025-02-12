#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <regex>
using std::cout;
using std::string;
using std::vector;
using std::unordered_map;
using std::endl;
typedef long long dword;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        std::smatch captures;
        std::regex pattern = std::regex("(.*?)" + part + "(.*)");
        while (regex_search(s, captures, pattern)) {
            s   = captures[1].str() + captures[2].str();
        }
        return s;
    }
};

int main(int argc, char** argv) {

    return 0;
}

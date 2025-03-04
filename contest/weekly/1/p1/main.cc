#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <utility>
#include <cmath>
#include <bitset>
#include <array>
#include <map>
using std::map;
using std::array;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;
using std::queue;
using std::priority_queue;
using std::bitset;
typedef long long dword;

template<typename T, typename U>
using pmap = unordered_map<T,U>;

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            string ns{};
            for (int i=0; i<(int)s.size();++i)  {
                if (i+1 < s.size())  {
                    char d1 = s[i];
                    char d2 = s[i+1];
                    int newDig = (((int) d1 - 48 ) + ((int) d2 - 48)) % 10;
                    ns += std::to_string(newDig);
                }
            }
            s  = ns;
        }
        return (s[0]  == s[1] ? true : false);
    }
};

int main(int argc, char** argv) {

    return 0;
}

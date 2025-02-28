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
#include <limits>
#include <tuple>
#include <cstdint>
using std::tuple;
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

template<typename T>
using lims = std::numeric_limits<T>;

class Solution {
public:
    string _dc(string& s, int l, int r) {
       if (l == r)  {
           return s.substr(l,1);
       }

       int mid = (l + r) / 2;
       string left = _dc(s, l, mid);
       string right = _dc(s, mid+1, r);

       return right + left;

    }
    uint32_t reverseBits(uint32_t n) {
        string s = std::bitset<32>(n).to_string();
        return std::bitset<32>(_dc(s,0,s.size()-1)).to_ulong();
    }
};

int main(int argc, char** argv) {

    Solution s;
    cout << s.reverseBits(00000010100101000001111010011100);

    return 0;
}

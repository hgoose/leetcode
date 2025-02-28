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
    int _dc(string& s, int l, int r) {
        if (l == r) {
            return (int) s[l] - 48 == 1 ? 1 : 0;
        }

        int mid  = (l + r) / 2;
        int leftweight = _dc(s, l, mid);
        int rightweight = _dc(s, mid+1, r);

        return leftweight + rightweight;
    }
    int hammingWeight(int n) {
        string s = std::bitset<32>(n).to_string();       
        return _dc(s,0,s.size()-1);
    }
};

int main(int argc, char** argv) {

    return 0;
}

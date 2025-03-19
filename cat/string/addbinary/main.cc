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
#include <numeric> // std::accumulate
#include <climits> // INT_MAX, INT_MIN, ...
#include <tuple>
#include <unordered_set>
#include <algorithm>
#include <stack>
using std::pair;
using std::stack;
using std::unordered_set;
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

template<typename T>
using pset = unordered_set<T>;

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

template<typename T>
using lims = std::numeric_limits<T>;

template<typename T, typename U>
using pmap = unordered_map<T,U>;

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) std::swap(a,b);
        string res{};
        bool carry=false;
        for (int i=b.size()-1, j=a.size()-1; i>=0; --i, --j) {
            char curr;
            if (a[j] == '1' && b[i] == '1') {
               carry ? curr = '1' : curr = '0'; 
               carry = true;
            } else if (a[j] == '0' && b[i] == '0') {
                carry ? curr = '1' : curr = '0';
                carry = false;
            } else {
                carry ? curr = '0' : curr = '1';
                carry ? carry = true : carry = false;
            }
            res+=curr;
        } 

        for (int i=a.size() - b.size()-1; i>=0; --i) {
            char curr;
            if (a[i] == '1') {
               carry ? curr = '0' : curr = '1'; 
               carry ? carry = true : carry = false;
            } else {
                carry ? curr = '1' : curr = '0';
                carry = false;
            }
            res.push_back(curr);
        }
        if (carry) res.push_back('1');
        std::reverse(res.begin(), res.end());

        return res;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.addBinary("100", "110010");

    return 0;
}

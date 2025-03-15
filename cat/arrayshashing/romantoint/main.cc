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
// vector<string> symbol{"M", "CM",  "D", "CD", "C", "XC", "L", "XL", "X", "IX",  "V", "IV", "I"}; 
// vector<int> values{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9,  5, 4, 1};

class Solution {
public:
    int romanToInt(string s) {
        int n = s.size(), res=0;
        for (int i=0; i<n; ++i) {
            switch (s[i]) {
                case 'M':
                    res+=1000;
                    break;
                case 'D':
                    res+=500;
                    break;
                case 'C':
                    if (i+1 < n && s[i+1] == 'M') {
                        res+=900;
                        ++i;
                    } else if (i+1 <n && s[i+1] == 'D') {
                        res+=400;
                        ++i;
                    } else res+=100;
                    break;
                case 'L':
                    res+=50;
                    break;
                case 'X':
                    if (i+1 <n && s[i+1] == 'C') {
                        res+=90;
                        ++i;
                    } else if (i+1 < n && s[i+1] == 'L') {
                        res+=40;
                        ++i;
                    } else res+=10;
                    break;
                case 'V':
                    res+=5;
                    break;
                case 'I':
                    if (i+1 < n && s[i+1] == 'X') {
                        res+=9;
                        ++i;
                    } else if (i+1 < n && s[i+1] == 'V') {
                        res+=4;
                        ++i;
                    } else res+=1;
                    break;
            }
        }
        return res;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.romanToInt("DCXXI") << '\n';
    400 + 100 + 10 + 10 = 520

    return 0;
}

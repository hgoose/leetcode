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
    string intToRoman(int num) {
        vector<string> symbol{"M", "CM",  "D", "CD", "C", "XC", "L", "XL", "X", "IX",  "V", "IV", "I"}; 
        vector<int> values{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9,  5, 4, 1};

        string res{};
        while (num > 0) {
            for (int i=0; i<(int)values.size(); ++i) {
                if (num - values[i] >= 0) {
                    res+=symbol[i];
                    num-=values[i];
                    break;
                }
            }
        }
        return res;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.intToRoman(3749);

    return 0;
}

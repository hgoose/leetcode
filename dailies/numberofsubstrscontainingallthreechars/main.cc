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

template<typename T, typename U>
using pmap = unordered_map<T,U>;

template<typename T>
using pset = unordered_set<T>;

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

template<typename T>
using lims = std::numeric_limits<T>;

class Solution {
public:
    int numberOfSubstrings(string s) {
        bitset<3> need(0);        
        vector<int> count(3,0);

        int tt = s.size() + 1, right{}, left{}, total{}, n = s.size();
        while (--tt) {
            need[s[right] - 97] = 1;
            ++count[s[right] - 97];

            while (need.all()) {
               total+=n-right;
               --count[s[left] - 97];
               if (count[s[left] - 97] == 0) {
                   need[s[left] - 97] = 0;
               }
               ++left;
            }


            ++right;
        }
        return total;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.numberOfSubstrings("abcabc");

    return 0;
}

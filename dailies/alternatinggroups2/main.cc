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
#include <climits> // INT_MAX, INT_MIN, ...
#include <tuple>
#include <unordered_set>
#include <algorithm>
#include <stack>
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
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int kcliques{}, n = colors.size() + (k-1), l{};
        for (int i=0; i<k-1; ++i) {
            colors.push_back(colors[i]);
        }

        for (int i=0; i<n; ++i) {
            if (i > 0 && colors[i] == colors[i-1]) {
                l = i;
            }

            if (i-l+1 >= k)  {
                ++kcliques;
            }
        }
        return kcliques;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> v{0,1,0,1,0};

    // cout << std::boolalpha << s.cliqueCheckerLeft(v,2,4,6);

    cout << s.numberOfAlternatingGroups(v,3) << endl;

    return 0;
}

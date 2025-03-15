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
    int removeDuplicates(vector<int>& nums) {
        int j=0;
        for (const auto& e : nums) {
            if (j<2 || e>nums[j-2]) {
                nums[j++] = e;
            }
        }
        return j;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> v{1,1,1,2,2,3};
    for (int i=0; i<s.removeDuplicates(v); ++i) {
        cout << v[i] << " ";
    }

    return 0;
}

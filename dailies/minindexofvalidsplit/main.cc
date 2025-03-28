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
    int minimumIndex(vector<int>& nums) {
        pmap<int,int> lmap, rmap;
        for (auto& e : nums) { ++rmap[e]; }

        for (int i=0; i<(int)nums.size(); ++i) {
            --rmap[nums[i]], ++lmap[nums[i]];

            if (rmap[nums[i]] > (nums.size()-i)/2 && lmap[nums[i]] > (i+1)/2) return i;
        }
        return -1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> v{2,1,3,1,1,1,7,1,2,1};



    return 0;
}

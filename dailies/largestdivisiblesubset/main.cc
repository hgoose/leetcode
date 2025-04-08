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

typedef vector<vector<int>> VII;
typedef vector<int> VI;
struct TreeNode;
struct ListNode;
typedef ListNode ln;
typedef TreeNode tn;
#define PB push_back

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        map<pair<int,int>, vector<int>> memo;
        return _solve(nums,0,1,memo);

    }
private:
    vector<int> _solve(VI& v, int idx, int prev, map<pair<int,int>, vector<int>>& memo) {
        if (idx >= v.size()) {
            return {};
        }
        if (memo.find({idx, prev}) != memo.end()) {
            return memo[{idx, prev}];
        }

        vector<int> res;
        if (v[idx] % prev == 0) {
            res = {v[idx]};
            vector<int> other = _solve(v, idx+1, v[idx], memo);
            res.reserve(res.size() + other.size());
            res.insert(res.end(), other.begin(), other.end());

        }
        vector<int> tmp = _solve(v, idx+1, prev, memo);
        if (tmp.size() > res.size()) res = tmp;

        memo[{idx, prev}] = res;

        return res;
    }
};

int main(int argc, char** argv) {

    return 0;
}

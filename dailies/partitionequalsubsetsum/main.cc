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
#include <ranges>
using std::accumulate;
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


typedef vector<vector<int>> VII;
struct TreeNode;
struct ListNode;
typedef ListNode ln;
typedef TreeNode tn;
#define PB push_back

class Solution {
public:
    bool fun(int idx, int target, std::vector<int>& nums, std::vector<std::vector<int>>& memo) {
        if (target == 0) return true;
        if (idx == nums.size() || target < 0) return false;

        if (memo[idx][target] != -1) return memo[idx][target];

        bool include = fun(idx + 1, target - nums[idx], nums, memo);
        bool exclude = fun(idx + 1, target, nums, memo);

        memo[idx][target] = include || exclude;

        return memo[idx][target];
    }

    bool canPartition(std::vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        
        int target = sum / 2;
        std::vector<std::vector<int>> memo(nums.size(), std::vector<int>(target + 1, -1));
        return fun(0, target, nums, memo);
    }
};

int main(int argc, char** argv) {

    return 0;
}

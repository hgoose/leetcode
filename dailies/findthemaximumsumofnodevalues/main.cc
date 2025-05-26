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

typedef priority_queue<int, vector<int>, std::greater<int>> I_MIN_HEAP;
typedef priority_queue<int, vector<int>> I_MAX_HEAP;

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
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int initial = std::accumulate(nums.begin(), nums.end(), 0);       
        vector<int> change(nums.size(), 0);

        for (int i=0; i<(int)nums.size(); ++i) {
            change[i] = (nums[i] ^ k) - nums[i];
        }

        vector<bool> changed(nums.size(),0);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (change[u] + change[v] > 0) {
                if (!changed[u]) {
                    nums[u] = change[u] + nums[u];
                    changed[u] = 1;
                }
                if (!changed[v]) {
                    nums[v] = change[v] + nums[v];
                    changed[v] = 1;
                }
            }
        }
        return std::accumulate(nums.begin(), nums.end(),0);
    }
};

int main(int argc, char** argv) {

    return 0;
}

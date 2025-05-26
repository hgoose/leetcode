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

template<typename T, typename U>
using pmap = unordered_map<T,U>;

typedef vector<vector<int>> VII;
typedef vector<int> VI;
struct TreeNode;
struct ListNode;
typedef ListNode ln;
typedef TreeNode tn;
#define PB push_back

typedef priority_queue<int, vector<int>, std::greater<int>> I_MIN_HEAP;
typedef priority_queue<int, vector<int>> I_MAX_HEAP;
class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        std::sort(queries.begin(), queries.end(), [](auto& x, auto& y) {
            return x[0] < y[0];
        });

        I_MIN_HEAP used;
        I_MAX_HEAP avail;
        
        int qp = 0, applied = 0;
        for (int i=0; i<(int)nums.size(); ++i) {
            while (qp < queries.size() && queries[qp][0] == i) {
                avail.push(queries[qp][1]);
                ++qp;
            }
            nums[i] -= used.size();

            while (nums[i] > 0 && avail.size() && avail.top() >= i) {
                used.push(avail.top());
                avail.pop();
                --nums[i];
                ++applied;
            }

            if (nums[i] > 0) return -1;

            while (used.size() && used.top() == i) {
                used.pop();
            }
        }

        return queries.size() - applied;
    }
};

int main(int argc, char** argv) {

    return 0;
}

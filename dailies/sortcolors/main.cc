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
    void sortColors(vector<int>& nums) {
        vector<int> cnts(3,0);
        vector<int> pfx(3,0);
        vector<int> cpy = nums;
        for (auto& e : nums) {
            ++cnts[e];
        }
        
        pfx[0] = cnts[0];
        for (int i=1; i<(int)cnts.size(); ++i) {
            pfx[i] = pfx[i-1] + cnts[i];
        }

        for (int i=cpy.size()-1; i>=0; --i) {
            int pos = pfx[cpy[i]]-1;
            nums[pos] = cpy[i];
            --pfx[cpy[i]];
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> v{2,0,2,1,1,0};

    s.sortColors(v);

    for (auto& e : v) {
        cout << e << " ";
    }

    return 0;
}

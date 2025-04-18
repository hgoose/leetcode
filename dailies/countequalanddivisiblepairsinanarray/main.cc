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

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int cnt = 0;
        for (int i=0; i<(int)nums.size()-1; ++i) {
            for (int j = i+1; j<(int)nums.size(); ++j) {
                if (nums[j] != nums[i]) continue;
                if ((i * j) % k == 0)  {
                    ++cnt;
                }
            }
        }       
        return cnt;
    }
};

int main(int argc, char** argv) {
    Solution s;
    int k = 2;
    vector<int> v{3,1,2,2,2,1,3};

    cout << s.countPairs(v,k);

    return 0;
}

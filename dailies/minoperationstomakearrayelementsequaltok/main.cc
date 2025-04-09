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
typedef vector<int> VI;
struct TreeNode;
struct ListNode;
typedef ListNode ln;
typedef TreeNode tn;
#define PB push_back

template<typename T, typename U>
using pmap = unordered_map<T,U>;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ops = 0;
        pmap<int,bool> seen;
        bool all = true;
        for (auto& e : nums) {
            if (e != k) all = false;
            if (e < k) return -1;
            if (!seen.count(e) && e > k) {
               ++ops; 
            }
            seen[e] = 1;
        }
        if (ops == 0) {
            if (all) return 0;
            return -1;
        }
        return ops;
    }
};


int main(int argc, char** argv) {

    return 0;
}

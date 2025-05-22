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
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> D{nums[0]};
        for (int i=1; i<(int)nums.size(); ++i) {
            D[i] = nums[i] - nums[i-1];
        }
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            D[l]+=1;
            if (r+1 < nums.size()) D[r+1]-=1;
        }
        nums[0] = D[0];
        for (int i=1; i<(int)D.size(); ++i) {
            nums[i] = nums[i-1] + D[i];
        }
        return _check(nums);
    }
private:
    bool _check(vector<int>& v) {
        for (auto& e : v) {
            if (e>0) return false;
        }
        return true;
    }
};

int main(int argc, char** argv) {

    return 0;
}

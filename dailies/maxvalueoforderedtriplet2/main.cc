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

#define ll long long
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
       int n = nums.size();         
       vector<int> lmax(n), rmax(n);

       for (int i=1; i<n; ++i) {
           lmax[i] = std::max(lmax[i-1], nums[i-1]);
           rmax[n-i-1] = std::max(rmax[n-i], nums[n-i]);
       }


       ll max = 0;
       for (int j=1; j<n-1; ++j) {
           max = std::max(max, (ll)(lmax[j] - nums[j]) * rmax[j]);
       }
       return max;
    }
};

int main(int argc, char** argv) {

    return 0;
}

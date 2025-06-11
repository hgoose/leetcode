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

#define ll long long
class Solution {
public:
    int findKthNumber(int n, int k) {
        int c = 0;
        for (int i=1; i<=9; ++i) {
            int ans = _solve(i,n,k,c);
            if (ans) return ans;
        }
        return 0;
    }
private:
    int _solve(ll curr, int n, int k, int& c) {
        if (curr > n) return 0;
        if (++c == k) {
            return curr;
        }
        for (int i=0; i<=9; ++i) {
            ll ell = curr * 10 + i;
            if (ell > n) break;
            int res = _solve(ell, n, k, c);
            if (res) return res;
        }
        return 0;
    }
};

int main(int argc, char** argv) {

    return 0;
}

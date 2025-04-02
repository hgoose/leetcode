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

typedef vector<int> VI;
struct TreeNode;
struct ListNode;
typedef ListNode ln;
typedef TreeNode tn;
#define PB push_back


#define ll long long
typedef vector<vector<int>> VII;
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<ll> memo(questions.size(),0);
        return _bt(questions, 0,memo);
    }
private:
    long long _bt(VII& q, int start, vector<ll>& memo) {
        if (start >= q.size()) return 0;
        if (memo[start]) return memo[start];

        int points = q[start][0], bp = q[start][1];
        memo[start] = (ll)std::max((ll)_bt(q,start+1, memo), (ll)points+(ll)_bt(q,start+bp+1, memo));
        return memo[start];
    }
};

int main(int argc, char** argv) {
    Solution s;
    VII v{{1,1},{2,2},{3,3},{4,4},{5,5}};

    cout << s.mostPoints(v);
    


    return 0;
}

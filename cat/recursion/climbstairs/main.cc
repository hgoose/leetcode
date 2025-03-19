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

const int N = 45;

class Solution {
public:
    int memo[N+1];

    Solution() {
        std::fill(memo, memo + (N+1), 0);
        memo[1] = 1;
        memo[2] = 2;
    }

    int climbStairs(int n) {
        if (n==1)return memo[1];
        if (n==2) return memo[2];

        if (memo[n-1] && memo[n-2]) {
            return memo[n-1] + memo[n-2];
        }
        memo[n-1] = climbStairs(n-1);
        memo[n-2] = climbStairs(n-2);

        return memo[n-1] + memo[n-2];
    }
};

int main(int argc, char** argv) {

    return 0;
}

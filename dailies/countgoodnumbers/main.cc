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

#define ll long long
const int MOD = 1e9 + 7;
class Solution {
public:
    int countGoodNumbers(long long n) {
        ll even = (n+1)/2;
        ll prime = n/2;

        return (modExp(5,even, MOD) * modExp(4,prime,MOD)) % MOD;
    }
private:
    #define ll long long
    ll modExp(ll a, ll b, ll mod) {
        ll result = 1;
        a %= mod;
        while (b > 0) {
            if (b & 1)
                result = (result * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    ll n = 50;
    cout << s.countGoodNumbers(n);


    return 0;
}

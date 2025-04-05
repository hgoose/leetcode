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
struct TreeNode;
struct ListNode;
typedef ListNode ln;
typedef TreeNode tn;
#define PB push_back

typedef vector<int> VI;
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sum = 0, res = 0;
        _solve(nums,sum,res,0);
        return res;
    }
private:
    void _solve(VI& V, int& sub, int& res, int i) {
        if (i >= V.size()) {
            res+=sub;
            return;
        }

        sub ^= V[i];
        _solve(V,sub,res,i+1);

        // Xor is its own inverse,
        // if a xor b = c, then c xor b = a
        //                a xor b xor b = a
        //                implies     a = a, since b xor b = 0 and a xor 0 = a []
        sub^=V[i];
        _solve(V,sub,res,i+1);
    }
};

int main(int argc, char** argv) {

    return 0;
}

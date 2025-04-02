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

#define ll long long
typedef vector<int> VI;
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        ll max = 0;
        VI comb;
        _comb(nums, 0, comb, max);
        return max;
    }
private:
    void _comb(VI& V, int r, VI& comb, ll& max) {
        if (comb.size() == 3) {
            ll v = ((ll)comb[0] - (ll)comb[1]) * comb[2];
            max = std::max((ll)max, (ll)v);
            return;
        }

        for (int i=r; i<(int)V.size(); ++i) {
            comb.push_back(V[i]);
            _comb(V,i+1, comb, max);
            comb.pop_back();
        }
    }
};

int main(int argc, char** argv) {

    return 0;
}

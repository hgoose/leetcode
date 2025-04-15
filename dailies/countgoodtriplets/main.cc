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
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int count = 0;
        int n = arr.size();
        vector<int> pfx_cnt(1001,0);

        for (int j=0; j<n; ++j) {
            for (int k=j+1; k<n; ++k) {
                if (abs(arr[j]) - abs(arr[k]) <= b) {
                    int l = std::max(arr[j] - a, arr[k] - c);
                    int r = std::min(a+arr[j], c+arr[k]);
                    l = std::max(l, 0);
                    r = std::min(r, 1000);

                    if (l<=r) {
                        count+=pfx_cnt[r] - (l-1 >= 0 ? pfx_cnt[l-1] : 0);
                    }
                }
            }
            for (int i = arr[j]; i<1001; ++i) {
                ++pfx_cnt[i];
            }
        }
        return count;
    }
};

int main(int argc, char** argv) {

    Solution s;
    vector<int> v{3,0,1,1,9,7};
    cout << s.countGoodTriplets(v,7,2,3);
    return 0;
}

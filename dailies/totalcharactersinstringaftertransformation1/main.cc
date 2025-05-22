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

#define mod 1000000007
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> cfreq(26,0), nfreq(26,0);

        for (int i=0; i<(int)s.size(); ++i) {
            ++cfreq[s[i]-97];
        }

        while (t--) {
            nfreq = vector<int>(26,0);
            for (int i=0; i<26; ++i) {
                if (i == 25) {
                    nfreq[0] = cfreq[25];
                    nfreq[1] = ((nfreq[1] % mod) + (cfreq[25] % mod)) % mod;
                } else {
                    nfreq[i+1] = cfreq[i];
                }
            }
            cfreq = nfreq;
        }

        int cnt = 0;
        for (int i=0; i<26; ++i) {
            cnt=((cnt % mod) + (cfreq[i] % mod)) % mod;
        }
        return cnt;
    }
};


int main(int argc, char** argv) {
    Solution s;
    string str = "abcyy";
    int t = 2;

    cout << s.lengthAfterTransformations(str, t);


    return 0;
}

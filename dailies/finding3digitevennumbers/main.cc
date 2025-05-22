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


typedef vector<vector<int>> VII;
typedef vector<int> VI;
struct TreeNode;
struct ListNode;
typedef ListNode ln;
typedef TreeNode tn;
#define PB push_back

template<typename T, typename U>
using pmap = unordered_map<T,U>;
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ret;
        vector<int> have(10,0);
        for (auto& e : digits) {
            ++have[e];
        }
        for (int i=100; i<1000; ++i) {
            int n = i, last{};
            bool l = true;
            vector<int> curr(10,0);
            while (n != 0) {
                ++curr[n%10];
                if (l) {
                    last = n%10;
                    l = false;
                }
                n/=10;
            }

            if (_check(have, curr, last)) {
                ret.push_back(i);
            }

        }
        std::sort(ret.begin(), ret.end());
        return ret;
    }
private:
    bool _check(vector<int>& have, vector<int>& curr, int last) {
        for (int j=0; j<(int)curr.size(); ++j) {
            if (curr[j] == 0) continue;
            if (curr[j] > have[j]) return false;
        }
        return last % 2 == 0;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> v{2,1,3,0};
    s.findEvenNumbers(v);

    return 0;
}

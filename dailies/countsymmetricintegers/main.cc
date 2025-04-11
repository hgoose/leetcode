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
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i=low; i<=high; ++i) {
            string full, left, right;
            full = std::to_string(i); int n = full.size();
            if (n % 2 != 0) continue;
            left = full.substr(0,n/2), right = full.substr(n/2);

            int leftsum=0, rightsum=0;
            for (int i = 0; i < left.size(); ++i) {
                leftsum+=left[i] - 48;
                rightsum+=right[i] - 48;
            }
            if (leftsum == rightsum) ++count;
        }
        return count;
    }
};

int main(int argc, char** argv) {

    return 0;
}

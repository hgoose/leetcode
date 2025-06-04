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

typedef std::unordered_map<int, vector<int>> List;
class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        List l1, l2;
        vector<int> ret;

        int n = 0;
        for (auto& edge : edges1) {
            n = std::max(n,edge[0]); n = std::max(n, edge[1]); ++n;
            l1[edge[0]].push_back(edge[1]);
            l1[edge[1]].push_back(edge[0]);
        }
        int m = 0;
        for (auto& edge : edges2) {
            m = std::max(m,edge[0]); m = std::max(n, edge[1]); ++m;
            l2[edge[0]].push_back(edge[1]);
            l2[edge[1]].push_back(edge[0]);
        }

        for (auto& [node, _] : l1) {
            vector<bool> visited(n,0);
            int m1 = 0;
            _dfs(l1, node, visited, 0, m1, k);

            for (auto& [n, _] : l2) {
            }
        }

        return ret;
    }
private:
    void _dfs(List& l, int curr, vector<bool>& visited, int edges, int& max, int k, bool le=true) {
        visited[curr] = 1;
        ++edges;
        if (le) {
            if (edges <= k) ++max;
        } else {
            if (edges < k) ++max;
        }

        for (auto& neighbor : l[curr]) {
            _dfs(l, neighbor, visited, edges+1, max, k, le); 
        }

    }
};

int main(int argc, char** argv) {

    return 0;
}

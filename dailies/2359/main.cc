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

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        if (node1 == node2) return node1;
        vector<int> dist1(edges.size(), -1), dist2(edges.size(), -1);
        vector<bool> visited1(edges.size(), 0), visited2(edges.size(),0);
        // dist1[node1] = 0, dist2[node2] = 0;
        _dfs(edges, node1, dist1,0, visited1);
        _dfs(edges, node2, dist2,0, visited2);

        int min = INT_MAX, ret = 0;
        for (int i=0; i<(int)dist1.size(); ++i) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                if (std::max(dist1[i], dist2[i]) < min) {
                    min = std::max(dist1[i], dist2[i]);
                    ret = i;
                }
            }
        }
        return ret;
    }
private:
    void _dfs(vector<int>& edges, int curr, vector<int>& dists, int dist, vector<bool>& visited) {
        if (curr == -1) return;
        if (visited[curr]) return;
        visited[curr] = 1;
        dists[curr] = dist;
        _dfs(edges, edges[curr], dists, dist+1, visited);
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> v{2,2,3,-1};
    int n1 = 0, n2 = 1;
    vector<int> d1(v.size(),-1), d2(v.size(),-1);
    s._dfs(v,n1,d1,0);
    s._dfs(v,n2,d2,0);

    for (auto& e : d1) cout << e << " ";
    cout << endl << endl;

    for (auto& e : d2) cout << e << " ";
    cout << endl;


    return 0;
}

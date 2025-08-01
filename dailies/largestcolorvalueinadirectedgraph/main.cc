#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <utility>
#include <cmath>
#include <bitset>
#include <set>
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

typedef std::unordered_map<int, std::unordered_set<int>> List;
enum color : short {WHITE=0, GREY=1, BLACK=2};
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        List list;
        for (auto& edge : edges) {
            list[edge[0]].insert(edge[1]);
        }

        vector<int> cnt(26,0);
        vector<color> visited(colors.size(), WHITE);

        for (auto& [node, _] : list) {
            if (visited[node] == WHITE) {
                if (!_dfs(list, visited, node, cnt, colors)) return -1;
            }
        }

        int max = 0;
        for (int i=0; i<26; ++i) {
            max = std::max(max, cnt[i]);
        }

        return max;
         
    }
private:
    bool _dfs(List& list, vector<color>& visited, int curr, vector<int>& cnt, const string& colors) {
        visited[curr] = GREY;

        for (auto& neighbor : list[curr]) {
            if (visited[neighbor] == WHITE) {
                if (!_dfs(list, visited, neighbor, cnt, colors)) return false;
            } else if (visited[neighbor] == GREY) {
                return false;
            }
        }

        visited[curr] = BLACK;
        ++cnt[colors[curr] - 'a'];
        return true;
    }
};

int main(int argc, char** argv) {

    Solution s;
    vector<vector<int>> e = {{0,1}, {0,2}, {2,3}, {3,4}};
    string colors = "abaca";

    cout << s.largestPathValue(colors, e);

    return 0;
}

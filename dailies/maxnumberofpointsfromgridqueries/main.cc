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


template<typename T>
using lims = std::numeric_limits<T>;

template<typename T, typename U>
using pmap = unordered_map<T,U>;

typedef vector<vector<int>> VII;
typedef vector<int> VI;
typedef vector<pair<int,int>> VPII;
#define PB push_back
#define all(i) int i=0; i<n; ++i

struct comp {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a[0] > b[0];
    }
};

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        const int rl = grid.size(), cl = grid[0].size();
        vector<int> R(queries.size(),0);
        vector<pair<int,int>> qp;
        for (int i=0; i<(int)queries.size(); ++i) {
            qp.push_back({queries[i], i});
        }
        std::sort(qp.begin(), qp.end(), [](auto x, auto y)->bool {
            return x.first < y.first;
        });
        pq<vector<int>, vector<vector<int>>, comp> q;
        vector<bool> visited(grid.size()*grid[0].size(), 0);
        const vector<pair<int,int>> dirs{{1,0}, {-1,0}, {0,1}, {0,-1}};

        q.push({grid[0][0], 0, 0});
        visited[0] = 1;
        int points = 0;
        for (const auto& [query, position] : qp) {
            while (q.size() && q.top()[0] < query) {
                vector<int> top = q.top();
                ++points;
                int row = top[1], col = top[2];
                q.pop();
                for (const auto& [dr, dc] : dirs) {
                    if (ib(row+dr, col+dc, rl, cl) && !visited[cl*(row+dr)+(col+dc)])  {
                        q.push({grid[row+dr][col+dc], row+dr, col+dc});
                        visited[cl*row+col] = 1;
                    }
                }

            }
            R[position] = points;
        }
        return R;
    }
private:
    static bool ib(int r, int c, int rl, int cl) {
        return (r >=0 && r < rl && c >= 0 && c < cl);
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<vector<int>> grid{{1,2,3},{2,5,7},{3,5,1}};
    vector<int> q{5,6,2};

    vector<int> res = s.maxPoints(grid,q); 
    for (auto& e : res) cout << e << " ";


    return 0;
}

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

struct CupFind {
    vector<int> parent;
    vector<int> rank;

    CupFind(int n) : parent(n), rank(n,1) { 
        for (int i=0; i<n; ++i) {
            parent[i] = i;
        }
    }

    int find(int n) {
        if (parent[n] != n) {
            parent[n] = find(parent[n]);
        }
        return parent[n];
    }

    void cup(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px != py) {
            if (rank[py] < rank[px]) {
                parent[py] = px;
            } else if (rank[px] < rank[py]) {
                parent[px] = py;
            } else {
                parent[py] = px;
                ++rank[px];
            }
        }
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        CupFind cf(n);    

        for (const auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            cf.cup(u,v);
        }

        pmap<int,int> umap;
        for (const auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            int root = cf.find(u);

            if (umap.find(root) == umap.end()) {
                umap[root] = w;
            } else {
                umap[root] &= w;
            }
        }

        vector<int> res;
        for (const auto& q : query) {
            int u = q[0], v = q[1];

            int ru = cf.find(u), rv = cf.find(v);

            if (ru != rv) {
                res.push_back(-1);
            } else {
                res.push_back(umap[ru]);
            }
        }
        return res;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<vector<int>> edges {{0,1,7},{1,3,7},{1,2,1}};
    vector<vector<int>> queries {{0,3}, {3,4}};

    vector<int> r = s.minimumCost(5,edges, queries);



    return 0;
}

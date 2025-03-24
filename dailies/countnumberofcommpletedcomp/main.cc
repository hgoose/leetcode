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

struct cupfind {
    vector<int> parent;
    vector<int> rank;
    cupfind(int n) : parent(n),rank(n,1) {
        for (int i=0; i<n; ++i) parent[i] = i;

    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void cup(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (rank[py] < rank[px]){
            parent[py] = px;
        } else if (rank[px]  < rank[py]) {
            parent[px] = py;
        } else {
            parent[py] = px;
            ++rank[parent[px]];
        }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        cupfind cf(n);

        pmap<int,int> deg;
        for (const auto & e : edges) {
            int u = e[0], v = e[1];
            ++deg[u]; ++deg[v];
            cf.cup(u,v);
        }

        pmap<int, int> comps_size;
        pmap<int, vector<int>> comps;
        for (int i=0; i<cf.parent.size(); ++i) {
            ++comps_size[cf.parent[i]];
            comps[cf.parent[i]].push_back(i);
        }

        for (const auto& [key,value] : comps) {
            cout << "Key: " << key << endl;
            for (const auto& e : value) {
                cout << e << " ";
            }
            cout << endl;
        }

        int ret = 0;
        for (const auto& [key, value] : comps) {
            int size = comps_size[key];
            bool all = true;
            for (const auto& e : value) {
                if (deg[e] != (size-1)) all = false;
            }
            if (all) ++ret;
        }
        return ret;

    }
};

int main(int argc, char** argv) {
    Solution s;
    int n =6;
    vector<vector<int>> e{{0,1},{0,2},{1,2},{3,4},{3,5}};

    cout << s.countCompleteComponents(n,e);

    return 0;
}

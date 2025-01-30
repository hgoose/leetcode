#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::string;
using std::vector;
using std::endl;

#include <ranges>
struct CupFind {
    vector<int> parent, rank;

    CupFind(int n) : parent(n+1), rank(n+1,1) {
        for (const auto& i : std::ranges::views::iota(0,n+1)) 
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        } return parent[x];
    }

    bool cup(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        else {
            if (rank[py] > rank[px]) {
                parent[py] = px;
            } else if (rank[px] > rank[py]){
                parent[px] = py;
            } else {
                parent[py] = px;
                ++rank[px];
            }
        }
        return true;
    }

    // void cup(int x, int y) {
    //     int px = find(x), py = find(y);
    //     if (px != py) {
    //         parent[py] = px;
    //     }
    // }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        CupFind cf((int)edges.size());
        for (const auto& item : edges) {
            int u = item[0], v = item[1];
            
            if (!cf.cup(u,v)) return {u,v};

            // if (cf.find(u) != cf.find(v)) {
            //     cf.cup(u,v);
            // } else {
            //     return {u,v};
            // }
        }
        return {};
    }
};

int main(int argc, char** argv) {

    return 0;
}

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

template<typename T, typename U>
using pmap = unordered_map<T,U>;

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

template<typename T>
using lims = std::numeric_limits<T>;

class Solution {
    vector<int> bp;
    void dfs(vector<vector<int>>& adj, int bob, int alice, vector<int>& amount, int& total, int& greatest, vector<bool>& visited) {
        int alice_amount = (alice == bob ? amount[alice]/2 : amount[alice]);
        int bob_amount = (alice == bob ? amount[bob]/2 : amount[bob]);;
        total+=alice_amount;
        amount[bob] = 0;
        amount[alice] = 0;
        visited[alice] = true;
        for (int i=0; i<(int)adj[alice].size(); ++i) {
            if (!visited[adj[alice][i]]) {
                dfs(adj, bob==0?0:bp[bob], adj[alice][i], amount, total, greatest, visited); 
            }
        }
        if (adj[alice].size() == 1 && alice != 0 && total > greatest) greatest = total;
        total-=alice_amount;
        amount[bob] += bob_amount;
        amount[alice] += alice_amount;

    }
    bool _bobs_path(vector<vector<int>>& adj, int bob,int cameFrom) {
        if (bob == 0) return true;
        for (int i=0;i<(int)adj[bob].size();++i) {
            if (adj[bob][i] != cameFrom) {
                if(_bobs_path(adj,adj[bob][i], bob)) {
                    bp[bob] = adj[bob][i];
                    return true;
                }
            }
        }
        return false;
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        vector<vector<int>> adj(amount.size());
        for (int i=0; i<(int)edges.size(); ++i) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        bp = vector<int>(amount.size(), -1);
        _bobs_path(adj,bob,bob);

        vector<bool> visited(amount.size(), 0);
        int greatest = lims<int>::min();
        int total{};
        dfs(adj, bob, 0, amount, total, greatest, visited);
        return greatest;
    }
};


int main(int argc, char** argv) {

    Solution s;
    vector<vector<int>> edges {
        {0,2},
        {0,5},
        {1,3},
        {1,5},
        {2,4}
    };

    vector<int> amount{5018,8388,6224,3466,3808,3456};
    cout << s.mostProfitablePath(edges,4,amount);


    return 0;
}

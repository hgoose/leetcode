#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <utility>
#include <cmath>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;
using std::queue;
using std::priority_queue;
typedef long long dword;

template<typename T, typename U>
using pmap = unordered_map<T,U>;

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

class Solution {
public:
    void _combine(vector<vector<int>>& res, vector<int>& comb, const int& n, const int& k, const int& j) {
        if (static_cast<int>(comb.size()) == n) {
            res.push_back(comb);
            return;
        }

        for (int i=j; i<=n; ++i) {
            comb.push_back(j);
            _combine(res, comb, n,k, i+1);
            comb.pop_back();
        }
    }
    vector<vector<int>> combine(const int& n, const int& k) {
        vector<vector<int>> res;
        vector<int> comb;
        _combine(res,comb,n,k,0);
        return res;
    }
};

int main(int argc, char** argv) {

    return 0;
}

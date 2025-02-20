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

class Solution {
public:
    void _comb(vector<int>& A, vector<vector<int>>& res, vector<int>& comb, const int& target, const int& j, const int& currsum) {
        if (currsum == target) {
            res.push_back(comb);
        }
        // if (currsum > target) return; 

        for (int i=j; i<(int)A.size(); ++i) {
            if (currsum + A[i] <= target) {
                comb.push_back(A[i]);
                _comb(A,res,comb,target, i+1, currsum + A[i]);
                comb.pop_back();
                while (((i+1) < A.size()) &&A[i] == A[i+1]) ++i;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, const int& target) {
        vector<vector<int>> res;
        vector<int> comb;
        std::sort(candidates.begin(), candidates.end());
        _comb(candidates, res, comb, target, 0,0);
        return res;
    }
};

int main(int argc, char** argv) {

    return 0;
}

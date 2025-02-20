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
    void _permute(const vector<int>& nums, vector<vector<int>>& res, vector<int>& perm, vector<bool>& used) {
        if (static_cast<int>(perm.size()) == nums.size() ) {
            res.push_back(perm);
            return;
        }

        for (int i=0; i<(int)nums.size(); ++i) {
            if (!used[i]) {
                perm.push_back(nums[i]);
                used[i] = true;
                _permute(nums, res, perm, used);
                perm.pop_back();
                used[i] = false;
            }
        }

    }
    vector<vector<int>> permute(const vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> perm;
        vector<bool> used(nums.size(),0);
        _permute(nums, res, perm, used);
        return res;
    }
};

int main(int argc, char** argv) {

    return 0;
}

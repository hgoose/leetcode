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
    void r_subsets(vector<int>& nums, vector<vector<int>>& res, vector<int>& subset, int i) {
        if (i>=nums.size()) {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        r_subsets(nums,res,subset, i+1);
        subset.pop_back();

        while ( ((i+1) < (int)nums.size()) && (nums[i] == nums[i+1])) {
            ++i;
        }
        r_subsets(nums,res,subset, i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> subset;
        r_subsets(nums,res,subset,0);
        return res;
    }
};

int main(int argc, char** argv) {

    return 0;
}

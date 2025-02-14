#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <queue>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;
using std::priority_queue;
typedef long long dword;

template<typename T, typename U>
using pmap = unordered_map<T,U>;

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        std::map<vector<int>, int> umap;
        std::sort(nums.begin(), nums.end());

        for (int i=0; i<(int)nums.size(); ++i) {
            auto left = nums.begin() + (i+1), right = nums.end()-1;
            while (left < right) {
                int target = nums[i];

                if (-(*left + *right) == target) {
                    if (umap[{target, *left, *right}] == 0) {
                        res.push_back({target,*left, *right});
                        ++umap[res.back()];
                    }
                    ++left, --right;
                } else if ((*left + *right) > target) {
                    --right;
                } else ++left;
            }
        }
        return res;
    }
};

int main(int argc, char** argv) {

    return 0;
}

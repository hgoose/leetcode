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
    void r_subsets(vector<int>& nums, vector<vector<int>>& res, vector<int>& s, const int& start)  {
        if (s.size() <= nums.size()) {
            res.push_back(s);
        }

        for (int i=start; i<(int)nums.size(); ++i) {
            s.push_back(nums[i]);
            r_subsets(nums,res,s,i+1);
            s.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res{};
        vector<int> s;
        r_subsets(nums,res,s,0);
        return res;
    }
};

int main(int argc, char** argv) {

    return 0;
}

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
#include <tuple>
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

template<typename T, typename U>
using pmap = unordered_map<T,U>;

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;


class Solution {
public:

    template<typename T>
    using lims = std::numeric_limits<T>;
    int inf = lims<int>::max();

    void _bt(vector<int>& nums, int& cost, int& gmin) {
        vector<int> tmp = nums;
        if (nums.size() >= 3) {
            for (int i=0; i<=2; ++i) {
                for (int j=i+1; j<=2; ++j) {
                    if ((cost + std::max(nums[i], nums[j])) > gmin) {
                        continue;
                    }
                    int save_i = tmp[i], save_j = tmp[j];
                    tmp.erase(tmp.begin()  + i); tmp.erase(tmp.begin() + (j-1));
                    cost+=std::max(save_i, save_j);
                    _bt(tmp, cost, gmin);
                    cost-=std::max(save_i, save_j);
                    tmp = nums;
                }
            }
        } else {
            if (nums.empty()) {
                if (cost < gmin) gmin = cost;
                return;
            }
            int tmpcost = cost;
            tmpcost += [&]() -> int {
                int max = nums[0];
                for (int i=1; i<(int)nums.size(); ++i) {
                    if (nums[i] > max) max = nums[i];
                }
                return max;
            }();

            if (tmpcost < gmin) gmin = tmpcost;
            return;
        }
    }
    int minCost(vector<int>& nums) {
        int cost{}, gmin = inf;
        _bt(nums,cost, gmin);
        return gmin;
    }
};

int main(int argc, char** argv) {

    vector<int> v{83,47,66,24,57,85,16,20,79,5,35,18,28,67,22,95,84,50,59,43,30,1,69,99,65,43,23,75,40,8,78,32,32,99,58,78,34,91,69,82,21,46,81,75,7,75,77,28,96,92,85,74,99,39,11,57,88,17,3,33};
    Solution s;
    cout << s.minCost(v);

    return 0;
}

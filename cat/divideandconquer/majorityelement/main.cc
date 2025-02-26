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

template<typename T>
using lims = std::numeric_limits<T>;

class Solution {
public:
    tuple<int, int> _dc(vector<int>& nums, int l, int r) {
        if (l == r) {
            return {nums[l],1};
        }
        int mid = (l + r) / 2;

        auto [lnum, lcount] = _dc(nums, l, mid);
        auto [rnum, rcount] = _dc(nums, mid+1, r);

        return [&]() -> std::tuple<int,int> {
            if (lnum == rnum) return {lnum, lcount + rcount};

            if (lcount == rcount) {
                return {0,0};
            } else if (lcount - rcount > 0) {
                return {lnum, lcount-rcount};
            } else {
                return {rnum, rcount-lcount};
            }
        }();
    }
    int majorityElement(vector<int>& nums) {
        return std::get<0>(_dc(nums,0,nums.size()-1));
    }
};

int main(int argc, char** argv) {

    vector<int> v{8,8,7,7,7};
    Solution s;
    cout << s.majorityElement(v);

    return 0;
}

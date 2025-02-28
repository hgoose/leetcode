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
    int maxSubArray(vector<int>& nums) {
       return _dc(nums, 0, nums.size()-1);
    }
private:
    int _dc(vector<int>& nums, int l, int r) {
        if (l == r) {
            return nums[l];
        }

        int mid = (l + r) / 2;
        int left_sum = _dc(nums, l, mid);
        int right_sum = _dc(nums, mid+1, r);
        int cross_sum = max_crossing(nums, l, r);

        return [&]() -> int {
          int max = left_sum;  
          if (right_sum > max) max = right_sum;
          if (cross_sum > max) max = cross_sum;
          return max;
        }();
    }
    int max_crossing(vector<int>& nums, int start, int end) {
        int mid = (start + end) / 2;
        
        int max_left = lims<int>::min();
        int sum{};
        for (int i=mid; i>=start; --i) {
            sum+=nums[i];  
            max_left = std::max(sum, max_left);
        }

        int max_right = lims<int>::min();
        sum = 0;
        for (int i=mid+1; i<=end; ++i) {
            sum+=nums[i];
            max_right = std::max(max_right, sum);
        }
        return max_left + max_right;
    }
};


int main(int argc, char** argv) {
    Solution s;
    vector<int> v{5,4,-1,7,8};
    cout << s.maxSubArray(v) << endl;

    return 0;
}

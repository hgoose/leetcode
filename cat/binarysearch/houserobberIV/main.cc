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
#include <numeric> // std::accumulate
#include <climits> // INT_MAX, INT_MIN, ...
#include <tuple>
#include <unordered_set>
#include <algorithm>
#include <stack>
using std::pair;
using std::stack;
using std::unordered_set;
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

template<typename T>
using pset = unordered_set<T>;

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

template<typename T>
using lims = std::numeric_limits<T>;

template<typename T, typename U>
using pmap = unordered_map<T,U>;

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int left = *std::min_element(nums.begin(), nums.end());
        int right = *std::max_element(nums.begin(), nums.end());

        int res = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (steal(nums, mid, k)) {
                res = mid;
                right = mid-1;
            } else left = mid+1;
        }
        return res;
    }
    bool steal(vector<int>& nums, int cap, int k) {
        int count = 0;
        for (int i=0; i<(int)nums.size(); ++i) {
            if (nums[i] <= cap) {
                i+=1;
                ++count;
            }

            if (count == k) break;
        }
        return count == k;
    }
};


int main(int argc, char** argv) {

    Solution s;
    vector<int> v{2,7,9,3,1};

    return 0;
}

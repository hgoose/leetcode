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
    int search(vector<int>& nums, int target) {
        // Find pivot point
        int left = 0, right = nums.size()-1;
        int pivot{};
        if (nums[left] < nums[right]) {
            pivot = (left + right) / 2;
        } else {
            while (right-left > 1) {
                int mid = (left + right) / 2;

                if (nums[left] <= nums[mid]) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            pivot = left;
        }
        // cout << pivot << '\n';

        left = 0, right = nums.size()-1;
        if (target < nums[left]) {
            left = pivot+1;
        } else {
            right = pivot;
        }
        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) return mid;

            else if (target < nums[mid]) {
                right = mid-1;
            } else {
                left = mid+1;
            }

        }
        
        return -1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    // vector<int> v{5,6,7,1,2,3,4};
    // vector<int> v{1,2,3,4,5,6};
    // vector<int> v{2,3,4,5,6,1};
    // vector<int> v{6,7,0,1,2,3,4,5};
    vector<int> v{4,5,6,7,0,1,2};
    cout << s.search(v, 0);

    return 0;
}

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
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            getCommon(nums2, nums1);
        }

        for (const auto& e : nums1) {
            if (binarysearch(nums2, e)) return e;
        }
        return -1;
    }
private:
    bool binarysearch(vector<int>& v, int target) {
        int left = 0, right = v.size()-1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (v[mid] == target) return true;
            else if (v[mid] > target) {
                right = mid-1;
            } else {
                left = mid+1;
            }

        }
        return false;
    }
};

int main(int argc, char** argv) {

    return 0;
}

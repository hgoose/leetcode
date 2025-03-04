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
#include <unordered_set>
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

template<typename T, typename U>
using pmap = unordered_map<T,U>;

template<typename T>
using pset = unordered_set<T>;

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

template<typename T>
using lims = std::numeric_limits<T>;

#define INT_MAX lims<int>::max();
#define INT_MIN lims<int>::min();

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int max = INT_MIN;
        while (left < right) {
            int lh = height[left], rh = height[right];
            int area = std::min(lh,rh) * (right - left);
            max = std::max(max, area);
            if (lh < rh) ++left;
            else --right;
        }
        return max;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> v{1,8,6,2,5,4,8,3,7};
    cout << s.maxArea(v);

    return 0;
}

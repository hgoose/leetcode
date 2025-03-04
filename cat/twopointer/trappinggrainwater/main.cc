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
#include <algorithm>
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
    int trap(vector<int>& height) {
        vector<int> ml(height.size()), mr(height.size()), minlr(height.size());
        int maxleft = height[0], maxright = height[height.size()-1];
        ml[0] = 0, mr[height.size()-1] = 0;
        for (int i = 1; i<(int)height.size(); ++i) {
            ml[i] = maxleft;
            maxleft = std::max(maxleft, height[i]);
        }

        for (int i = height.size()-2; i>=0; --i) {
            mr[i] = maxright;
            maxright = std::max(maxright, height[i]);
        }

        for (int i=0; i<(int)height.size(); ++i) {
            minlr[i] = std::min(ml[i], mr[i]);
        }


        int water{};
        for (int i=0; i<(int)height.size(); ++i) {
            water += std::max(0, minlr[i] - height[i]);
        }
        return water;
    }
};

int main(int argc, char** argv) {
    vector<int> v{1,0,0,1,2,3,2,1,1};
    Solution s;
    s.trap(v);

    return 0;
}

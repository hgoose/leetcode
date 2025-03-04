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
        int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
            int lb = bounds[0][0], rb = bounds[0][1];
            int ans = rb - lb + 1;

            for (int i=1; i<(int)original.size(); ++i) {
                int df = original[i] - original[i-1];
                lb = std::max(lb + df, bounds[i][0]);
                rb = std::min(rb + df, bounds[i][1]);
                ans = rb - lb + 1;
            }
            return ans < 0 ? 0 : ans;
        }
};

int main(int argc, char** argv) {

    vector<int> in{1,2,3,4};
    vector<vector<int>> bounds {
        {1,10},
        {2,9},
        {3,8},
        {4,7}
    };
    Solution s;

    cout << s.countArrays(in, bounds);

    return 0;
}

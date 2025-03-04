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


template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

template<typename T>
using lims = std::numeric_limits<T>;

template<typename T, typename U>
using pmap = unordered_map<T,U>;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = std::min(nums1.size(), nums2.size());
        vector<vector<int>> res;

        int l = 0, r = 0;

        while (l < nums1.size() && r < nums2.size()) {
            if (nums1[l][0] < nums2[r][0]) {
                res.push_back({nums1[l][0], nums1[l][1]});
                ++l;
            } else if (nums1[l][0] > nums2[r][0]) {
                res.push_back({nums2[r][0], nums2[r][1]});
                ++r;
            } else {
                res.push_back({nums1[l][0], nums1[l][1] + nums2[r][1]}); 
                ++l, ++r;
            }
        }

        if (l < nums1.size()) {
            for (int i=l; i<(int)nums1.size(); ++i) {
                res.push_back({nums1[i][0], nums1[i][1]});
            }
        } else if (r < nums2.size()) {
            for (int i=r; i<(int)nums2.size(); ++i) {
                res.push_back({nums2[i][0], nums2[i][1]});
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {

    return 0;
}

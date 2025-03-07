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
#include <stack>
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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       pmap<int,int> umap;        
        for (int i=0; i<(int)nums2.size(); ++i) {
            umap[nums2[i]] = i;
        }
        vector<int> res1(nums2.size(),-1), res2(nums1.size(),-1);
        std::stack<int> mack;
        for (int i=0; i<(int)nums2.size(); ++i) {

            while (mack.size() && nums2[i] > nums2[mack.top()]) {
               res1[mack.top()] = nums2[i];
               mack.pop();
            }

            mack.push(i);
        }

        for (int i=0; i<(int)nums1.size(); ++i) {
            res2[i] = res1[umap[nums1[i]]];

        }

        return res2;

    }
};

int main(int argc, char** argv) {

    vector<int> v1{4,1,2}, v2{1,3,4,2};
    Solution s;
    vector<int> res = s.nextGreaterElement(v1,v2);
    for (const auto& item : res) cout << item << " ";

    return 0;
}

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
    int removeDuplicates(vector<int>& nums) {
        int j=1,k=1;
        for (int i=1; i<(int)nums.size(); ++i) {
            if (nums[i] != nums[i-1]) {
                ++k;
                std::swap(nums[i], nums[j++]);
                ++i;
            }
        }
        return k;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{0,0,1,1,1,2,2,3,3,4};

    int k = s.removeDuplicates(nums);

    for (int i=0; i<k; ++i)  {
        cout << nums[i] << " ";
    }

    return 0;
}

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
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size()-1;
        while (left <= right)  {
            int mid = left + (right - left) / 2;
            if (k+mid < arr[mid]) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return left + k;

    }
};
    // int findKthPositive(vector<int>& arr, int k) {
    //     int pi = 1, count{};
    //     int tt = arr.size()+1, t{};
    //     while (--tt) {
    //         while (arr[t] > pi) {
    //             ++count;
    //             if (count == k) return pi;
    //             ++pi;
    //         }
    //         if (arr[t] == pi) ++pi;
    //         ++t;
    //     }
    //     return arr[arr.size()-1] + (k-count);
    // }
// };

int main(int argc, char** argv) {

    Solution s;
    vector<int> v{-2,-1,1,2,3,6,8};
    cout << s.findKthPositive(v,3);

    return 0;
}

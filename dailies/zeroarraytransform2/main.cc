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
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        int tt = nums.size()+1, t{};
        bool az = true;
        while (--tt) {
            if (nums[t++] != 0) {
                az = false;
                break;
            }
        }
        if (az) return 0;

        int left = 0, right = queries.size()-1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (condition(nums, queries,  mid)) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return left < queries.size() ? left + 1 : -1;
    }
private:
    bool condition(vector<int>& A, vector<vector<int>>& q, int stop) {

        vector<int> D(A.size());
        D[0] = A[0];
        for (int i=1; i<(int)A.size(); ++i) {
            D[i] = A[i] - A[i-1];    
        }
        for (int i=0; i<=stop; ++i) {
            D[q[i][0]] -= q[i][2];
            if (q[i][1]+1 < A.size()) {
                D[q[i][1]+1] += q[i][2];
            }
        }

        int prev = D[0];
        if (prev > 0) return false;
        int tt = A.size(), t{1};
        while (--tt) {
            if (prev + D[t] > 0) return false;
            prev = prev + D[t++];
        }

        return true;

    }
};

int main(int argc, char** argv) {
    Solution s;
    // vector<int> v{2,0,2};
    // vector<vector<int>> q{{0,2,1},{0,2,1},{1,1,3}};
    vector<int> v{7};
    vector<vector<int>> q{{0,0,4},{0,0,1},{0,0,4},{0,0,4},{0,0,4},{0,0,4},{0,0,1},{0,0,5},{0,0,1},{0,0,3},{0,0,5},{0,0,2},{0,0,3},{0,0,1},{0,0,5}};
    cout << s.minZeroArray(v,q);

    return 0;
}

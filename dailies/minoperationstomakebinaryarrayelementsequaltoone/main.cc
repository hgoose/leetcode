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
    int minOperations(vector<int>& nums) {
        if (check(nums)) return 0;

        int ops{};
        for (int i=0; i<(int)nums.size()-2; ++i) {
            if (nums[i] == 0) {
                for (int j=i; j<i+3 && j<(int)nums.size(); ++j) {
                    nums[j] = !nums[j];
                }
                ++ops;
            }
        }
        return check(nums) ? ops : -1;
    }
private:
    bool check(vector<int>& nums) {
        for (int i=0; i<(int)nums.size(); ++i) {
            if (nums[i] != 1) return false;
        }
        return true;
    }
};

int main(int argc, char** argv) {

    return 0;
}

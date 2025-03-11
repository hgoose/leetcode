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

template<typename T, typename U>
using pmap = unordered_map<T,U>;

template<typename T>
using pset = unordered_set<T>;

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

template<typename T>
using lims = std::numeric_limits<T>;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;
        int left = 0, right = 1;
        int max = 0;

        while (right < prices.size()) {
            max = std::max(max, prices[right] - prices[left]);
            if (prices[right] - prices[left] < 0) ++left;
            else ++right;
        }
        --right;
        while (left < prices.size()) {
            max = std::max(max, prices[right] - prices[left]);
            ++left;
        }
        return max;
    }
};

int main(int argc, char** argv) {

    Solution s;
    vector<int> v{7,1,5,3,6,4};
    cout << s.maxProfit(v);

    return 0;
}

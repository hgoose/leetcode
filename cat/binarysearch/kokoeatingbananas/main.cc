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
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *std::max_element(piles.begin(), piles.end());
        int min = right;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (canEat(piles, mid, h)) {
                right = mid - 1;
                min = mid;
            } else left = mid + 1;
        }
        return min;

    }
private: 
    bool canEat(vector<int>& piles, int speed, int h) {
        int t = piles.size()+1, i = 0;
        int time{};
        while (--t) {
           time+=ceil(static_cast<double>(piles[i])/speed); 
           if (time > h) return false;
           ++i;
        }
        return true;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> v{3,6,7,11};
    cout << s.minEatingSpeed(v, 8);

    return 0;
}

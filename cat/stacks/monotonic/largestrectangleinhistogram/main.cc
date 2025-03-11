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
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> monack;

        int max = 0;
        for (int i=0;i<(int)heights.size(); ++i) {
            int last_popped{-1};
            while (monack.size() && heights[i] < monack.top().second) {
               int stop = i; 
               int width = stop - monack.top().first;
               int area = monack.top().second * width;
               max = std::max(max,area);
               last_popped = monack.top().first;
               monack.pop();
            }
            monack.push({last_popped == -1 ? i : last_popped, heights[i]});
        }

        while (monack.size()) {
            int i = monack.top().first, h = monack.top().second;
            cout << "h: " << h << " i: " << i << endl;
            max = std::max(max, h * ((int)heights.size() - i));
            monack.pop();
        }
        return max;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> v{2,4};
    cout << s.largestRectangleArea(v) << endl;

    return 0;
}

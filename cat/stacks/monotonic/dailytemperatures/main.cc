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

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> mack;        
        vector<int> res(temperatures.size(), 0);

        for (int i=0; i<(int)temperatures.size(); ++i) {
            while (mack.size() && temperatures[i] > temperatures[mack.top()]) {
                res[mack.top()] = i-mack.top();
                mack.pop();
            }
            mack.push(i);
        }
        return res;
    }
};

int main(int argc, char** argv) {

    return 0;
}

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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int, int> line;
        for (const auto& e : intervals) {
            ++line[e[0]];
            --line[e[1]];
        }

        int count=0, start=0;
        vector<vector<int>> res;
        for (auto& [key, value] : line) {
            if (count==0) {
                start = key;
            }
            count+=value;

            if (count == 0) {
                res.push_back({start, key});
            }
        }
        return res;
    }
};

// [[1,3],[2,6],[8,10],[15,18]] -> [[1,6],[8,10],[15,18]]

int main(int argc, char** argv) {

    return 0;
}

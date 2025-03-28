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
    int minOperations(vector<vector<int>>& grid, int x) {
        if (grid.size() == 1 && grid[0].size() == 1) return 0;
        int count{};        
        vector<int> targets(grid.size() * grid[0].size());
        int i=0;
        for (const auto& v : grid) {
            for (const auto& e : v) {
                targets[i++] = e;
            }
        }

        std::nth_element(targets.begin(), targets.begin() + ((targets.size()-1) / 2),targets.end());
        int target = targets[(targets.size()-1)/2];
        std::swap(targets[(targets.size()-1)/2], targets[targets.size()-1]);

        for (int i=0; i<(int)targets.size()-1; ++i) {
            if (targets[i] < target) {
                double tmp = (target - targets[i]) / (double)x;
                if (tmp == floor(tmp)) count+=tmp;
                else return -1;
            } else if (targets[i] > target) {
                double tmp = (targets[i] - target) / (double)x;
                if (tmp == floor(tmp)) count+=tmp;
                else return -1;
            } 
        }
        return count;
    }
};

int main(int argc, char** argv) {

    return 0;
}

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

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

constexpr long long minf = std::numeric_limits<long long>::min();

class Solution {
public:
    void _bt(vector<vector<int>>& grid, vector<int>& limits, int k, int row, int limRow, int& max, int& taken, int& sum) {
        if (row >= grid.size()) return;
        if (taken == k) {
            if (sum > max)  max = sum;
            return;
        }
        vector<int> rowElements{};
        int grabbed{};

        for (int i=0;i<(int)grid[row].size();++i) {
           if (grabbed == limRow) break; 
           if (grid[row][i] <= 0 ) continue;
           rowElements.push_back(grid[row][i]);
           sum+=grid[row][i];
           ++taken;
           _bt(grid, limits, k, row+1, limits[row+1], max, taken, sum);
           ++grabbed;
        }
         
    }
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {

        for (int i=0; i<(int)grid.size(); ++i){
            std::sort(grid[i].begin(), grid[i].end());

        }
         
    }
};

int main(int argc, char** argv) {

    return 0;
}

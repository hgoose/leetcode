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
#define INT_MAX lims<int>::max();
#define INT_MIN lims<int>::min();

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int b = grid.size() * grid.size();        
        vector<int> v(b,0);

        int dup{};
        int missing = (b * (b+1)) / 2;
        for (int i=0; i<(int)grid.size(); ++i) {
            for (int j=0;j<(int)grid[0].size();++j) {
                ++v[grid[i][j]]; 
                if (v[grid[i][j]]) {
                    dup = grid[i][j];
                } else {
                    missing-=grid[i][j];
                }
            }
        }
        return {dup, missing};
    }
};

int main(int argc, char** argv) {

    return 0;
}

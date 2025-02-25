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

template<typename T>
using lims = std::numeric_limits<T>;

class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        long long sol{};
        int grabbed{};
        vector<pq<int,vector<int>, std::greater<int>>> trivial_container(grid.size()); 
        for (int i=0; i<(int)grid.size();++i) {
            for (int j=0; j<(int)grid[0].size();++j) {
                trivial_container[i].push(grid[i][j]);
            }
        }

        int ninf = lims<int>::min();
        while (grabbed < k) {
            int max = ninf;
            int maxIdx{};
            for (int i=0; i<(int)trivial_container.size(); ++i) {
                if (limits[i] && trivial_container[i].size()) {
                    int local_max = trivial_container[i].top(); 
                    if (local_max > max) {
                        max = local_max;
                        maxIdx = i;
                    }
                }
            }
            sol+=trivial_container[maxIdx].top();
            trivial_container[maxIdx].pop();
            ++grabbed;
            --limits[maxIdx];
        }
        return sol;
    }
};

int main(int argc, char** argv) {

    return 0;
}

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
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> hval, vval;

        for (auto& e : rectangles) {
            hval.push_back({e[1], e[3]});
            vval.push_back({e[0], e[2]});
        }

        auto [h_merged, v_merged] = _merge(hval, vval);

        if (h_merged.size() > 2 || v_merged.size() > 2) {
            return true;
        } return false;
    }
private:
    pair<vector<vector<int>>, vector<vector<int>>> _merge(vector<vector<int>>& h, vector<vector<int>>& v) {
        std::sort(h.begin(), h.end()); 
        std::sort(v.begin(), v.end());
        int curr_start = h[0][0], curr_end = h[0][1];

        vector<vector<int>> mh, mv;
        for (int i=1; i<(int)h.size(); ++i) {
            int next_start = h[i][0], next_end = h[i][1];
            if (next_start >= curr_start && next_start < curr_end) {
                curr_end = std::max(curr_end, next_end);
            } else {
                mh.push_back({curr_start, curr_end});
                curr_start = next_start;
                curr_end = next_end;
            }
        }
        mh.push_back({curr_start, curr_end});

        curr_start = v[0][0], curr_end = v[0][1];
        for (int i=1; i<(int)v.size(); ++i) {
            int next_start = v[i][0], next_end = v[i][1];
            if (next_start >= curr_start && next_start < curr_end) {
                curr_end = std::max(curr_end, next_end);
            } else {
                mv.push_back({curr_start, curr_end});
                curr_start = next_start;
                curr_end = next_end;
            }
        }
        mv.push_back({curr_start, curr_end});

        return {mh,mv};
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<vector<int>> r{{1,0,5,2},{0,2,2,4},{3,2,5,3},{0,4,4,5}};

    cout << s.checkValidCuts(5,r);


    return 0;
}

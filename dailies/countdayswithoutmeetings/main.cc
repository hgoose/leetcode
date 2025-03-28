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
    int countDays(int days, vector<vector<int>>& meetings) {
        map<int, int> line;
        for (auto& e : meetings) {
            ++line[e[0]], --line[e[1]];
        }

        int start = 0, count = 0, res=0, last=0;
        bool begin = true, first=true;
        int end=0;
        for (auto& [key, value] : line) {
            if (!count) {
                start = key;
                if (begin) {
                    res+=key-1;
                    begin = false;
                } else {
                    res+=start-end-1;
                }
            } 
            count+=value;
            if (!count) {
                end = key;
            }
        }
        return res + (days - end);
    }
};

int main(int argc, char** argv) {
    int n = 10;
    vector<vector<int>> m {{5,7}, {1,3}, {9,10}};
    Solution s;
    cout << s.countDays(n,m);

    return 0;
}

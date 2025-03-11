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
    int minimumRecolors(string blocks, int k) {
        int window{};
        int min = INT_MAX;
        for (int i=0; i<=k; ++i) {
            if (blocks[i] == 'W') ++window;
        }
        min = std::min(min, window);
        for (int i=1; i<=(int)blocks.size()-k; ++i) {
           if (blocks[i-1] == 'W') --window; 
           if (blocks[i+k] == 'W') ++window;
           min=std::min(min, window);
        }
        return min;
    }
};

int main(int argc, char** argv) {

    Solution s;
    string str = "BWBBWWBBBWBWWWBWWBBWBWBBWBB";
    cout << s.minimumRecolors(str, 11);


    return 0;
}

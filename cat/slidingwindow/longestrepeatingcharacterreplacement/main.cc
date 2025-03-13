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
    int characterReplacement(string s, int k) {
        pmap<char,int> umap;
        int left  = 0, right=0;
        int n = s.size(), max=0;
        ++umap[s[left]];
        while (left < n) {
            while (right < n && ((right - left + 1) - most_freq(umap)) <= k) {
                max = std::max(max, (right-left+1));
                ++umap[s[++right]];
            }
            ++left;
            --umap[s[left-1]];

        }
        return max;
    }
private:
    int most_freq(pmap<char,int>& umap) {
        int max = 0;
        for (const auto& [key, value] : umap) {
            max = std::max(max,value);
        }
        return max;
    }
};

int main(int argc, char** argv) {
    Solution s;
    // cout << s.characterReplacement("ABAB", 2) << '\n';
    cout << s.characterReplacement("AABABBA", 1) << '\n';

    return 0;
}

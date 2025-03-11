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
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        if (s.size() == 1) return 1;

        pmap<char, int> umap;

        int left = 0, right = 1, max{1};
        ++umap[s[left]];
        while (right < s.size()) {
            ++umap[s[right]];
            int add = check(umap);
            if (add == 1) max = std::max(max, (int)(s.substr(left, right-left+1)).size());
            else {
                while (true) {
                    --umap[s[left++]];
                    add = check(umap);
                    if (add) {
                        max = std::max(max, (int)(s.substr(left, right-left+1)).size());
                        break;
                    }
                }
            }
            ++right;
        }
        return max;
    }
private:
    int check(pmap<char, int>& umap) {
        for (const auto& [key,value] : umap) {
            if (value > 1) return 0;
        }
        return 1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb");

    return 0;
}

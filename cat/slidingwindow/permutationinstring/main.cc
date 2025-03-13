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
    bool checkInclusion(string s1, string s2) {
        // Deal with Vacuous truths
        if (s1.empty()) return true;

        if (s1.size() > s2.size()) return false;

        pmap<char,int> key, against;
        int n = s2.size(), windowlen = s1.size();
        int left = 0, right = windowlen-1;
        for (const auto& e : s1) {
            ++key[e];
        }

        int tt = windowlen+1, t=0;
        while (--tt) {
            ++against[s2[t++]];
        }

        while (right < n) {
            if (check(key, against)) return true;
            --against[s2[left++]];
            if (against[s2[left-1]] == 0) against.erase(s2[left-1]);
            ++against[s2[++right]];
        }
        return false;
    }

private:
    bool check(pmap<char,int>& m1, pmap<char, int> m2) {
        return m1 == m2;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << std::boolalpha << s.checkInclusion("hello", "ooolleoooleh") << '\n';

    return 0;
}

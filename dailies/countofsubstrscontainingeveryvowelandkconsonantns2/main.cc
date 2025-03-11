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
    long long countOfSubstrings(string word, int k) {
        return at_least_k(word,k) - at_least_k(word, k+1);
    }
    long long at_least_k(string word, int k) {
        bitset<26> v=0, sv;
        vector<int> cc(26,0);
        int tt = 0b1100001+1, t=0;

        while (--tt) {
            if (!((t+0b1100001)^0b1100001) || !((t+0b1100001)^101) 
                    || !((t+0b1100001)^105) || !((t+0b1100001)^111) 
                    || !((t+0b1100001)^117)
               ) { v[t] = 1; } 
            ++t;
        }

        int l{}, c{}, n = word.size();
        long long total{};
        tt = n+1, t = 0;
        while (--tt) {
            if (v[word[t] - 0b1100001]) {
                sv[word[t] - 0b1100001] = 1;
                ++cc[word[t] - 0b1100001];
            } else ++c;

            while ((v & sv).count() == 5 && c >= k) {
                total+=n-t;

                if (v[word[l] - 0b1100001]) {
                    if (!--cc[word[l] - 0b1100001]) {
                        sv[word[l] - 0b1100001] = 0;
                    }
                } else --c;

                ++l;
            }
            ++t;
        }
        return total;
    }
};
int main(int argc, char** argv) {
    Solution s;

    cout << s.countOfSubstrings("aoaiuefi" ,1);

    return 0;
}

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
    string minWindow(string s, string t) {
        if (t.empty()) return "";
        if (t.size() > s.size()) return "";

        bool atleastone = false;

        pmap<char, int> key, against;       
        bitset<26*2> need(0);
        for (const auto& e : t) {
            ++key[e];
            need[index(e)]=1;
        }
        int wl = t.size(), n=s.size();
        int left = 0, right = wl-1;

        int tt = wl+1, i=0;
        while (--tt) {
            if (need[index(s[i])]) {
                ++against[s[i]];
            }
            ++i;
        }
        int min = INT_MAX;
        int ml{}, mr{};

        if (check(key, against)) {
            if ((right - left + 1) < min) {
                min = right - left + 1;
                ml = left, mr = right;
            }
            atleastone = true;
        }

        while (left < n) {
            while (right < n && !check(key,against)) {
                ++right;
                if (need[index(s[right])]) {
                    ++against[s[right]];
                }
                if (check(key, against)) {
                    if ((right - left + 1) < min) {
                        min = right - left + 1;
                        ml = left, mr = right;
                    }
                    atleastone = true;
                    break;
                }
            }
            if (need[index(s[left])]) {
                --against[s[left]];
                if (against[s[left]] == 0) against.erase(s[left]);
            }
            ++left;
            if (check(key, against)) {
                if (((right >= n ? n-1 : right) - (left >= n ? n-1 : left) + 1) < min) {
                    min = right - left + 1;
                    ml = left, mr = right;
                }

                atleastone = true;
            }
        }

        return atleastone ? s.substr(ml, mr-ml+1) : "";
    }
private:
    int index(char c) {
        if (c - 97 >= 0) {
            return c-97;
        } else return 26 + (c-65);
    }
    bool check(pmap<char, int>& m1, pmap<char, int>& m2) {
        if (m1.size() != m2.size()) return false;
        for (const auto& [key, value] : m1) {
            if (m2[key] < value) return false;
        }
        return true;
    }
};
int main(int argc, char** argv) {
    Solution s;
    // cout << s.minWindow("a", "a");
    // cout << s.minWindow("ab", "a");
    // cout << s.minWindow("a", "b");
    // cout << s.minWindow("abc", "c");
    // cout << s.minWindow("ADOBECODEBANC", "ABC");
    // cout << s.minWindow("abc", "bc");
    // cout << s.minWindow("bbaac", "aba");
    cout << s.minWindow("cabefgecdaecf", "cae");


    return 0;
}

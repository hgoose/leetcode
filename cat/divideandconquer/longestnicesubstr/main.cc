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

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

template<typename T>
using lims = std::numeric_limits<T>;

class Solution {
public:
    std::pair<int,bool> getAbsoluteIdx(const char& c) {
        int code = (int) c - 97;
        bool cap = 0;
        if (code < 0) {
            code = (int) c - 65;
            cap = 1;
        }
        return {code, cap};
    }
    string _dc(string s, int start, int end) {
        if (start > end) {
            return "";
        }

        vector<std::pair<int,int>> v(26);
        for (int i=start; i<=end; ++i) {
            auto [idx, flag] = getAbsoluteIdx(s[i]);
            if (flag) {
                v[idx].second = 1;;
            } else {
                v[idx].first = 1;
            }
            // ++v[getIdx(s[i])];
        }

        string left=s.substr(start, end-start+1), right;
        for (int i=start; i<=end; ++i) {
            auto [idx, flag] = getAbsoluteIdx(s[i]);
            if (v[idx].first != v[idx].second) {
                left = _dc(s, start, i-1);
                right = _dc(s, i+1, end);
                break;
            }
        }

        return left.size() >= right.size() ?  left : right;  
    }
    string longestNiceSubstring(string s) {
        return _dc(s, 0, s.size()-1);
    }
};

int main(int argc, char** argv) {

    Solution s;
    cout << s.longestNiceSubstring("XqLJWaEEcAjslIXxKZgufikxFwVVYUlvYrIeGRyS") << endl;

    return 0;
}

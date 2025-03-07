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
#define INT_MAX lims<int>::max();
#define INT_MIN lims<int>::min();

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<char> chars{'(', ')'};
        vector<string> res{};
        string curr{};
        int k = n * 2;
        _bt(res, chars, curr, k, 0, 0);
        return res;

    }
public:
    bool _bt(vector<string>& res, vector<char>& v, string& curr, int k, int open, int close) {
        if (curr.size() == k) {
            res.push_back(curr);
            return true;
        }

        for (int i=0; i<(int)v.size(); ++i) {
            if ((v[i] == '(' && open < k/2) || (v[i] == ')' && (close < open)) ) {
                curr.push_back(v[i]);
                if (v[i] == '(') ++open;
                else ++close;
                _bt(res, v, curr, k, open, close);
                curr.pop_back();
                if (v[i] == '(') --open;
                else --close;
            } 
        }
        return true;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<string> res = s.generateParenthesis(3);
    for (const auto& item: res) {
        cout << item << endl;
    }

    return 0;
}

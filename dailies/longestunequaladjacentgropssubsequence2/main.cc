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
#include <ranges>
using std::accumulate;
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

typedef priority_queue<int, vector<int>, std::greater<int>> I_MIN_HEAP;
typedef priority_queue<int, vector<int>> I_MAX_HEAP;

template<typename T>
using lims = std::numeric_limits<T>;

template<typename T, typename U>
using pmap = unordered_map<T,U>;

typedef vector<vector<int>> VII;
typedef vector<int> VI;
struct TreeNode;
struct ListNode;
typedef ListNode ln;
typedef TreeNode tn;
#define PB push_back

class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ret{};
        for (int start=0; start<(int)words.size(); ++start) {
            vector<string> vtry{words[start]};
            int last_group = groups[start];
            string last_word = words[start];

            for (int i=start+1; i<(int)words.size(); ++i) {
                if (groups[i] != last_group && words[i].size() == last_word.size() && _hamming(last_word, words[i]) == 1) {
                    vtry.push_back(words[i]);
                    last_word = words[i];
                    last_group = groups[i];
                }
            }

            if (vtry.size() > ret.size()) ret = vtry;
        }
        return ret;
    }

private:
    int _hamming(const string& a, const string& b) {
        int dist = 0;
        for (int i=0; i<(int)a.size(); ++i) {
            if (a[i] != b[i]) ++dist;
        }
        return dist;
    }
};

int main(int argc, char** argv) {

    return 0;
}

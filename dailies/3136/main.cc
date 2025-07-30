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
#include <cctype>
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

template<typename T>
using pset = unordered_set<T>;
class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) return false; 

        std::bitset<26> bs("100010001000001000001000001");

        pset<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        bool vow{}, con{};
        for (char ch : word) {
            if (!isalnum(ch)) return false;
            if (isdigit(ch)) continue;

            if (bs[(int)towlower(ch)-97] == 1) {
                vow = true;
            } else con = true;
        }

        return (vow && con ? true : false);
    }
};

int main(int argc, char** argv) {
    Solution s;
    string w = "AhI";

    cout << std::boolalpha << s.isValid(w);

    return 0;
}

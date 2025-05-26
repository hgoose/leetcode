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


typedef vector<vector<int>> VII;
typedef vector<int> VI;
struct TreeNode;
struct ListNode;
typedef ListNode ln;
typedef TreeNode tn;
#define PB push_back

template<typename T, typename U>
using pmap = unordered_map<T,U>;
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
       pmap<string, pair<int, bool>> occur;        
       for (auto& word : words) {
           ++occur[word].first;
           occur[word].second = false;
       }

       int len = 0;
       vector<string> examine_later;
       for (auto& [word, count] : occur) {
           string need = word; 
           std::reverse(need.begin(), need.end());
           if (occur.find(need) != occur.end()) {
               auto& other = occur[need];
               if (other.second) continue;
               len+=2*std::min(count.first, other.first);
               other.second = true;
           }
       }
       int tmp = len;
       while (tmp > 0 && examine_later.size()) {
            len+=2; 
            examine_later.pop_back();
            tmp-=4;
       }
       if (!len && examine_later.size()) len+=2;
       return len;
    }
private:
    bool _is_palindrome(const string& w) {
        int left = 0, right = w.size()-1;

        while (left < right) {
            if (w[left] != w[right]) return false;
            ++left, --right;
        }
        return true;

    }
};

int main(int argc, char** argv) {

    return 0;
}

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

template<typename T>
using pset = unordered_set<T>;

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

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
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long> w(weights.size()-1);
        pq<long long, vector<long long>, std::greater<long long>> q_min;
        pq<long long, vector<long long>, std::less<long long>> q_max;

        for (long long i=0; i<weights.size()-1; ++i) {
            w[i] = weights[i] + weights[i+1];
            q_min.push(w[i]);
            q_max.push(w[i]);
        }
        long long min_score = 0, max_score=0;
        for (int i=0; i<k-1; ++i) {
            min_score+=q_min.top(), q_min.pop();
            max_score+=q_max.top(), q_max.pop();
        }
        return max_score - min_score;
    }
};

int main(int argc, char** argv) {

    return 0;
}

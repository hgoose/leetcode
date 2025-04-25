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
    int countLargestGroup(int n) {
        pmap<int,int> sumtofreq, freqoffreq;
        for (int i=1; i<=n; ++i) {
            ++sumtofreq[_sum_dig_(i)]; 
        }

        for (const auto& [key,value] : sumtofreq) {
            ++freqoffreq[value];
        }

        int max = 0;
        for (const auto& [key,value] : freqoffreq) {
            if (key > max) max = key;
        }

        return freqoffreq[max];
    }
private:
    int _sum_dig_(int n) {
        int sum = 0;
        while (n > 0) {
            sum+=(n%10);
            n/=10;
        }
        return sum;
    }
};

int main(int argc, char** argv) {

    return 0;
}

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

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

typedef priority_queue<int, vector<int>> I_MAX_HEAP;

typedef priority_queue<int, vector<int>, std::greater<int>> I_MIN_HEAP;
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (auto& e : nums) {
            stream.push(e);
        }

        while (stream.size() > k) {
            stream.pop();
        }
    }
    
    int add(int val) {
        stream.push(val);

        if (stream.size() > k) {
            stream.pop();
        }

        return stream.top();
    }

private:
    int k{};
    I_MIN_HEAP stream;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main(int argc, char** argv) {

    return 0;
}

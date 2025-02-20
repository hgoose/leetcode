#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <utility>
#include <cmath>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;
using std::queue;
using std::priority_queue;
typedef long long dword;

template<typename T, typename U>
using pmap = unordered_map<T,U>;

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

class Solution {
public:
    int r_fib(int n, vector<int>& memo) {
        if (n<=1) return n;
        if (memo[n] != -1) return memo[n];
        memo[n] = r_fib(n-2, memo) + r_fib(n-1, memo);
        return memo[n];
    }
    int fib(int n) {
        vector<int> memo(n+1,-1);
        memo[0] = 0;
        memo[1] = 1;
        return r_fib(n, memo);
    }
};

int main(int argc, char** argv) {

    Solution s;
    cout << s.fib(4);

    return 0;
}

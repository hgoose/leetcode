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
#include <climits> // INT_MAX, INT_MIN, ...
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

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> pre_primes(right+1,1);       
        vector<int> primes;

        for (int i=2; i*i<(int)pre_primes.size(); ++i) {
            for (int j=i*i; j<(int)pre_primes.size(); j+=i) {
                pre_primes[j] = 0;
            }
        }

        for (int i=std::max(left, 2); i<(int)pre_primes.size(); ++i) {
            if (pre_primes[i] == 1) primes.push_back(i);
        }

        int least = INT_MAX;
        vector<int> ret;

        for (int i=0; i<(int)primes.size()-1; ++i) {
            if (primes[i+1] - primes[i] < least) {
                ret = {primes[i], primes[i+1]};
                least = primes[i+1] - primes[i];
            }
        }
        return ret.size() ? ret : vector<int>{-1,-1};
    }
};


int main(int argc, char** argv) {
    Solution s;
    vector<int> sol = s.closestPrimes(1,1000);
    for (const auto& item : sol) cout << item << " ";

    return 0;
}

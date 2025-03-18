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

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int curr = digits.size()-1;
        bool carry = 0;
        digits[curr] = (digits[curr] + 1) % 10;
        if (digits[curr] == 0) carry=true;
        --curr;

        while (curr>=0 && carry) {
            digits[curr] = (digits[curr] + 1) % 10;
            if (digits[curr] > 0) carry = false; 
            --curr;
        }

        if (curr < 0 && carry) {
            vector<int> res(digits.size()+1);
            res[0] = 1;
            for (int i=1,k=0; i<res.size(); ++i, ++k) {
                res[i] = digits[k];
            }
            return res;
        }
        return digits;
    }
};

int main(int argc, char** argv) {

    return 0;
}

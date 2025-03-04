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
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        pset<int> uset;
        for (const auto& e : nums) {
            uset.insert(e);
        }

        int max = 1, count{1}, offset{};
        for (auto it = uset.begin(); it!=uset.end(); ++it) {
            auto curr = it;
            if (uset.find(*curr-1) == uset.end()) {
                while (uset.find(*curr+1) != uset.end()) {
                    ++count;
                    curr = uset.find(*curr+1);
                }
                max = std::max(max,count);
                count = 1;
            }
        }

        return max;
    }
};

int main(int argc, char** argv) {

    vector<int> v{9,1,4,7,3,-1,0,5,8,-1,6};
    Solution s;
    cout << endl;
    cout << s.longestConsecutive(v);



    return 0;
}

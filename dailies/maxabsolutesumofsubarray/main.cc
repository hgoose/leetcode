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

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

template<typename T>
using lims = std::numeric_limits<T>;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int gmax{}, lmax{}, gmin{}, lmin{};

        for (int i=0; i<(int)nums.size(); ++i) {
            lmax += nums[i], lmin+=nums[i];
            if (lmax > gmax)  {
                gmax=lmax;
            }
            if (lmin < gmin)  {
                gmin = lmin;
            }
            if (lmax <= 0) {
                lmax = 0;
            }
            if (lmin >= 0) {
                lmin = 0;
            }
        }
        return std::max(abs(gmin), abs(gmax));
    }
};

int main(int argc, char** argv) {

    return 0;
}

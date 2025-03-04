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

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

template<typename T>
using lims = std::numeric_limits<T>;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
       for (int i=0; i<(int)nums.size()-1; ++i) {
           if (nums[i] == nums[i+1]) {
               nums[i]*=2;
               nums[i+1] = 0;
           }
       } 
       std::stable_partition(nums.begin(), nums.end(), [](int x) -> bool{
            return x != 0; 
       });

       return nums;
    }
};

int main(int argc, char** argv) {

    return 0;
}

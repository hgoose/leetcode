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

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        while (start <= end) {
            int mid = (start + end) / 2; 

            if (nums[mid] < target) {
                end = mid-1;
            } else if (nums[mid] > target) {
                start = mid+1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};

int main(int argc, char** argv) {

    return 0;
}

#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::string;
using std::vector;
using std::endl;

class Solution {
public:
    static bool checkSorted(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n-1; ++i) {
            if (nums[i] > nums[i+1]) return false;
        }
        return true;
    }

    static bool rotateSorted(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> ret(n);
        for (int i=0; i<n; ++i) {
            ret[(i+x) % n] = nums[i];
        }
        return checkSorted(ret);
    }

    bool check(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n; ++i) {
            if (rotateSorted(nums, i)) return true;
        }
        return false;
    }
};

int main(int argc, char** argv) {

    vector<int> nums1{1,4,5,9};
    vector<int> nums2{1,4,3,9};


    return 0;
}

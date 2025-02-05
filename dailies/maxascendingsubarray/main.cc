#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::string;
using std::vector;
using std::endl;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int maxascend{}, subascend=nums[0], prev=nums[0];
        for (int i=1; i<n; ++i) {
            if (nums[i] > prev) {
                subascend+=nums[i];
            } else {
                maxascend = std::max(maxascend, subascend);
                subascend=nums[i];
            }
            prev = nums[i];
        }
        maxascend = std::max(maxascend, subascend);
        return maxascend;
    }
};

int main(int argc, char** argv) {

    return 0;
}

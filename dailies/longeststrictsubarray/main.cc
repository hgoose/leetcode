#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::string;
using std::vector;
using std::endl;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int n = nums.size();

        int longestinc{}, longestdec{}, subinc = 1, subdec=1;
        int prev = nums[0];
        for (int i=1; i<n; ++i) {
            if (nums[i] > prev) {
                ++subinc;
            } else {
                longestinc = (subinc > longestinc ? subinc : longestinc);
                subinc=1;
            } 

            if (nums[i] < prev) {
                ++subdec;
            } else {
                longestdec = (subdec > longestdec ? subdec : longestdec);
                subdec=1;
            } 
            prev = nums[i];
        }
        longestinc = (subinc > longestinc ? subinc : longestinc);
        longestdec = (subdec > longestdec ? subdec : longestdec);


        return (longestinc >= longestdec ? longestinc : longestdec);
    }
};

int main(int argc, char** argv) {

    return 0;
}

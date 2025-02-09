#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::string;
using std::vector;
using std::endl;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixProd(nums.size(), 1), suffixProd(nums.size(), 1), res(nums.size()); 
        prefixProd[0] = nums[0];
        for (int i=1; i<(int)nums.size();++i) {
            prefixProd[i] = prefixProd[i-1] * nums[i];
        }
        suffixProd[nums.size()-1] = nums[nums.size()-1];
        for (int i=(int)nums.size()-2; i>=0; --i) {
            suffixProd[i] = suffixProd[i+1]  * nums[i];
        }
        res[nums.size()-1] = prefixProd[nums.size()-2];
        res[0] = suffixProd[1];
    
        for (int i=1; i<(int)nums.size()-2; ++i) {
            res[i] = prefixProd[i-1] * suffixProd[i+1];
        }
        return res;
    }
};

int main(int argc, char** argv) {

    return 0;
}

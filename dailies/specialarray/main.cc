#include <iostream>
#include <vector>
#include <string>
#include <ranges>
using std::cout;
using std::string;
using std::vector;
using std::endl;

using std::ranges::views::iota;

class Solution {
public:
    static inline bool checkParity(int x, int y) {
        return (((x % 2 == 0) && (y % 2 != 0)) || (x % 2 != 0) && (y % 2 == 0));
    }
    bool isArraySpecial(vector<int>& nums) {
        for (const auto& i : iota(0, (int)nums.size()-1)) {
            if (!checkParity(nums[i], nums[i+1])) return false;
        }
        return true;
    }
};

int main(int argc, char** argv) {

    Solution s;

    // cout << std::boolalpha << s.checkParity(1,2);
    // cout << std::boolalpha << Solution::checkParity(2,2);

    
    return 0;
}

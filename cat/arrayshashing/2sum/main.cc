#include <vector>
#include <ranges>
#include <unordered_map>
using std::vector;
using std::unordered_map;
using namespace std::ranges::views;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> hm;
        for (const auto& i : iota(0,n)) {
            int comp = target - nums[i];
            if (hm.find(comp) != hm.end()) {
                return {i, hm[comp]};
            }
            hm[nums[i]] = i;
        }
        return {};
    }
};

auto main(int argc, char** argv) -> int {
    return 0;
}

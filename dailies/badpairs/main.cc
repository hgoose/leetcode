#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using std::cout;
using std::string;
using std::vector;
using std::endl;
using std::unordered_map;

typedef long long dword;
typedef unordered_map<dword, vector<int>> umap;

class Solution {
public:
    dword nPairs(dword n, dword k) {
        return (n*n - n)/2;
    }

    dword countBadPairs(vector<int>& nums) {
        dword totalpairs = nPairs(nums.size(), 2);
        umap pmap;

        for (int i=0; i<(int)nums.size(); ++i) {
            pmap[nums[i] - i].push_back(i);
        }

        dword good{};
        for (const auto& [key, value] : pmap) {
            if (value.size() > 1) {
                good+=nPairs(value.size(), 2);
            }
        }

        return totalpairs-good;
    }
};

int main(int argc, char** argv) {

    return 0;
}

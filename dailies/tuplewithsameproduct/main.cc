#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using std::cout;
using std::string;
using std::vector;
using std::endl;
using std::unordered_map;

typedef unordered_map<int, int> pmap;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        pmap umap;
        int count{};
        for (int i=0; i<(int)nums.size(); ++i) {
            int product=nums[i];
            for (int j=i+1; j<(int) nums.size(); ++j) {
                product*=nums[j];
                ++umap[product];
                if (umap[product] == 2) count+=8;
            }
        } 
        return count;
    }
    
};

int main(int argc, char** argv) {

    return 0;
}

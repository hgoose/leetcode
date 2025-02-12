#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using std::cout;
using std::string;
using std::vector;
using std::unordered_map;
using std::endl;
using std::priority_queue;
typedef long long dword;
typedef unordered_map<int, priority_queue<int, vector<int>>> umap;

class Solution {
public:
    unsigned sumdig(int n) {
        int sum = 0;
        while (n>0) {
            sum+=n%10;
            n/=10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        umap pmap;
        int max = 0;
        for (int i=0; i<(int)nums.size(); ++i) {
            pmap[sumdig(nums[i])].push(i);
        } 

        for (auto& [key, value] : pmap) {
            if (value.size() > 1) {
                int first = value.top(); value.pop();
                int second = value.top(); value.pop();

                int sum = first + second;
                if (sum > max) max = sum;
            }
        }
        return (max == 0 ? -1 : max);
    }
};

int main(int argc, char** argv) {

    vector<int> v {18,43,36,13,7};

    return 0;
}

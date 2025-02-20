#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <utility>
#include <cmath>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;
using std::queue;
using std::priority_queue;
typedef long long dword;

template<typename T, typename U>
using pmap = unordered_map<T,U>;

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

class Solution {
public:
    string backtrack(vector<string>& nums, string& curr, pmap<string, bool>& mmap) {
        if (curr.size() == nums.size()) {
           if (mmap[curr] == false) {
               return curr;
           }
           return "";
        }

        curr.push_back(std::to_string(1)[0]); 
        if (backtrack(nums, curr, mmap) != "") return curr;
        curr.pop_back();

        curr.push_back(std::to_string(0)[0]);
        if (backtrack(nums, curr, mmap) != "") return curr;
        curr.pop_back();

        return "";
    }
    string findDifferentBinaryString(vector<string>& nums) {
        pmap<string, bool> umap;
        string curr;
        for (const auto& item : nums) {
            umap[item] = true;
        }
        return backtrack(nums, curr, umap);
    }
};

int main(int argc, char** argv) {

    Solution s;
    vector<string> in = {"10", "11"};
    string ret =  s.findDifferentBinaryString(in);

    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <ranges>
using std::cout;
using std::string;
using std::vector;
using std::endl;
using std::unordered_map;

template <typename T, typename U>
using umap =  unordered_map<T,U>; 

using namespace std::ranges::views;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        umap<string, vector<string>> m;

        for (const auto& i : std::ranges::views::iota(0,(int)strs.size())) {
            string s = strs[i];
            std::sort(s.begin(), s.end());

            m[s].push_back(strs[i]);
        }

        vector<vector<string>> ret;
        for (const auto& [key, value] : m) {
           ret.push_back(value); 
        }
        return ret;
    }
};

int main(int argc, char** argv) {

    return 0;
}

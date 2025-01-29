#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <ranges>
using std::cout;
using std::string;
using std::vector;
using std::endl;

template<typename T, typename U>
using umap = std::unordered_map<T,U>;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        umap<int, size_t> m;
        for (const auto& i : std::ranges::views::iota(0,(int)nums.size())) {
            ++m[nums[i]];
        }
        vector<std::pair<int,size_t>> p;

        for (const auto& [key, value] : m) {
            p.emplace_back(std::make_tuple(key, value));
        }
        std::sort(p.begin(), p.end(), [](const auto& x, const auto& y) {return x.second > y.second;});

        vector<int> ret;
        for (int i=0; i<k; ++i) {
            ret.push_back(p[i].second);
        }
        return ret;
    }
};

int main(int argc, char** argv) {


    return 0;
}

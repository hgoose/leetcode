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
    pmap<char,int> umap;
    int backtrack() {
        int res{};
        for (const auto& [key,val] : umap) {
            if (umap[key] > 0) {
                --umap[key];
                ++res;
                res += backtrack();
                ++umap[key];
            }
        }
        return res;
    }
    int numTilePossibilities(string tiles) {
        for (const char& c : tiles) {
            ++umap[c];
        }
        return backtrack();
    }
};

int main(int argc, char** argv) {

    return 0;
}

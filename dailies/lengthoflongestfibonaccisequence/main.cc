#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <utility>
#include <cmath>
#include <bitset>
#include <array>
#include <map>
#include <limits>
#include <tuple>
#include <unordered_set>
using std::tuple;
using std::map;
using std::array;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;
using std::queue;
using std::priority_queue;
using std::bitset;

typedef long long dword;


template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

template<typename T>
using lims = std::numeric_limits<T>;


template<typename T, typename U>
using pmap = unordered_map<T,U>;
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        std::unordered_set<int> umap(arr.begin(), arr.end());

        int global_max{0};
        for (int i=0; i<(int)arr.size()-1; ++i) {
            for (int j=i+1; j<(int)arr.size(); ++j) {
                int prev = arr[j];
                int curr = arr[i] + arr[j];
                int lmax = 2;
                while (umap.find(curr) != umap.end()) {
                    ++lmax;
                    int tmp = curr;
                    curr+=prev;
                    prev=tmp;
                    if (lmax > global_max) global_max = lmax;
                }
            }
        }
        return global_max;
    }
};

int main(int argc, char** argv) {

    vector<int> v{1,2,3,4,5,6,7,8};
    Solution s;
    // cout << s.checkFib(v,3);
    cout << s.lenLongestFibSubseq(v);


    return 0;
}

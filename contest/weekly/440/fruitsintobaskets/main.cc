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
#include <climits> // INT_MAX, INT_MIN, ...
#include <tuple>
#include <unordered_set>
#include <algorithm>
#include <stack>
using std::stack;
using std::unordered_set;
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


template<typename T>
using pset = unordered_set<T>;

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

template<typename T>
using lims = std::numeric_limits<T>;

template<typename T, typename U>
using pmap = unordered_map<T,U>;
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        pmap<int, int> umap; 
        for (int i=0; i<(int)fruits.size(); ++i) {
            umap[i] = -1;
        }

        int n = fruits.size();
        int last_placed{}, unplaced{};
        for (int i=0; i<n; ++i) {
            bool placed = false, less = false;
            int j{};
            if (i > 0 &&  fruits[i] >= fruits[i-1]) {
                j = last_placed+1;
            } else if (i > 0 && fruits[i] < fruits[i-1]) {
                n = last_placed == 0 ? n : last_placed;
                less = true;
            }
            for (; j<n; ++j) {
                if (baskets[j] >= fruits[i] && (umap[j] == -1 || umap[j] == i)) {
                    baskets[j]-=fruits[i];
                    placed = true;
                    umap[j] = i;
                    last_placed = j;
                    break;
                }
            }
            if (!placed && less) {
                bool letmeplace{false};
                for (int k=last_placed+1; k<(int)fruits.size(); ++k) {
                    if (baskets[k] >= fruits[i] && (umap[k] == -1 || umap[k] == i)) {
                        baskets[k]-=fruits[i];
                        letmeplace = true;
                        umap[k] = i;
                        last_placed = k;
                        break;
                    }
                }
                placed = letmeplace;
            }
            if (!placed)  {
                ++unplaced;
            }
            n = fruits.size();
        }
        return unplaced;

    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> f{28,68,18}, b{36,85,94};

    cout << s.numOfUnplacedFruits(f,b);

    return 0;
}

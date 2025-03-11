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
#define say(x) cout << x << endl;
#define list(x) for(int i=0; i<(int)x.size(); ++i) cout << x[i] << " ";

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
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        pmap<int,int> umap;        
        for (int i=0; i<(int)position.size(); ++i) {
            umap[position[i]] = speed[i];
        }
        std::sort(position.begin(), position.end());
        for (int i=0; i<(int)position.size(); ++i) {
            speed[i] = umap[position[i]];
        }

        vector<double> stack(position.size());

        int stack_idx{0};
        int stack_size{};
        for (int i=position.size()-1; i>=0; --i) {
            stack[stack_idx] = (target-position[i]) / static_cast<double>(speed[i]);
            ++stack_idx;
            ++stack_size;

            if (stack_size >= 2 && stack[stack_idx-1] <= stack[stack_idx-2]) {
                stack.pop_back();
                --stack_size;
                --stack_idx;
            }
        }
        return stack.size();
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> position{6,8}, speed{3,2};

    cout << s.carFleet(10, position, speed);


    return 0;
}

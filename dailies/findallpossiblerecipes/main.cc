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
#include <numeric> // std::accumulate
#include <climits> // INT_MAX, INT_MIN, ...
#include <tuple>
#include <unordered_set>
#include <algorithm>
#include <stack>
using std::pair;
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
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> res;
        pmap<string, bool> can; for (const auto& e : supplies) can[e] = true;
        pmap<string, int> umap;

        for (int i=0; i<(int)recipes.size(); ++i) {
            umap[recipes[i]] = i;
        }

        for (const auto& e : recipes) {
            if (dfs(e, ingredients, supplies, can, umap)) {
                res.push_back(e);
            }
        }
        return res;

    }
private:
    bool dfs(const string& recipe, vector<vector<string>>& ing, vector<string>& sup, pmap<string, bool>& s, pmap<string, int>& m) {
        if (s.find(recipe) != s.end()) {
            return s[recipe];
        }
        if (m.find(recipe) == m.end()) return false;

        s[recipe] = false;

        for (const auto& e : ing[m[recipe]]) {
            if (!dfs(e, ing, sup, s, m)) {
                return false;
            }
        }
        s[recipe] = true;
        return true;
    }
};

int main(int argc, char** argv) {

    return 0;
}

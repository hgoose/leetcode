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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef TreeNode* ts;
class Solution {
public:
    ts lowestCommonAncestor(ts root, ts p, ts q) {
        ts lowest = nullptr;
        _solve(root,p,q, lowest);
        return lowest;
    }
private:
    void _solve(ts root, ts p, ts q, ts& lowest) {
        if (!root) return; 

        bool locate_p = locate(root,p);
        bool locate_q = locate(root,q);

        if (locate_p && locate_q) lowest = root;

        _solve(root->left, p,q, lowest);
        _solve(root->right, p,q, lowest);

    }
    bool locate(ts root, ts p) {
        if (!root || !p) return false;

        if (root == p) return true;

        if (p->val < root->val) return locate(root->left, p);
        else return locate(root->right, p);
    }
};



int main(int argc, char** argv) {




    return 0;
}

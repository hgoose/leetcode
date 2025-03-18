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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int max = 0;
        depth(root, max);
        return max;
    }
// private:
    int depth(TreeNode* p, int& max) {
        if (!p) return 0;

        int ld = depth(p->left, max);
        int rd = depth(p->right, max);

        max = std::max(max, ld + rd);
        cout << "Max: " << max << endl;

        return 1 + std::max(ld, rd);
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode;
    root->left = new TreeNode;
    root->left->left = new TreeNode;
    root->left->right = new TreeNode;
    root->right = new TreeNode;
    root->right->left = new TreeNode;

    Solution s;
    int max = 0;
    cout << s.depth(root, max) << endl;
    cout << max << endl;

    return 0;
}

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

// ts (TreeNode*)
typedef TreeNode* ts;
class Solution {
public:
    bool isSubtree(ts root, ts subRoot) {
        if (!root) return false;

        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);

        if (left || right) return true;

        bool check = _solve(root, subRoot);

        if (check) return true;
        return false;
    }
private:
    bool _solve(ts p, ts q) {
        if (!p && !q) return true;
        if (!p || !q) return false;

        bool curr = false;
        if (p->val == q->val)  {
            curr = true;
        }

        bool left = _solve(p->left, q->left);
        bool right = _solve(p->right, q->right);

        return (curr && left && right);
    }
};

int main(int argc, char** argv) {
    ts root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);

    ts root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    root2->left->left = new TreeNode(4);
    root2->right->left = new TreeNode(5);


    Solution s;
    cout << std::boolalpha << s.isSubtree(root, root2);


    return 0;
}

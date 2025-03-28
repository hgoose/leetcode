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

typedef TreeNode node;
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return _solve(root, INT_MIN * 2ll, INT_MAX * 2ll);
    }
private:
    bool _solve(node* root, long min, long max) {
        if (!root) return true;

        bool left = _solve(root->left, min, root->val);
        bool right = _solve(root->right, root->val ,max);

        bool here = false;
        if (root->val > min && root->val < max) {
            here = true;
        }

        return left && right && here;
    }
};

int main(int argc, char** argv) {

    node* root = new node(5);
    root->left = new node(4);
    root->right = new node(6);
    root->right->left = new node(3);
    root->right->right = new node(7);

    Solution s;

    cout << std::boolalpha << s.isValidBST(root);


    return 0;
}

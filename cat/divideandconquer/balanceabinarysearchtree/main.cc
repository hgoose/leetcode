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

template<typename T, typename U>
using pmap = unordered_map<T,U>;

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

template<typename T>
using lims = std::numeric_limits<T>;

// Definition for a binary tree node.
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
        TreeNode* balanceBST(TreeNode* root) {
            vector<int> vals = inorder(root);
            return _dc(nullptr, vals, 0, vals.size()-1);
        }
    private:
        TreeNode* _dc(TreeNode* p, vector<int>& vals, int l, int r) {
            if (l > r) return nullptr;
            int mid = (l + r) / 2;

            p = new TreeNode(vals[mid]);
            p->left = _dc(p->left,vals, l, mid-1);
            p->right = _dc(p->right,vals, mid+1, r);
            return p;
        }
        void _inorder(TreeNode* root, vector<int>& res) {
            if (!root) return;
            _inorder(root->left, res);
            res.push_back(root->val);
            _inorder(root->right, res);
        }
        vector<int> inorder(TreeNode* root) {
            vector<int> res;
            _inorder(root, res);
            return res;
        }
};

int main(int argc, char** argv) {

    return 0;
}

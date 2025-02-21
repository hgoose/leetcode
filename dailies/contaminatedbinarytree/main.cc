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

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindElements {
public:
    TreeNode* m_root;
    TreeNode* _fixTree(TreeNode* p) {
        if (!p) return nullptr;
        int homeVal = p->val;
        if (p->left)  {
            p->left->val = homeVal * 2 + 1;
            p->left = _fixTree(p->left);
        }
        if (p->right) {
            p->right->val = homeVal*2 + 2;
            p->right = _fixTree(p->right);
        }
        return p;
    }

    TreeNode* fixTree(TreeNode* root) {
        if (!root) return nullptr;
        root->val = 0;
        return _fixTree(root);
    }

    bool treeWalk(TreeNode* root, const int& target) {
        if (!root) return false;
        if (root->val == target) return true;
        if (treeWalk(root->left, target)) return true;;
        if (treeWalk(root->right, target)) return true;;
        return false;
    }

    FindElements(TreeNode* root) {
        m_root = fixTree(root);
    }
    
    bool find(int target) {
        return treeWalk(m_root, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

int main(int argc, char** argv) {

    TreeNode* root = new TreeNode(-1);
    root->left = new TreeNode(-1);
    root->right = new TreeNode(-1);
    root->left->left = new TreeNode(-1);
    root->left->right = new TreeNode(-1);

    FindElements* fe = new FindElements{root};

    cout << std::boolalpha << fe->find(0) << endl;
    cout << std::boolalpha << fe->find(1) << endl;
    cout << std::boolalpha << fe->find(2) << endl;
    cout << std::boolalpha << fe->find(3) << endl;
    cout << std::boolalpha << fe->find(4) << endl;
    cout << std::boolalpha << fe->find(5) << endl;




    return 0;
}

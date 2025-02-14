#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::queue;
using std::unordered_map;
using std::priority_queue;
typedef long long dword;

template<typename T, typename U>
using pmap = unordered_map<T,U>;

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

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
    static void swapNode(TreeNode*& u, TreeNode*& v) {
        v = std::exchange(u,v);
    }
    TreeNode* r_invertTree(TreeNode* root) {
        if (!root) return nullptr;

        r_invertTree(root->left);
        r_invertTree(root->right);

        swapNode(root->left, root->right);
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front(); q.pop();
            if (!curr) continue;

            TreeNode*& left = curr->left, *&right = curr->right;

            swapNode(left, right);

            if (left) q.push(left);
            if (right) q.push(right);
        }
        return root;
    }
};
int main(int argc, char** argv) {







    return 0;
}

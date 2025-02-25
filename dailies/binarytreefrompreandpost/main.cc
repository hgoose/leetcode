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

class Solution {
public:
    pmap<int, int> umap;
    int idx{1};
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if (!preorder.size()) return nullptr;
        for (int i=0; i<(int)postorder.size(); ++i) {
            umap[postorder[i]] = i;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        root = _construct(root, preorder, root->val);
        return root;
    }

private:
    TreeNode* _construct(TreeNode* p, vector<int>& preorder, int prevVal) {
        if (idx >= preorder.size()) return p;
        if (!p) {
            if (umap[preorder[idx]] < umap[prevVal])  {
                TreeNode* np = new TreeNode(preorder[idx++]);
                np->left = _construct(np->left, preorder, np->val); 
                np->right = _construct(np->right, preorder, np->val); 
                return np;
            }
            return nullptr;
        }
        p->left = _construct(p->left, preorder, p->val);
        p->right = _construct(p->right, preorder, p->val);
        return p;

    }

};

int main(int argc, char** argv) {
    vector<int> pre{1,2,4,5,3,6,7};
    vector<int> post{4,5,2,6,7,3,1};

    return 0;
}

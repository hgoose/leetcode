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
    int currIdx{1};
    int buildInt(const string& trav, int& idx){ 
        int num{}; 
        while ((idx < trav.size()) && trav[idx] != '-') { 
            num = num * 10 + (int)(trav[idx++]-48); 
        } return num; 
    }

    std::tuple<int, int,int> parseString(const string& trav, int idx) {
        int depth{};
        while (trav[idx] == '-')  {
            ++depth, ++idx;
        }
        return {buildInt(trav,idx), depth, idx};
    }

    TreeNode* _preorder(TreeNode* p, const string& traversal, int idx, int currDepth, int last) {
        if (currIdx >= last) return p;
        if (!p) {
            auto [nodeVal, depth, newIdx] = parseString(traversal, currIdx);
            if (depth == currDepth) {
                currIdx = newIdx;
                // idx = newIdx;
                TreeNode* np = new TreeNode(nodeVal);
                np->left = _preorder(np->left, traversal, currIdx, currDepth+1, last);
                np->right = _preorder(np->right, traversal, currIdx, currDepth+1, last);
                return np;
            }
            return nullptr;
        }
        p->left = _preorder(p->left, traversal, currIdx, currDepth + 1, last);
        p->right = _preorder(p->right, traversal, currIdx, currDepth + 1, last);
        return p;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        int idx = 0;
        TreeNode* root = new TreeNode(buildInt(traversal, idx)); 
        currIdx = idx;
        root = _preorder(root, traversal,idx,0,traversal.size());
        return root;
    }
};

int main(int argc, char** argv) {
    Solution s;
    s.recoverFromPreorder("10-7--8");


    return 0;
}

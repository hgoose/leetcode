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

typedef vector<vector<int>> VII;
typedef vector<int> VI;
#define PB push_back


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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pmap<int, int> ind;
        for (int i=0;i < (int)inorder.size(); ++i) {
            ind[inorder[i]] = i;
        } 
    
        TreeNode* root = _construct(nullptr, preorder, inorder, 0,preorder.size()-1,0, inorder.size()-1, ind);
        return root;
    }
private:
    TreeNode* _construct(TreeNode* p, vector<int>& preorder, vector<int>& inorder, int start_pre, int stop_pre, int start_in, int stop_in, pmap<int,int>& ind) {
        if (start_pre > stop_pre || start_in > stop_in) return nullptr;
        if (start_pre > inorder.size()-1) return nullptr;

        p = new TreeNode(preorder[start_pre]);
        int in_idx = ind[preorder[start_pre]];
        int n = in_idx - start_in;
        p->left = _construct(p->left, preorder, inorder, start_pre+1, start_pre + n, start_in, in_idx-1, ind);
        p->right = _construct(p->right, preorder, inorder, start_pre + n + 1, stop_pre,in_idx+1 ,stop_in, ind);

        return p;
    }
};

int main(int argc, char** argv) {

    return 0;
}

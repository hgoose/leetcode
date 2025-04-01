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


typedef vector<vector<int>> VII;
typedef vector<int> VI;
struct TreeNode;
struct ListNode;
typedef ListNode ln;
typedef TreeNode tn;
#define PB push_back

class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

class Solution {
template<typename T, typename U>
using pmap = unordered_map<T,U>;
public:
    Node* copyRandomList(Node* head) {
        vector<int> list;
        pmap<Node*, int> umap;
        vector<Node*> copy_list;

        Node* curr = head;
        Node* copy_head = nullptr;
        bool first = true;
        int i=0;
        Node* prev = copy_head;
        while (curr) {
            umap[curr] = i++;
            Node* copy = new Node(head->val);

            if (prev) prev->next = copy;

            if (first) { copy_head = copy; first = false; }

            copy->val = curr->val;
            copy_list.push_back(copy);
            curr = curr->next;
            prev = copy;
        }

        curr = head;
        while (curr) {
            list.push_back(curr->random ? umap[curr->random] : -1);
            curr = curr->next;
        }

        i=0;
        curr = copy_head;
        while (curr) {
            curr->random = list[i] != -1 ? copy_list[i++] : nullptr; 
            curr = curr->next;
        }

        return copy_head;
    }
};

int main(int argc, char** argv) {

    return 0;
}

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
struct TreeNode;
struct ListNode;
typedef ListNode ln;
typedef TreeNode tn;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

template <typename T=ListNode*>
class Solution {
public:
    // 0 -> n -> 1 -> n-2 -> 2 -> n-3 -> ... 
    void reorderList(T head) {
        stack<pair<T,int>> st;
        T left = head, tmp = head;
        int i = 0;
        while (tmp) { 
            st.push({tmp, i++});
            tmp = tmp->next;
        }

        pair<T,int> right = st.top();
        st.pop();
        i=0;
        while (i < right.second) {
            T tmp = left->next;
            left->next = right.first;
            right.first->next = tmp;
            if (left->next && left->next->next) left=left->next->next;
            else break;
            if (st.size()) {
                right = st.top(), st.pop();
            }
            ++i;
        }

        left->next = nullptr;
    }
};

int main(int argc, char** argv) {

    ln* head = new ln(1);
    head->next = new ln(2);
    head->next->next = new ln(3);
    head->next->next->next = new ln(4);
    Solution s;
    s.reorderList(head);

    ln* curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }




    return 0;
}

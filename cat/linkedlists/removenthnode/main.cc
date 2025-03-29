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
struct TreeNode;
typedef TreeNode tn;
#define PB push_back

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct ListNode;
typedef ListNode ln;
#define np nullptr

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next) {
            if (n==1) {
                delete head;
                return nullptr;
            } else return head;
        } 

        stack<ln*> st;        
        ln* curr = head;
        while (curr) {
            st.push(curr);
            curr=curr->next;
        }

        int i=1;
        ln* the = np, *after=np, *before=np;
        while (i != n) {
            after = st.top(), st.pop();
            ++i;
        }
        the = st.top();
        st.pop();
        if (st.size()) {
            before = st.top(), st.pop();
        }

        if (after && before) {
            before->next = after;
        } else if (!after && before) {
            before->next = np;
        } else if (!before && after) {
            head = after;
        }
        delete the;

        return head;
    }
};

int main(int argc, char** argv) {

    return 0;
}

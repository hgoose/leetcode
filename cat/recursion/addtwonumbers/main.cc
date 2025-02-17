#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <utility>
#include <cmath>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;
using std::queue;
using std::priority_queue;
typedef long long dword;

template<typename T, typename U>
using pmap = unordered_map<T,U>;

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry=0) {
        if (!l1 && !l2 && carry == 0) return nullptr;

        int sum = carry;
        if (l1) sum+=l1->val; 
        if (l2) sum+=l2->val; 

        ListNode* newnode = new ListNode(sum % 10);
        newnode->next = addTwoNumbers(l1? l1->next : nullptr,l2? l2->next : nullptr,sum/10);
        return newnode;
    }
};

int main(int argc, char** argv) {

    return 0;
}

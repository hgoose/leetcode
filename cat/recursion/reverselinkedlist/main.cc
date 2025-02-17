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

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};
int main(int argc, char** argv) {

    ListNode* head = new ListNode{1};
    ListNode* n1 = new ListNode{2};
    ListNode* n2 = new ListNode{3};
    ListNode* n3 = new ListNode{4};
    ListNode* n4 = new ListNode{5};

    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;


    Solution s;
    head = s.reverseList(head);

    while (head) {
        cout << head->val << endl;
        head = head->next;
    }




    return 0;
}

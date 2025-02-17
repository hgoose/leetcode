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
    void r_mergeTwoLists(ListNode* curr, ListNode* list1, ListNode* list2) {
        if (!list1 && !list2) return;

        if (list1 && !list2) {
            curr->next = list1;
            r_mergeTwoLists(curr->next, list1->next, list2);
        } else if (!list1 && list2) {
            curr->next = list2;
            r_mergeTwoLists(curr->next, list1, list2->next);
        } else {
            if (list1->val <= list2->val) {
                curr->next = list1;
                r_mergeTwoLists(curr->next, list1->next, list2);
            } else if (list2->val < list1->val) {
                curr->next = list2;
                r_mergeTwoLists(curr->next, list1, list2->next);
            } 
        } 
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newhead = new ListNode{}, *curr = newhead;
        r_mergeTwoLists(curr, list1, list2);
        return newhead->next;
    }
};    
    // ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //     ListNode* newhead = new ListNode{};
    //     ListNode* curr = newhead;
    //     while (list1 && list2) {
    //         if (list1->val <= list2->val) {
    //             curr->next = list1;
    //             list1=list1->next;
    //         } else {
    //             curr->next = list2;
    //             list2=list2->next;
    //         }
    //         curr=curr->next;
    //     }
    //     if (list1) {
    //        while (list1) {
    //            curr->next = list1;
    //            list1=list1->next;
    //            curr=curr->next;
    //        } 
    //     } else if (list2) {
    //         while (list2) {
    //             curr->next = list2;
    //             list2=list2->next;
    //             curr=curr->next;
    //         }
    //     }
    //     return newhead->next;
    // }
// };
//
int main(int argc, char** argv) {

    return 0;
}
